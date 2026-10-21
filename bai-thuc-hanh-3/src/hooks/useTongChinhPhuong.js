import { useMemo } from 'react'
import { useAppStore } from '../store/useAppStore.js'
import { taoCacBuoc } from '../sim/tongChinhPhuong.js'

export function useTongChinhPhuong() {
  const { text, a, error } = useAppStore((s) => s.chinhPhuong)
  const setText = useAppStore((s) => s.setChinhPhuongText)
  const events = useMemo(() => taoCacBuoc(a), [a])
  return { text, setText, a, error, events }
}
