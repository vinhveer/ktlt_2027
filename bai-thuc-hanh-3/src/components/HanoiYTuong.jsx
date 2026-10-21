import { ActionIcon, Anchor, Box, Breadcrumbs, Group, Stack, Text } from '@mantine/core'
import {
  IconArrowNarrowRight,
  IconChevronLeft,
  IconChevronRight,
  IconRefresh,
  IconZoomIn,
  IconZoomOut,
} from '@tabler/icons-react'
import HanoiBoard from './HanoiBoard.jsx'
import HanoiSteps from './HanoiSteps.jsx'
import { useHanoiYTuong } from '../hooks/useHanoiYTuong.js'

const tenBai = (l) => (
  <>
    {l.k} đĩa: {l.nguon} <IconArrowNarrowRight size={18} className="step-arrow" /> {l.dich}
  </>
)

export default function HanoiYTuong() {
  const h = useHanoiYTuong()
  const { snap, L } = h
  const cuoi = snap.levels.length - 1

  return (
    <Stack gap="md">
      <Group gap="xs">
        <ActionIcon variant="default" size="xl" onClick={h.lui} disabled={!h.luiDuoc} aria-label="Lùi">
          <IconChevronLeft size={22} />
        </ActionIcon>
        <ActionIcon size="xl" onClick={h.tiep} disabled={h.xong} aria-label="Bước tiếp">
          <IconChevronRight size={22} />
        </ActionIcon>
        <ActionIcon variant="light" size="xl" onClick={h.mo} disabled={!h.moDuoc} aria-label="Mở cục">
          <IconZoomIn size={20} />
        </ActionIcon>
        <ActionIcon variant="light" size="xl" onClick={h.len} disabled={!h.lenDuoc} aria-label="Lên một tầng">
          <IconZoomOut size={20} />
        </ActionIcon>
        <ActionIcon variant="subtle" size="xl" onClick={h.reset} disabled={!h.luiDuoc} aria-label="Làm lại">
          <IconRefresh size={20} />
        </ActionIcon>
      </Group>

      <Breadcrumbs separator={<IconChevronRight size={16} />} className="crumbs">
        {snap.levels.map((l, i) =>
          i < cuoi ? (
            <Anchor key={i} component="button" type="button" onClick={() => h.dong(i)} c="dimmed" inherit>
              {tenBai(l)}
            </Anchor>
          ) : (
            <Text key={i} span inherit fw={700}>{tenBai(l)}</Text>
          ),
        )}
      </Breadcrumbs>

      <HanoiBoard
        soDia={h.soDia}
        pos={snap.pos}
        vaiTro={{ nguon: L.nguon, dich: L.dich, trungGian: L.trungGian }}
        k={L.k}
        moDuoc={h.moDuoc}
        onMo={h.mo}
        thoiGian={600}
      />

      <Box w="100%" maw={440} mx="auto">
        <HanoiSteps L={L} moDuoc={h.moDuoc} onMo={h.mo} />
      </Box>
    </Stack>
  )
}
