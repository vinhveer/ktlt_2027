import { ActionIcon, Group, Paper, Text, ThemeIcon } from '@mantine/core'
import { IconArrowNarrowRight, IconCheck, IconZoomIn } from '@tabler/icons-react'
import { cacBuoc } from '../sim/thapHaNoi.js'

const Mui = () => <IconArrowNarrowRight size={18} className="step-arrow" />

// 3 bước của bài đang xét; màu ô vuông khớp màu đĩa trên bàn (cục / đĩa đáy)
export default function HanoiSteps({ L, moDuoc, onMo }) {
  const buoc = cacBuoc(L)
    .map((b, i) => ({ ...b, i }))
    .filter((b) => !(b.loai === 'cuc' && b.soDia === 0))

  return (
    <Paper withBorder radius="md" p="sm">
      {buoc.map((b) => {
        const trangThai = b.i < L.step ? 'xong' : b.i === L.step ? 'on' : ''
        const ten = b.loai === 'day' ? `Đĩa ${b.dia}` : b.soDia === 1 ? 'Đĩa 1' : `${b.soDia} đĩa`
        return (
          <Group key={b.i} gap="sm" wrap="nowrap" className={'step ' + trangThai}>
            <ThemeIcon
              size={24}
              radius="xl"
              variant={trangThai === 'on' ? 'filled' : 'light'}
              color={trangThai === 'xong' ? 'teal' : trangThai === 'on' ? undefined : 'gray'}
            >
              {trangThai === 'xong' ? <IconCheck size={14} stroke={3} /> : <Text span size="xs" fw={700}>{b.i + 1}</Text>}
            </ThemeIcon>
            <i className={'sw ' + b.loai} />
            <span className="step-text">
              {ten}: {b.tu} <Mui /> {b.sang}
            </span>
            {trangThai === 'on' && b.loai === 'cuc' && moDuoc && (
              <ActionIcon variant="light" ml="auto" onClick={onMo} aria-label="Mở cục">
                <IconZoomIn size={18} />
              </ActionIcon>
            )}
          </Group>
        )
      })}
    </Paper>
  )
}
