import { useEffect, useState, type JSX } from 'react'
import { useTranslation } from 'react-i18next'
import NavigationShell from '../../components/navigation/Navigation'
import './Copying.scss'

export default function Copying(): JSX.Element {
  const { t } = useTranslation()
  const [copyingContent, setCopyingContent] = useState<string>('This project is licensed under GPL v3.')
  useEffect(() => {
    fetch('/COPYING')
      .then(response => response.text())
      .then(text => setCopyingContent(text))
  }, [])
  return (
    <>
      <NavigationShell activeId='copying'>
        <h1>{t('%article_copying%')}</h1>
        <pre className='copying-text'>{copyingContent}</pre>
      </NavigationShell>
    </>
  )
}
