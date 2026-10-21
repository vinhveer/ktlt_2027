// Tư tưởng của tongChinhPhuong(a, i, n): đi từ i = 0 tới cuối mảng,
// rồi quay về cộng dồn: tong(i) = phanTu + tong(i + 1), với tong(n) = 0

function laChinhPhuong(x) {
  if (x < 0) return false
  const k = Math.floor(Math.sqrt(x))
  return k * k === x
}

// Mỗi bước: msg (ghi chú ngắn), vis { i, loai: {i: 'ok' | 'no'}, tong: {i: tổng từ i tới cuối} }
export function taoCacBuoc(a) {
  const n = a.length
  const ev = []
  const loai = {}
  const tong = {}
  const push = (i, msg) => ev.push({ msg, vis: { i, loai: { ...loai }, tong: { ...tong } } })

  // Đi: xét từng phần tử
  for (let i = 0; i < n; i++) {
    const cp = laChinhPhuong(a[i])
    loai[i] = cp ? 'ok' : 'no'
    push(i, cp ? `${a[i]} là số chính phương` : `${a[i]} không phải`)
  }

  // Điểm dừng
  tong[n] = 0
  push(n, 'i = n → 0')

  // Quay về: cộng dồn từ cuối lên
  for (let i = n - 1; i >= 0; i--) {
    const phanTu = loai[i] === 'ok' ? a[i] : 0
    tong[i] = phanTu + tong[i + 1]
    push(i, `${phanTu} + ${tong[i + 1]} = ${tong[i]}`)
  }

  push(null, `Tổng = ${tong[0]}`)
  return ev
}
