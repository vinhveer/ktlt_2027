import { useAppStore } from '../store/useAppStore.js'

export function useThapHaNoi() {
  const soDia = useAppStore((s) => s.thapHaNoi.soDia)
  const cheDo = useAppStore((s) => s.thapHaNoi.cheDo)
  const setSoDia = useAppStore((s) => s.setSoDia)
  const setCheDo = useAppStore((s) => s.setCheDo)
  return { soDia, setSoDia, cheDo, setCheDo }
}
