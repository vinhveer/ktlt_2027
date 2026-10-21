const PX = { A: 115, B: 340, C: 565 }
const DAY = 158 // mặt đế
const CAO = 16 // độ dày mỗi đĩa
const rong = (d) => 30 + 28 * d

const TEN_VAI_TRO = { nguon: 'nguồn', dich: 'đích', trungGian: 'trung gian' }
const RONG_THE = { nguon: 66, dich: 54, trungGian: 96 }

// Vẽ 3 cọc + các đĩa.
// pos: { đĩa: cọc }
// vaiTro: { nguon, dich, trungGian } → 3 thẻ vai trò, trượt sang cọc mới khi vai trò đổi
// k: bài đang xét có k đĩa → đĩa 1..k-1 là "cục", đĩa k là đĩa đáy, đĩa lớn hơn k làm mờ
//    (không truyền k thì mọi đĩa như nhau)
// moDuoc / onMo: bấm vào khung cục để mở
// thoiGian: thời gian hoạt cảnh (ms)
export default function HanoiBoard({ soDia, pos, vaiTro, k, moDuoc, onMo, thoiGian = 500 }) {
  // Xếp đĩa lớn ở dưới, nhỏ ở trên
  const xy = {}
  const coc = { A: [], B: [], C: [] }
  for (let d = soDia; d >= 1; d--) coc[pos[d]].push(d)
  for (const p in coc) coc[p].forEach((d, i) => { xy[d] = { x: PX[p] - rong(d) / 2, y: DAY - CAO * (i + 1) } })

  const loai = (d) => (!k ? 'thuong' : d < k ? 'cuc' : d === k ? 'day' : 'ngoai')

  // Khung bao quanh cục (từ 2 đĩa trở lên); cục luôn nằm gọn trên đỉnh một cọc
  const m = k ? k - 1 : 0
  const khung = m >= 2
    ? { x: PX[pos[1]] - rong(m) / 2 - 7, y: xy[1].y - 5, w: rong(m) + 14, h: m * CAO + 5 }
    : null

  const dias = []
  for (let d = soDia; d >= 1; d--) dias.push(d)

  return (
    <svg width="100%" viewBox="0 0 680 170" role="img" className="hanoi" style={{ '--dur': `${thoiGian}ms` }}>
      <title>Ba cọc A, B, C và các đĩa</title>
      <rect className="base" x="20" y={DAY} width="640" height="4" rx="1" />
      {Object.entries(PX).map(([p, x]) => (
        <g key={p}>
          <text className="name" x={x} y="60" textAnchor="middle">{p}</text>
          <rect className="rod" x={x - 2} y="70" width="4" height={DAY - 70} rx="1" />
        </g>
      ))}

      {vaiTro && Object.entries(vaiTro).map(([vt, p]) => (
        <g key={vt} className={'tag tag-' + vt} style={{ transform: `translate(${PX[p]}px, 0px)` }}>
          <rect x={-RONG_THE[vt] / 2} y="6" width={RONG_THE[vt]} height="24" rx="12" />
          <text y="23" textAnchor="middle">{TEN_VAI_TRO[vt]}</text>
        </g>
      ))}

      {dias.map((d) => (
        <g key={d} className={'disk ' + loai(d)} style={{ transform: `translate(${xy[d].x}px, ${xy[d].y}px)` }}>
          <rect width={rong(d)} height={CAO} rx="4" />
          <text x={rong(d) / 2} y="12" textAnchor="middle">{d}</text>
        </g>
      ))}

      {khung && (
        <g
          className={'khung' + (moDuoc ? ' mo-duoc' : '')}
          style={{ transform: `translate(${khung.x}px, ${khung.y}px)` }}
          onClick={moDuoc ? onMo : undefined}
        >
          {moDuoc && <title>Mở cục</title>}
          <rect width={khung.w} height={khung.h} rx="8" />
        </g>
      )}
    </svg>
  )
}
