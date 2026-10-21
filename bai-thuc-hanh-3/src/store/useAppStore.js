import { create } from 'zustand'
import { parseArray } from '../lib/parseArray.js'
import { khoiTao } from '../sim/thapHaNoi.js'

// Ô nhập mảng: giữ nguyên chuỗi người dùng gõ, còn mảng a chỉ đổi khi chuỗi hợp lệ
function nhapMang(text) {
  return { text, a: parseArray(text).a, error: null }
}

function capNhatMang(cu, text) {
  const r = parseArray(text)
  return { text, a: r.a || cu.a, error: r.error || null }
}

const cungMang = (a, b) => a.join(',') === b.join(',')

export const useAppStore = create((set) => ({
  // Bước hiện tại của từng trình phát, theo id tab
  steps: {},
  setStep: (id, cur) => set((s) => ({ steps: { ...s.steps, [id]: cur } })),

  chinhPhuong: nhapMang('4, 7, 9, 10, 16, -4'),
  setChinhPhuongText: (text) =>
    set((s) => {
      const moi = capNhatMang(s.chinhPhuong, text)
      const steps = cungMang(moi.a, s.chinhPhuong.a) ? s.steps : { ...s.steps, 'chinh-phuong': 0 }
      return { chinhPhuong: moi, steps }
    }),

  timDauTien: { ...nhapMang('3, 5, 2, 5, 8'), x: 5, cach: 0 },
  setTimDauTienText: (text) =>
    set((s) => {
      const moi = { ...s.timDauTien, ...capNhatMang(s.timDauTien, text) }
      const steps = cungMang(moi.a, s.timDauTien.a) ? s.steps : { ...s.steps, 'tim-dau-tien': 0 }
      return { timDauTien: moi, steps }
    }),
  setTimDauTienX: (x) =>
    set((s) => ({ timDauTien: { ...s.timDauTien, x }, steps: { ...s.steps, 'tim-dau-tien': 0 } })),
  setTimDauTienCach: (cach) =>
    set((s) => ({ timDauTien: { ...s.timDauTien, cach }, steps: { ...s.steps, 'tim-dau-tien': 0 } })),

  // Tháp Hà Nội: hist là lịch sử trạng thái chế độ "Ý tưởng" (để lùi lại),
  // idx / dangChay / tocDo dùng cho chế độ "Chạy thật"
  thapHaNoi: { soDia: 3, cheDo: 'y-tuong', hist: [khoiTao(3)], idx: 0, dangChay: false, tocDo: 1 },
  setSoDia: (soDia) =>
    set((s) => ({ thapHaNoi: { ...s.thapHaNoi, soDia, hist: [khoiTao(soDia)], idx: 0, dangChay: false } })),
  setCheDo: (cheDo) => set((s) => ({ thapHaNoi: { ...s.thapHaNoi, cheDo, dangChay: false } })),
  hanoiLam: (fn) =>
    set((s) => {
      const h = s.thapHaNoi.hist
      const moi = fn(h[h.length - 1])
      return moi === h[h.length - 1] ? {} : { thapHaNoi: { ...s.thapHaNoi, hist: [...h, moi] } }
    }),
  hanoiLui: () =>
    set((s) => {
      const h = s.thapHaNoi.hist
      return h.length > 1 ? { thapHaNoi: { ...s.thapHaNoi, hist: h.slice(0, -1) } } : {}
    }),
  hanoiReset: () => set((s) => ({ thapHaNoi: { ...s.thapHaNoi, hist: [khoiTao(s.thapHaNoi.soDia)] } })),
  setChay: (patch) => set((s) => ({ thapHaNoi: { ...s.thapHaNoi, ...patch } })),
}))
