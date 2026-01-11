import { useEffect, useState, type JSX } from "react";
import { useTranslation } from 'react-i18next';

import pkg from '@arco-design/web-react';
import "@arco-design/web-react/dist/css/arco.css";

const { PageHeader } = pkg;

export default function MainWindow(): JSX.Element {
  const { t } = useTranslation();
  const [isDrawerOpen, setIsDrawerOpen] = useState(true);
  const toggleDrawer = () => setIsDrawerOpen(!isDrawerOpen);

  useEffect(() => {
    const isDarkTheme = window.matchMedia("(prefers-color-scheme: dark)");
    const handleThemeSwitch = (e: MediaQueryListEvent | MediaQueryList) => {
      if (e.matches) {
        document.body.setAttribute('arco-theme', 'dark');
      } else {
        document.body.removeAttribute('arco-theme');
      }
    };
    handleThemeSwitch(isDarkTheme);
    isDarkTheme.addEventListener('change', handleThemeSwitch);
    return () => {
      isDarkTheme.removeEventListener('change', handleThemeSwitch);
    };
  }, []);

  const [breadcrumbRoutes, setBreadcrumbRoutes] = useState([
    {
      path: '/',
      breadcrumbName: 'Home',
    }
  ]);
  const [chapterTitle, setChapterTitle] = useState('Home');

  return (
    <>
      <PageHeader
        style={{ background: 'var(--color-bg-2)' }}
        title={t('%website_title%')}
        subTitle={chapterTitle}
        breadcrumb={{routes: breadcrumbRoutes}}
        extra={<></>}
      ></PageHeader>
    </>
  );
}