import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import { BrowserRouter, Routes, Route } from 'react-router'
import Copying from './pages/copying/Copying'
import Welcome from './pages/welcome/Welcome'
import './locales/translator'
import './index.css'

createRoot(document.getElementById('root')!).render(
  <StrictMode>
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Welcome />} />
        <Route path="/copying" element={<Copying />} />
      </Routes>
    </BrowserRouter>
  </StrictMode>,
)
