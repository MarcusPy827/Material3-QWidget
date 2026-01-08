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

#ifndef SRC_COMPONENTS_APP_BAR_APP_BAR_H_
#define SRC_COMPONENTS_APP_BAR_APP_BAR_H_

#include <QWidget>
#include <QList>

#include "components/app_bar/app_bar_icon_btn.h"

namespace m3qw {
namespace components {

enum class AppBarSize {
  kSearch,
  kSmall,
  kMedium,
  kLarge
};

struct AppBarConfig {
  AppBarSize size = AppBarSize::kSmall;
  AppBarIconBtn * leading_icon_btn = nullptr;
  QString title = "";
  QList<AppBarIconBtn *> trailing_icon_btns = {};
};

class AppBar: public QWidget {
  Q_OBJECT

 public:
  explicit AppBar(const AppBarConfig &config, QWidget *parent = nullptr);
  ~AppBar();
  AppBarConfig GetConfig();

 private:
  QString class_name_;
  AppBarConfig config_;
};

}  // namespace components
}  // namespace m3qw

#endif  // SRC_COMPONENTS_APP_BAR_APP_BAR_H_
