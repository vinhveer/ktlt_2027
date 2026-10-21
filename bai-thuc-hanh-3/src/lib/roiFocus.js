// Bỏ focus khỏi control vừa bấm (tab, nút chọn...) để phím mũi tên điều khiển mô phỏng
// thay vì đổi lựa chọn của control đó
export function roiFocus() {
  if (document.activeElement instanceof HTMLElement) document.activeElement.blur()
}
