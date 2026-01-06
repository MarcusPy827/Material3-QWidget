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

#include <QColor>
#include <QDebug>

#include "utils/utils.h"

namespace m3qw {
namespace utils {

QString Utils::TemplateCat(QString original, QList<QString> args) {
  for (int i = 0; i < args.size(); i++) {
    const QString current_arg = args.at(i);
    const QString current_template_placeholder = "%t" + QString::number(i + 1)
      + "%";
    original.replace(current_template_placeholder, current_arg);
  }
  return original;
}

QString Utils::ApplyOpacityToHexColor(const QString& hex,
    const double & opacity) {
  QColor color(hex);
  if (color.isValid()) {
    int r = color.red();
    int g = color.green();
    int b = color.blue();

    return TemplateCat(QStringLiteral(R"""(rgba(%t1%, %t2%, %t3%, %t4%))"""),
      QList<QString>{
        QString::number(r), QString::number(g), QString::number(b),
        QString::number(opacity)});
  } else {
    qCritical() << "[ERROR] Hex color util: Cannot apply opacity to hex color"
      << hex << "as it is invalid, no action taken.";
    return hex;
  }
}

}  // namespace utils
}  // namespace m3qw
