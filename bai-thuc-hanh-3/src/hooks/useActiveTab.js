import { useHash } from '@mantine/hooks'

// Tab đang mở lưu trên URL (#id) để tải lại trang hay gửi link vẫn đúng tab
export function useActiveTab(ids) {
  const [hash, setHash] = useHash({ getInitialValueInEffect: false })
  const h = hash.replace(/^#/, '')
  const tab = ids.includes(h) ? h : ids[0]
  return [tab, (id) => setHash(id)]
}
