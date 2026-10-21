import { IconCaretUpFilled } from '@tabler/icons-react'

// Vẽ mảng thành các ô, có con trỏ i.
// ghost: 'end' thêm ô ảo ở vị trí n, 'start' thêm ô ảo ở vị trí -1 (điểm dừng của đệ quy)
// cellClass(i): class thêm cho ô thứ i; below(i): chữ hiển thị dưới ô thứ i
// large: ô to, trải hết chiều ngang
export default function ArrayView({ a, focus, ghost, cellClass, below, large }) {
  const slots = a.map((v, i) => ({ i, v }))
  if (ghost === 'start') slots.unshift({ i: -1, ghost: true })
  if (ghost === 'end') slots.push({ i: a.length, ghost: true })

  return (
    <div className={'arr-wrap' + (large ? ' lg' : '')}>
      <div className="arr">
        {slots.map((s) => {
          let cls = 'cell'
          if (s.ghost) cls += ' ghost'
          else if (cellClass) cls += ' ' + cellClass(s.i)
          if (focus === s.i) cls += ' cur'
          return (
            <div key={s.i} className="slot">
              <div className="idx">{s.i}</div>
              <div className={cls}>{s.ghost ? '' : s.v}</div>
              <div className="ptr">
                {focus === s.i && (
                  <>
                    <IconCaretUpFilled className="ptr-icon" />
                    <span>i</span>
                  </>
                )}
              </div>
              {below && <div className="below">{below(s.i)}</div>}
            </div>
          )
        })}
      </div>
    </div>
  )
}
