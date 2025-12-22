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

#ifndef SRC_THEME_LOADER_THEME_CONF_H_
#define SRC_THEME_LOADER_THEME_CONF_H_

#include <QStringLiteral>
#include <QString>
#include <QMap>
#include <QList>

#include "interfaces/color_palette.h"
#include "utils/utils.h"

namespace m3qw {
namespace loader {

struct StyleTuple {
  QString light_style;
  QString dark_style;
};

static QString GetAppBackground(interfaces::ColorPalette palette) {
  return utils::Utils::TemplateCat(
    QStringLiteral(R"""(
    *[class='background_layer'] {
        background: %t1%;
    })"""), QList<QString>{palette.kBackground});
}

static StyleTuple GetThemeMap(interfaces::ColorConfig conf) {
  return {
    GetAppBackground(conf.light),
    GetAppBackground(conf.dark)
  };
}

}  // namespace loader
}  // namespace m3qw

#endif  // SRC_THEME_LOADER_THEME_CONF_H_
