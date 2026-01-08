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

#ifndef SRC_THEME_LOADER_DEFAULT_PALETTE_H_
#define SRC_THEME_LOADER_DEFAULT_PALETTE_H_

#include "interfaces/color_palette.h"

namespace m3qw {
namespace loader {

interfaces::ColorPalette default_light_palette = {
  "#F6FAFE",  // kBackground
  "#EBEEF3",  // kSurfaceContainer
  "#181C20",  // kOnSurface
  "#41484D",  // kOnSurfaceVariant
};

interfaces::ColorPalette default_dark_palette = {
  "#101417",  // kBackground
  "#1C2024",  // kSurfaceContainer
  "#DFE3E7",  // kOnSurface
  "#C1C7CE",  // kOnSurfaceVariant
};

interfaces::ColorConfig default_color_config = {
  default_light_palette,
  default_dark_palette
};

}  // namespace loader
}  // namespace m3qw

#endif  // SRC_THEME_LOADER_DEFAULT_PALETTE_H_
