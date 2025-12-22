/*
 * Copyright (C) 2025 MarcusPy827
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <QDebug>
#include <QApplication>
#include <QStyleHints>

#include "theme_loader/theme_loader.h"

namespace m3qw {
namespace loader {

ThemeLoader::ThemeLoader(QList<QWidget *> targets, QWidget * parent) {
  parent_widget_ = parent;
  installed_components_.clear();
  for (QWidget * target : targets) {
    installed_components_.append(target);
  }
  theme_map_ = GetThemeMap();
  LoadThemeFromMap(IsDarkMode());

  connect(qApp->styleHints(), &QStyleHints::colorSchemeChanged, this,
      [this](Qt::ColorScheme scheme){
    qInfo() << "[M3QW] Theme Loader: Detected color scheme has been"
      << "changed, now reloading theme...";
    LoadThemeFromMap(IsDarkMode());
  });
}

ThemeLoader::~ThemeLoader() {
  installed_components_.clear();
}

void ThemeLoader::LoadThemeFromMap(bool use_dark_mode) {
  if (parent_widget_ != nullptr) {
    qInfo() << "[M3QW Frontend] Theme Loader: Loading selector styles...";
    parent_widget_->setStyleSheet(use_dark_mode ? GenerateSelectorStyle()
      .dark_style : GenerateSelectorStyle().light_style);
  } else {
    qCritical() << "[M3QW Frontend] Theme Loader: No parent widget"
      << "was specified during initialization. "
      << "Selector styles will not be loaded.";
  }

  for (auto * component : installed_components_) {
    if (component == nullptr) {
      qCritical() << "[M3QW Frontend] Theme Loader: Nullptr encountered."
        << "Skipping loading style for current unknown component.";
      continue;
    }

    const QString element_name = component->objectName();
    qInfo() << "[M3QW Frontend] Theme Loader: Installing stylesheet for"
      << "widget:" << element_name;
    if (theme_map_.contains(element_name)) {
      const StyleTuple styles = theme_map_.value(element_name);
      if (use_dark_mode) {
        component->setStyleSheet(styles.dark_style);
        continue;
      } else {
        component->setStyleSheet(styles.light_style);
        continue;
      }
    }

    qWarning() << "[M3QW Frontend] Theme Loader: No style found for element:"
      << element_name;
    continue;
  }
}

bool ThemeLoader::IsDarkMode() {
  return (qApp->styleHints()->colorScheme() == Qt::ColorScheme::Dark);
}

}  // namespace loader
}  // namespace m3qw
