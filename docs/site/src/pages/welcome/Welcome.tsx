import type { JSX } from 'react'
import { useTranslation } from 'react-i18next'
import NavigationShell from '../../components/navigation/Navigation'
import './Welcome.scss'

export default function Welcome(): JSX.Element {
  const { t } = useTranslation()
  return (
    <>
      <NavigationShell activeId='welcome'>
        <h1>{t('%acticle_welcome%')}</h1>
      </NavigationShell>
    </>
  )
}
