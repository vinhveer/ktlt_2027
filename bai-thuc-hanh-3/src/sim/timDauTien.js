// Tư tưởng của 4 cách đệ quy tìm vị trí đầu tiên của x: đi tới điểm dừng rồi quay về.
// Mỗi bước: msg (ghi chú ngắn), vis { i, cmp: {i: a[i] == x?}, tra: {i: giá trị lời gọi tại i trả về}, kq }

function khoiTao() {
  const ev = []
  const vis = { i: null, cmp: {}, tra: {}, kq: null }
  const push = (i, msg) => {
    vis.i = i
    ev.push({ msg, vis: { ...vis, cmp: { ...vis.cmp }, tra: { ...vis.tra } } })
  }
  const ketThuc = (r) => {
    vis.kq = r
    push(null, `Kết quả = ${r}`)
    return ev
  }
  return { vis, push, ketThuc }
}

const soSanh = (a, i, x) => `${a[i]} ${a[i] === x ? '=' : '≠'} ${x}`

// Cách 1: đi xuôi, so sánh trước — gặp là dừng, rồi chuyển kết quả lên
function cach1(a, x) {
  const n = a.length
  const { vis, push, ketThuc } = khoiTao()
  let i = 0
  let r = -1
  for (; i < n; i++) {
    vis.cmp[i] = a[i] === x
    if (a[i] === x) {
      r = i
      vis.tra[i] = i
      push(i, `${soSanh(a, i, x)} → ${i}`)
      break
    }
    push(i, soSanh(a, i, x))
  }
  if (i === n) {
    vis.tra[n] = -1
    push(n, 'i = n → -1')
  }
  for (let j = i - 1; j >= 0; j--) {
    vis.tra[j] = r
    push(j, `→ ${r}`)
  }
  return ketThuc(r)
}

// Cách 2: đi xuôi tới cuối (chưa so sánh), quay về mới so sánh
function cach2(a, x) {
  const n = a.length
  const { vis, push, ketThuc } = khoiTao()
  for (let i = 0; i < n; i++) push(i, `i = ${i}`)
  vis.tra[n] = -1
  push(n, 'i = n → -1')
  for (let i = n - 1; i >= 0; i--) {
    const kq = vis.tra[i + 1]
    vis.cmp[i] = a[i] === x
    vis.tra[i] = a[i] === x ? i : kq
    push(i, `${soSanh(a, i, x)} → ${vis.tra[i]}`)
  }
  return ketThuc(vis.tra[0])
}

// Cách 3: đi ngược từ cuối, so sánh trước (kq), quay về ưu tiên kết quả phía trước
function cach3(a, x) {
  const n = a.length
  const { vis, push, ketThuc } = khoiTao()
  const kq = {}
  for (let i = n - 1; i >= 0; i--) {
    vis.cmp[i] = a[i] === x
    kq[i] = a[i] === x ? i : -1
    push(i, `${soSanh(a, i, x)}, kq = ${kq[i]}`)
  }
  vis.tra[-1] = -1
  push(-1, 'i = -1 → -1')
  for (let i = 0; i < n; i++) {
    const truoc = vis.tra[i - 1]
    vis.tra[i] = truoc !== -1 ? truoc : kq[i]
    push(i, `truoc = ${truoc} → ${vis.tra[i]}`)
  }
  return ketThuc(vis.tra[n - 1])
}

// Cách 4: đi ngược tới đầu (chưa so sánh), quay về: phía trước đã thấy thì giữ, chưa thấy mới so sánh
function cach4(a, x) {
  const n = a.length
  const { vis, push, ketThuc } = khoiTao()
  for (let i = n - 1; i >= 0; i--) push(i, `i = ${i}`)
  vis.tra[-1] = -1
  push(-1, 'i = -1 → -1')
  for (let i = 0; i < n; i++) {
    const kq = vis.tra[i - 1]
    if (kq !== -1) {
      vis.tra[i] = kq
      push(i, `kq = ${kq} → ${kq}`)
    } else {
      vis.cmp[i] = a[i] === x
      vis.tra[i] = a[i] === x ? i : -1
      push(i, `${soSanh(a, i, x)} → ${vis.tra[i]}`)
    }
  }
  return ketThuc(vis.tra[n - 1])
}

export const CACH = [
  { tao: cach1, ghost: 'end' },
  { tao: cach2, ghost: 'end' },
  { tao: cach3, ghost: 'start' },
  { tao: cach4, ghost: 'start' },
]
