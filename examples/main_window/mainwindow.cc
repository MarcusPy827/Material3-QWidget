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

#include <QVBoxLayout>
#include <QSize>

#include <components/app_bar/app_bar.h>
#include <theme_loader/default_palette.h>

#include "main_window/mainwindow.h"

namespace m3qw {
namespace examples {

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
  setWindowTitle(tr("Material3-QWidget Example"));
  resize(QSize(800, 600));

  // You will need a background layer widget
  // You must set the classname to 'background_layer'
  auto * background_layer = new QWidget();
  background_layer->setProperty("class", "background_layer");
  this->setCentralWidget(background_layer);

  auto * main_layout = new QVBoxLayout();
  main_layout->setContentsMargins(0, 0, 0, 0);
  main_layout->setSpacing(0);
  main_layout->setAlignment(Qt::AlignTop);
  background_layer->setLayout(main_layout);

  // Set up app bar
  const auto & app_bar_config = components::AppBarConfig{
    .size = components::AppBarSize::kSmall,
    .title = tr("Material3-QWidget Example")
  };
  components::AppBar * app_bar = new components::AppBar(app_bar_config, this);
  main_layout->addWidget(app_bar);

  // Initialize theme loader
  if (theme_loader_ == nullptr) {
    theme_loader_ = new m3qw::loader::ThemeLoader(background_layer,
      m3qw::loader::default_color_config);
  }
}

MainWindow::~MainWindow() {
}

}  // namespace examples
}  // namespace m3qw
