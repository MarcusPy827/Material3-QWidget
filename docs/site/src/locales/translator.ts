import i18n from 'i18next'
import { initReactI18next } from 'react-i18next'
import LanguageDetector from 'i18next-browser-languagedetector'

import getChineseTranslations from './locale_ZH_CN'
import getEnglishTranslations from './locale_EN_US'

const resources = {
  zh: getChineseTranslations(),
    en: getEnglishTranslations(),
};

i18n
  .use(LanguageDetector)
  .use(initReactI18next)
  .init({
    resources,
    fallbackLng: 'en',

    interpolation: {
      escapeValue: false
    }
  });

export default i18n;
