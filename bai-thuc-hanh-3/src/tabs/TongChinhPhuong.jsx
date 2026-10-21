import { Stack, TextInput } from '@mantine/core'
import StepPlayer from '../components/StepPlayer.jsx'
import ArrayView from '../components/ArrayView.jsx'
import { useTongChinhPhuong } from '../hooks/useTongChinhPhuong.js'

export default function TongChinhPhuong() {
  const { text, setText, a, error, events } = useTongChinhPhuong()

  return (
    <Stack gap="md">
      <TextInput
        label="a"
        value={text}
        onChange={(ev) => setText(ev.currentTarget.value)}
        error={error}
        maw={380}
        classNames={{ input: 'mono' }}
      />

      <StepPlayer
        id="chinh-phuong"
        events={events}
        visual={({ e }) => (
          <ArrayView
            large
            a={a}
            ghost="end"
            focus={e ? e.vis.i : 0}
            cellClass={(i) => (e && e.vis.loai[i]) || ''}
            below={(i) => (e && e.vis.tong[i] !== undefined ? e.vis.tong[i] : '')}
          />
        )}
      />
    </Stack>
  )
}
