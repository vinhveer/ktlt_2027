import { Anchor, AppShell, Container, Flex, Group, Tabs, Text } from '@mantine/core'
import { IconSearch, IconSquareRoot2, IconStack2 } from '@tabler/icons-react'
import ThemeToggle from './components/ThemeToggle.jsx'
import { useActiveTab } from './hooks/useActiveTab.js'
import { roiFocus } from './lib/roiFocus.js'
import TongChinhPhuong from './tabs/TongChinhPhuong.jsx'
import TimDauTien from './tabs/TimDauTien.jsx'
import ThapHaNoi from './tabs/ThapHaNoi.jsx'

const TABS = [
  { id: 'chinh-phuong', label: 'Tổng chính phương', short: 'Chính phương', Icon: IconSquareRoot2, Comp: TongChinhPhuong },
  { id: 'tim-dau-tien', label: 'Tìm vị trí đầu tiên', short: 'Tìm đầu tiên', Icon: IconSearch, Comp: TimDauTien },
  { id: 'thap-ha-noi', label: 'Tháp Hà Nội', short: 'Hà Nội', Icon: IconStack2, Comp: ThapHaNoi },
]

export default function App() {
  const [tab, setTab] = useActiveTab(TABS.map((t) => t.id))
  const { Comp } = TABS.find((t) => t.id === tab)

  return (
    <AppShell header={{ height: { base: 100, sm: 60 } }} padding="md">
      <AppShell.Header>
        <Container size="lg" h="100%">
          <Flex
            h="100%"
            direction={{ base: 'column', sm: 'row' }}
            align={{ base: 'stretch', sm: 'center' }}
            justify="center"
            gap={{ base: 6, sm: 'lg' }}
          >
            <Group justify="space-between" wrap="nowrap">
              <Anchor href="../../" fw={600} c="inherit" underline="never" title="Về danh sách bài">
                Bài thực hành 3
              </Anchor>
              <ThemeToggle hiddenFrom="sm" />
            </Group>
            <Tabs value={tab} onChange={(v) => { setTab(v); roiFocus() }} variant="pills" radius="md" style={{ flex: 1, minWidth: 0 }}>
              <Tabs.List className="nav-tabs">
                {TABS.map((t) => (
                  <Tabs.Tab key={t.id} value={t.id} leftSection={<t.Icon size={16} />}>
                    <Text span inherit visibleFrom="xs">{t.label}</Text>
                    <Text span inherit hiddenFrom="xs">{t.short}</Text>
                  </Tabs.Tab>
                ))}
              </Tabs.List>
            </Tabs>
            <ThemeToggle visibleFrom="sm" />
          </Flex>
        </Container>
      </AppShell.Header>

      <AppShell.Main>
        <Container size="lg" pb="xl">
          <Comp />
        </Container>
      </AppShell.Main>
    </AppShell>
  )
}
