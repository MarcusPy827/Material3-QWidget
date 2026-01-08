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

#ifndef SRC_FONT_LOADER_FONT_LOADER_H_
#define SRC_FONT_LOADER_FONT_LOADER_H_

#include <QFont>
#include <QFontDatabase>

namespace m3qw {
namespace loader {

class FontLoader {
 public:
  static QFont GetOutlinedMaterialSymbolFont();
  static QFont GetRoundedMaterialSymbolFont();
  static QFont GetSharpMaterialSymbolFont();

 private:
  inline static bool is_outlined_symbols_loaded_ = false;
  inline static int outlined_symbol_id_ = -1;

  inline static bool is_rounded_symbols_loaded_ = false;
  inline static int rounded_symbol_id_ = -1;

  inline static bool is_sharp_symbols_loaded_ = false;
  inline static int sharp_symbol_id_ = -1;
};

}  // namespace loader
}  // namespace m3qw

#endif  // SRC_FONT_LOADER_FONT_LOADER_H_
