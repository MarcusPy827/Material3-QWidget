import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import { BrowserRouter } from 'react-router'
import Welcome from './pages/welcome/Welcome'
import './locales/translator'
import './index.css'

createRoot(document.getElementById('root')!).render(
  <StrictMode>
    <BrowserRouter>
      <Welcome />
    </BrowserRouter>
  </StrictMode>,
)
