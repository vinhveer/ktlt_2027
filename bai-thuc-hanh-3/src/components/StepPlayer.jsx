import { ActionIcon, Group, Slider, Stack, Text } from '@mantine/core'
import { IconChevronLeft, IconChevronRight, IconRefresh } from '@tabler/icons-react'
import { useStepPlayer } from '../hooks/useStepPlayer.js'

// Trình phát từng bước dùng chung cho các tab.
// events: danh sách bước đã chạy sẵn; bước nào có msg thì hiện ghi chú cỡ lớn bên dưới
// visual: hàm vẽ phần minh hoạ, nhận { e, cur, events }
export default function StepPlayer({ id, events, visual }) {
  const { cur, total, setCur, lui, tiep, reset } = useStepPlayer(id, events.length)
  const e = cur > 0 ? events[cur - 1] : null
  const coGhiChu = events.some((x) => x.msg)

  return (
    <Stack gap="md">
      <Stack gap="xs">
        <Group gap="xs">
          <ActionIcon variant="default" size="xl" onClick={lui} disabled={cur === 0} aria-label="Lùi">
            <IconChevronLeft size={22} />
          </ActionIcon>
          <ActionIcon size="xl" onClick={tiep} disabled={cur === total} aria-label="Bước tiếp">
            <IconChevronRight size={22} />
          </ActionIcon>
          <ActionIcon variant="subtle" size="xl" onClick={reset} disabled={cur === 0} aria-label="Làm lại">
            <IconRefresh size={20} />
          </ActionIcon>
          <Text size="sm" c="dimmed" ml="auto">{cur} / {total}</Text>
        </Group>
        <Slider min={0} max={total} value={cur} onChange={setCur} label={null} size="sm" aria-label="Bước" />
      </Stack>

      {visual({ e, cur, events })}

      {coGhiChu && <div className="idea">{e ? e.msg : ''}</div>}
    </Stack>
  )
}
