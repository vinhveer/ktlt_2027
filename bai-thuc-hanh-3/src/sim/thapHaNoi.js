// Tháp Hà Nội theo tư tưởng: bài k đĩa = 1 cục (k - 1 đĩa trên) + 1 đĩa đáy, và chỉ làm 3 bước:
//   1. cục: nguồn → trung gian   2. đĩa đáy: nguồn → đích   3. cục: trung gian → đích
// Muốn biết cục chuyển thế nào thì "mở" nó ra: lại là một bài nhỏ hơn với vai trò cọc khác.

export const SO_DIA_MAX = 5

const COC = ['A', 'B', 'C']
const cocConLai = (a, b) => COC.find((p) => p !== a && p !== b)

// Ba bước của một bài: [{ loai: 'cuc', soDia, tu, sang } | { loai: 'day', dia, tu, sang }]
export function cacBuoc(L) {
  return [
    { loai: 'cuc', soDia: L.k - 1, tu: L.nguon, sang: L.trungGian },
    { loai: 'day', dia: L.k, tu: L.nguon, sang: L.dich },
    { loai: 'cuc', soDia: L.k - 1, tu: L.trungGian, sang: L.dich },
  ]
}

// Bỏ qua bước chuyển cục rỗng (bài 1 đĩa không có cục)
function boQuaRong(L) {
  while (L.step < 3) {
    const b = cacBuoc(L)[L.step]
    if (b.loai !== 'cuc' || b.soDia > 0) break
    L.step++
  }
}

function chuyen(pos, tuDia, denDia, sang) {
  const p = { ...pos }
  for (let d = tuDia; d <= denDia; d++) p[d] = sang
  return p
}

// Trạng thái: { levels, pos }
//   levels: các tầng đang mở, tầng cuối là bài đang xét
//     { k, nguon, dich, trungGian, step: số bước đã làm (0..3), posKhiMo: vị trí đĩa lúc mở tầng này }
//   pos: { đĩa: cọc }
export function khoiTao(n) {
  const pos = {}
  for (let d = 1; d <= n; d++) pos[d] = 'A'
  const goc = { k: n, nguon: 'A', dich: 'C', trungGian: 'B', step: 0 }
  boQuaRong(goc)
  return { levels: [goc], pos }
}

export function daXong(s) {
  return s.levels.length === 1 && s.levels[0].step === 3
}

// Làm bước tiếp theo của bài đang xét (cục thì chuyển nguyên khối)
export function tiep(s) {
  if (daXong(s)) return s
  const levels = s.levels.map((l) => ({ ...l }))
  const L = levels[levels.length - 1]
  const b = cacBuoc(L)[L.step]
  const pos = b.loai === 'cuc' ? chuyen(s.pos, 1, b.soDia, b.sang) : chuyen(s.pos, b.dia, b.dia, b.sang)
  L.step++
  boQuaRong(L)
  // Bài con xong nghĩa là cục của tầng trên đã chuyển xong → quay lên
  while (levels.length > 1 && levels[levels.length - 1].step === 3) {
    levels.pop()
    levels[levels.length - 1].step++
  }
  return { levels, pos }
}

// Có mở được không: bước sắp làm là chuyển một cục từ 2 đĩa trở lên
export function coTheMo(s) {
  if (daXong(s)) return false
  const L = s.levels[s.levels.length - 1]
  const b = cacBuoc(L)[L.step]
  return b.loai === 'cuc' && b.soDia >= 2
}

export function mo(s) {
  if (!coTheMo(s)) return s
  const L = s.levels[s.levels.length - 1]
  const b = cacBuoc(L)[L.step]
  const con = { k: b.soDia, nguon: b.tu, dich: b.sang, trungGian: cocConLai(b.tu, b.sang), step: 0, posKhiMo: s.pos }
  return { levels: [...s.levels, con], pos: s.pos }
}

// Đóng các tầng sâu hơn tầng i, đĩa về lại như lúc mở
export function dong(s, i) {
  if (i >= s.levels.length - 1) return s
  return { levels: s.levels.slice(0, i + 1), pos: s.levels[i + 1].posKhiMo }
}

// Toàn bộ lời giải: [đĩa, từ, sang]
export function danhSachNuoc(n) {
  const kq = []
  function rec(k, nguon, dich, trungGian) {
    if (k === 0) return
    rec(k - 1, nguon, trungGian, dich)
    kq.push([k, nguon, dich])
    rec(k - 1, trungGian, dich, nguon)
  }
  rec(n, 'A', 'C', 'B')
  return kq
}

export function viTriSau(n, nuoc, soNuoc) {
  const pos = {}
  for (let d = 1; d <= n; d++) pos[d] = 'A'
  nuoc.slice(0, soNuoc).forEach(([d, , sang]) => { pos[d] = sang })
  return pos
}
