import { ActionIcon, useComputedColorScheme, useMantineColorScheme } from '@mantine/core'
import { IconMoon, IconSun } from '@tabler/icons-react'

export default function ThemeToggle(props) {
  const { setColorScheme } = useMantineColorScheme()
  const scheme = useComputedColorScheme('light')
  const toi = scheme === 'dark'

  return (
    <ActionIcon
      variant="default"
      size="lg"
      aria-label={toi ? 'Chuyển sang nền sáng' : 'Chuyển sang nền tối'}
      onClick={() => setColorScheme(toi ? 'light' : 'dark')}
      {...props}
    >
      {toi ? <IconSun size={18} /> : <IconMoon size={18} />}
    </ActionIcon>
  )
}
