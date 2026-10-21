// Đọc chuỗi "4, 7, 9" thành mảng số nguyên; trả về { a } hoặc { error }

const MAX = 10

export function parseArray(text) {
  const parts = text.split(/[\s,;]+/).filter(Boolean)
  if (parts.length === 0) return { error: 'Nhập ít nhất 1 số' }
  if (parts.length > MAX) return { error: `Tối đa ${MAX} số` }
  const a = parts.map(Number)
  if (a.some((v) => !Number.isInteger(v))) return { error: 'Chỉ nhập số nguyên' }
  if (a.some((v) => Math.abs(v) > 999)) return { error: 'Từ -999 đến 999' }
  return { a }
}
