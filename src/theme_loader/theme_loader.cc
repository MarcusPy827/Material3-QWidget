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

ThemeLoader::ThemeLoader(QWidget * base_layer, interfaces::ColorConfig
    palette, QWidget * parent) {
  if (base_layer == nullptr) {
    qCritical() << "[ERROR] Theme Loader: No valid base layer."
      << "Skipping loading styles...";
    return;
  }

  install_target_ = base_layer;
  palette_conf_ = palette;
  theme_map_ = GetThemeMap(palette_conf_);
  LoadThemeFromMap(IsDarkMode());

  connect(qApp->styleHints(), &QStyleHints::colorSchemeChanged, this,
      [this](Qt::ColorScheme scheme){
    qInfo() << "[INFO] Theme Loader: Detected color scheme has been"
      << "changed, now reloading theme...";
    LoadThemeFromMap(IsDarkMode());
  });
}

ThemeLoader::~ThemeLoader() {
}

void ThemeLoader::LoadThemeFromMap(bool use_dark_mode) {
  if (install_target_ != nullptr) {
    qInfo() << "[INFO] Theme Loader: Loading selector styles...";
    install_target_->setStyleSheet(use_dark_mode ? theme_map_.dark_style :
      theme_map_.light_style);
  } else {
    qCritical() << "[ERROR] Theme Loader: No parent widget"
      << "was specified during initialization. "
      << "Selector styles will not be loaded.";
  }
}

bool ThemeLoader::IsDarkMode() {
  return (qApp->styleHints()->colorScheme() == Qt::ColorScheme::Dark);
}

}  // namespace loader
}  // namespace m3qw
