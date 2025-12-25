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

#ifndef SRC_COMPONENTS_BUTTONS_ICON_BUTTONS_H_
#define SRC_COMPONENTS_BUTTONS_ICON_BUTTONS_H_

#include <QWidget>
#include <QToolButton>

namespace m3qw {
namespace components {

struct IconButtonConfig {
	QString icon_path = "";
};

class IconButton: public QToolButton {
  Q_OBJECT

 public:
  explicit IconButton(QWidget *parent = nullptr);
  ~IconButton();

 private:
  QString class_name_;
};

}  // namespace components
}  // namespace m3qw

#endif  // SRC_COMPONENTS_BUTTONS_ICON_BUTTONS_H_
