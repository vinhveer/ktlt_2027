import { useMemo } from 'react'
import { useAppStore } from '../store/useAppStore.js'
import { CACH } from '../sim/timDauTien.js'

export function useTimDauTien() {
  const { text, a, error, x: xNhap, cach } = useAppStore((s) => s.timDauTien)
  const setText = useAppStore((s) => s.setTimDauTienText)
  const setX = useAppStore((s) => s.setTimDauTienX)
  const setCach = useAppStore((s) => s.setTimDauTienCach)

  // Ô x để trống thì tạm coi x = 0
  const x = typeof xNhap === 'number' ? xNhap : 0
  const c = CACH[cach]
  const events = useMemo(() => c.tao(a, x), [c, a, x])

  return { text, setText, a, error, xNhap, x, setX, cach, setCach, c, events }
}
