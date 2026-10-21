import { ActionIcon, Group, SegmentedControl, Slider, Stack, Text } from '@mantine/core'
import {
  IconArrowNarrowRight,
  IconChevronLeft,
  IconChevronRight,
  IconPlayerPauseFilled,
  IconPlayerPlayFilled,
  IconRefresh,
} from '@tabler/icons-react'
import HanoiBoard from './HanoiBoard.jsx'
import { TOC_DO, useHanoiChay } from '../hooks/useHanoiChay.js'
import { roiFocus } from '../lib/roiFocus.js'

const CHON_TOC_DO = TOC_DO.map((t, i) => ({ label: t.label, value: String(i) }))

export default function HanoiChay() {
  const c = useHanoiChay()

  return (
    <Stack gap="md">
      <Stack gap="xs">
        <Group gap="xs">
          <ActionIcon variant="default" size="xl" onClick={() => c.setIdx(c.idx - 1)} disabled={c.idx === 0} aria-label="Lùi">
            <IconChevronLeft size={22} />
          </ActionIcon>
          <ActionIcon size="xl" onClick={c.chayDung} aria-label={c.dangChay ? 'Dừng' : 'Chạy'}>
            {c.dangChay ? <IconPlayerPauseFilled size={20} /> : <IconPlayerPlayFilled size={20} />}
          </ActionIcon>
          <ActionIcon variant="default" size="xl" onClick={() => c.setIdx(c.idx + 1)} disabled={c.idx === c.total} aria-label="Tiến">
            <IconChevronRight size={22} />
          </ActionIcon>
          <ActionIcon variant="subtle" size="xl" onClick={c.reset} disabled={c.idx === 0} aria-label="Làm lại">
            <IconRefresh size={20} />
          </ActionIcon>
          <SegmentedControl data={CHON_TOC_DO} value={String(c.tocDo)} onChange={(v) => { c.setTocDo(Number(v)); roiFocus() }} />
          <Text size="sm" c="dimmed" ml="auto">{c.idx} / {c.total}</Text>
        </Group>
        <Slider min={0} max={c.total} value={c.idx} onChange={c.setIdx} label={null} size="sm" aria-label="Nước đi" />
      </Stack>

      <HanoiBoard
        soDia={c.soDia}
        pos={c.pos}
        vaiTro={{ nguon: 'A', dich: 'C', trungGian: 'B' }}
        thoiGian={Math.min(450, c.ms * 0.8)}
      />

      <div className="idea">
        {c.nuocCuoi && (
          <>
            Đĩa {c.nuocCuoi[0]}: {c.nuocCuoi[1]} <IconArrowNarrowRight className="idea-arrow" /> {c.nuocCuoi[2]}
          </>
        )}
      </div>
    </Stack>
  )
}
