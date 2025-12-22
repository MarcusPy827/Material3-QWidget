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

#ifndef SRC_THEME_LOADER_THEME_LOADER_H_
#define SRC_THEME_LOADER_THEME_LOADER_H_

#include <QObject>
#include <QList>
#include <QWidget>

#include "theme_loader/theme_conf.h"

namespace m3qw {
namespace loader {

class ThemeLoader: public QObject {
  Q_OBJECT

 public:
  explicit ThemeLoader(QList<QWidget *> targets, QWidget * parent = nullptr);
  ~ThemeLoader();
  void LoadThemeFromMap(bool use_dark_mode = false);

 private:
  bool IsDarkMode();
  QList<QWidget *> installed_components_;
  QWidget * parent_widget_ = nullptr;
  QMap<QString, StyleTuple> theme_map_;
};

}  // namespace loader
}  // namespace m3qw

#endif  // SRC_THEME_LOADER_THEME_LOADER_H_
