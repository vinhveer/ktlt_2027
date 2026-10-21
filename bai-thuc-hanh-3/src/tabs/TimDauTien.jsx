import { Group, NumberInput, SegmentedControl, Stack, TextInput } from '@mantine/core'
import StepPlayer from '../components/StepPlayer.jsx'
import ArrayView from '../components/ArrayView.jsx'
import { useTimDauTien } from '../hooks/useTimDauTien.js'
import { CACH } from '../sim/timDauTien.js'
import { roiFocus } from '../lib/roiFocus.js'

const CHON_CACH = CACH.map((_, i) => ({ label: `Cách ${i + 1}`, value: String(i) }))

export default function TimDauTien() {
  const { text, setText, a, error, xNhap, setX, cach, setCach, c, events } = useTimDauTien()

  return (
    <Stack gap="md">
      <SegmentedControl data={CHON_CACH} value={String(cach)} onChange={(v) => { setCach(Number(v)); roiFocus() }} style={{ alignSelf: 'flex-start' }} />

      <Group align="flex-start" gap="md">
        <TextInput
          label="a"
          value={text}
          onChange={(ev) => setText(ev.currentTarget.value)}
          error={error}
          w={380}
          maw="100%"
          classNames={{ input: 'mono' }}
        />
        <NumberInput
          label="x"
          value={xNhap}
          onChange={setX}
          allowDecimal={false}
          min={-999}
          max={999}
          w={110}
          classNames={{ input: 'mono' }}
        />
      </Group>

      <StepPlayer
        id="tim-dau-tien"
        events={events}
        visual={({ e }) => (
          <ArrayView
            large
            a={a}
            ghost={c.ghost}
            focus={e ? e.vis.i : null}
            cellClass={(i) => {
              if (!e) return ''
              if (e.vis.kq === i) return 'found'
              if (e.vis.cmp[i] === undefined) return ''
              return e.vis.cmp[i] ? 'ok' : 'no'
            }}
            below={(i) => (e && e.vis.tra[i] !== undefined ? e.vis.tra[i] : '')}
          />
        )}
      />
    </Stack>
  )
}
