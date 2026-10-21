import { useEffect, useMemo } from 'react'
import { useHotkeys } from '@mantine/hooks'
import { useAppStore } from '../store/useAppStore.js'
import { danhSachNuoc, viTriSau } from '../sim/thapHaNoi.js'

export const TOC_DO = [
  { label: 'Chậm', ms: 1200 },
  { label: 'Vừa', ms: 650 },
  { label: 'Nhanh', ms: 250 },
]

// Chế độ "Chạy thật": tự chạy toàn bộ 2^n - 1 nước.
// Phím: Space chạy/dừng, ←/→ lùi/tiến một nước
export function useHanoiChay() {
  const { soDia, idx, dangChay, tocDo } = useAppStore((s) => s.thapHaNoi)
  const setChay = useAppStore((s) => s.setChay)

  const nuoc = useMemo(() => danhSachNuoc(soDia), [soDia])
  const total = nuoc.length
  const ms = TOC_DO[tocDo].ms

  useEffect(() => {
    if (!dangChay) return
    if (idx >= total) {
      setChay({ dangChay: false })
      return
    }
    const t = setTimeout(() => setChay({ idx: idx + 1 }), ms)
    return () => clearTimeout(t)
  }, [dangChay, idx, total, ms, setChay])

  const setIdx = (v) => setChay({ idx: Math.max(0, Math.min(total, v)), dangChay: false })
  const chayDung = () => {
    if (dangChay) setChay({ dangChay: false })
    else setChay({ dangChay: true, idx: idx >= total ? 0 : idx })
  }

  useHotkeys([
    ['space', chayDung],
    ['ArrowLeft', () => setIdx(idx - 1)],
    ['ArrowRight', () => setIdx(idx + 1)],
  ])

  return {
    soDia,
    idx,
    total,
    dangChay,
    tocDo,
    ms,
    pos: viTriSau(soDia, nuoc, idx),
    nuocCuoi: idx > 0 ? nuoc[idx - 1] : null,
    setIdx,
    chayDung,
    reset: () => setIdx(0),
    setTocDo: (v) => setChay({ tocDo: v }),
  }
}
