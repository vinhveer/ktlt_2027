import { useHotkeys } from '@mantine/hooks'
import { useAppStore } from '../store/useAppStore.js'
import { coTheMo, daXong, dong, mo, tiep } from '../sim/thapHaNoi.js'

// Chế độ "Ý tưởng": làm từng bước của bài đang xét, mở cục để đi sâu, đóng để quay lên.
// Phím: → bước tiếp, ← lùi, ↓ mở cục, ↑ lên một tầng
export function useHanoiYTuong() {
  const soDia = useAppStore((s) => s.thapHaNoi.soDia)
  const hist = useAppStore((s) => s.thapHaNoi.hist)
  const lam = useAppStore((s) => s.hanoiLam)
  const lui = useAppStore((s) => s.hanoiLui)
  const reset = useAppStore((s) => s.hanoiReset)

  const snap = hist[hist.length - 1]
  const L = snap.levels[snap.levels.length - 1]

  const api = {
    soDia,
    snap,
    L,
    xong: daXong(snap),
    moDuoc: coTheMo(snap),
    luiDuoc: hist.length > 1,
    lenDuoc: snap.levels.length > 1,
    tiep: () => lam(tiep),
    mo: () => lam(mo),
    dong: (i) => lam((s) => dong(s, i)),
    len: () => lam((s) => dong(s, s.levels.length - 2)),
    lui,
    reset,
  }

  useHotkeys([
    ['ArrowRight', api.tiep],
    ['ArrowLeft', lui],
    ['ArrowDown', api.mo],
    ['ArrowUp', api.len],
  ])

  return api
}
