import { useState } from 'react'
import { Header, SkipToContent, HeaderMenuButton, HeaderName, SideNav, SideNavItems, SideNavLink } from '@carbon/react'
import { Document } from '@carbon/icons-react'
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
        <SideNavItems>
          <SideNavLink renderIcon={Document} href='/' isActive={activeId === 'welcome'}>
            {t('%acticle_welcome%')}
          </SideNavLink>
        </SideNavItems>
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
