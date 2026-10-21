import { Center, Group, SegmentedControl, Stack, Text } from '@mantine/core'
import { IconBulb, IconPlayerPlay } from '@tabler/icons-react'
import HanoiYTuong from '../components/HanoiYTuong.jsx'
import HanoiChay from '../components/HanoiChay.jsx'
import { useThapHaNoi } from '../hooks/useThapHaNoi.js'
import { SO_DIA_MAX } from '../sim/thapHaNoi.js'
import { roiFocus } from '../lib/roiFocus.js'

const CHON_SO_DIA = Array.from({ length: SO_DIA_MAX }, (_, i) => String(i + 1))

const CHE_DO = [
  { value: 'y-tuong', label: <Center style={{ gap: 6 }}><IconBulb size={16} />Ý tưởng</Center> },
  { value: 'chay', label: <Center style={{ gap: 6 }}><IconPlayerPlay size={16} />Chạy thật</Center> },
]

export default function ThapHaNoi() {
  const { soDia, setSoDia, cheDo, setCheDo } = useThapHaNoi()

  return (
    <Stack gap="md">
      <Group gap="lg">
        <Group gap="sm">
          <Text fw={500}>n</Text>
          <SegmentedControl data={CHON_SO_DIA} value={String(soDia)} onChange={(v) => { setSoDia(Number(v)); roiFocus() }} />
        </Group>
        <SegmentedControl data={CHE_DO} value={cheDo} onChange={(v) => { setCheDo(v); roiFocus() }} />
      </Group>

      {cheDo === 'y-tuong' ? <HanoiYTuong /> : <HanoiChay />}
    </Stack>
  )
}
