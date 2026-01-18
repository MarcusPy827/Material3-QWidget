import { useState } from 'react'
import { Header, SkipToContent, HeaderMenuButton, HeaderName, SideNav, SideNavMenu, SideNavMenuItem } from '@carbon/react'
import { Concept, Document } from '@carbon/icons-react'
import { useTranslation } from 'react-i18next'
import './Navigation.scss'

function NavigationShell({ activeId, children }: { activeId?: string; children?: React.ReactNode }) {
  const { t } = useTranslation()
  const [isNavigationDrawerExpanded, setIsNavigationDrawerExpanded] = useState(true)
  return (
    <>
      <Header aria-label='Material3-QWidget Docs'>
        <SkipToContent />
        <HeaderMenuButton
          aria-label={isNavigationDrawerExpanded ? 'Close menu' : 'Open menu'}
          onClick={() => setIsNavigationDrawerExpanded(!isNavigationDrawerExpanded)}
          isActive={isNavigationDrawerExpanded}
          aria-expanded={isNavigationDrawerExpanded}
        />
        <HeaderName href='#' prefix='Material3-QWidget'>
          {t('%website_subtitle%')}
        </HeaderName>
      </Header>

      <SideNav
        aria-label='Navigation drawer'
        expanded={isNavigationDrawerExpanded}
        onSideNavBlur={() => setIsNavigationDrawerExpanded(!isNavigationDrawerExpanded)}
        href='#'
      >
        <SideNavMenu renderIcon={Concept} title={t('%category_quick_start%')} tabIndex={0}>
          <SideNavMenuItem href='/' aria-current={activeId === 'welcome' ? 'page' : undefined}>
              {t('%article_welcome%')}
          </SideNavMenuItem>
          <SideNavMenuItem href='/copying' aria-current={activeId === 'copying' ? 'page' : undefined}>
              {t('%article_copying%')}
          </SideNavMenuItem>
        </SideNavMenu>
      </SideNav>

      <main 
        id='main-content' 
        className={isNavigationDrawerExpanded ? 'main-with-sidebar' : 'main-without-sidebar'}
      >
        {children}
      </main>
    </>
  )
}

export default NavigationShell
