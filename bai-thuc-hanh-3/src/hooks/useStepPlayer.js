import { useHotkeys } from '@mantine/hooks'
import { useAppStore } from '../store/useAppStore.js'

// Điều khiển bước hiện tại của một trình phát (lưu trong store theo id),
// kèm phím mũi tên trái/phải để lùi/tiến
export function useStepPlayer(id, total) {
  const cur = Math.min(useAppStore((s) => s.steps[id] ?? 0), total)
  const setStep = useAppStore((s) => s.setStep)

  const setCur = (v) => setStep(id, Math.max(0, Math.min(total, v)))
  const lui = () => setCur(cur - 1)
  const tiep = () => setCur(cur + 1)
  const reset = () => setCur(0)

  // Bỏ qua khi đang focus thanh trượt, vì thanh trượt tự xử lý phím mũi tên
  const neuKhongPhaiSlider = (fn) => (ev) => {
    if (ev.target.closest && ev.target.closest('[role="slider"]')) return
    fn()
  }
  useHotkeys([
    ['ArrowLeft', neuKhongPhaiSlider(lui)],
    ['ArrowRight', neuKhongPhaiSlider(tiep)],
  ])

  return { cur, total, setCur, lui, tiep, reset }
}
