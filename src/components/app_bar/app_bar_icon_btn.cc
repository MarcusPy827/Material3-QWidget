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

#include "components/app_bar/app_bar_icon_btn.h"
#include "font_loader/font_loader.h"

namespace m3qw {
namespace components {

AppBarIconBtn::AppBarIconBtn(const AppBarIconBtnConfig &config, QWidget *
    parent): QToolButton(parent) {
  this->setFixedSize(QSize(48, 48));
  this->setProperty("class", "app_bar_icon_button");
  this->setText(config.icon_name);

  switch (config.icon_variant) {
    case utils::IconVariant::kOutlined: {
      this->setFont(loader::FontLoader::GetOutlinedMaterialSymbolFont());
      break;
    }

    case utils::IconVariant::kRounded: {
      this->setFont(loader::FontLoader::GetRoundedMaterialSymbolFont());
      break;
    }

    case utils::IconVariant::kSharp: {
      this->setFont(loader::FontLoader::GetSharpMaterialSymbolFont());
      break;
    }

    default: {
      qWarning() << "[WARN] AppBarIconBtn: Unknown IconVariant provided."
        << "Now defaulting to rounded...";
      this->setFont(loader::FontLoader::GetRoundedMaterialSymbolFont());
      break;
    }
  }
}

AppBarIconBtn::~AppBarIconBtn() {}

}  // namespace components
}  // namespace m3qw
