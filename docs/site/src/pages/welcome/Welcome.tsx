import type { JSX } from 'react'
import { useTranslation } from 'react-i18next'
import { ListItem, UnorderedList } from '@carbon/react'
import NavigationShell from '../../components/navigation/Navigation'
import './Welcome.scss'

export default function Welcome(): JSX.Element {
  const { t } = useTranslation()
  return (
    <>
      <NavigationShell activeId='welcome'>
        <h1>{t('%acticle_welcome%')}</h1>
        <p>{t('%welcome_p1%')}</p>
        <p>{t('%welcome_p2%')}</p>
        <UnorderedList>
          <ListItem>{t('%feature_custom_palette%')}</ListItem>
          <ListItem>{t('%feature_dynamic_dark_mode%')}</ListItem>
        </UnorderedList>
      </NavigationShell>
    </>
  )
}
