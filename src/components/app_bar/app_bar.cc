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

#include <QHBoxLayout>
#include <QStackedWidget>
#include <QLabel>

#include "components/app_bar/app_bar.h"

namespace m3qw {
namespace components {

AppBar::AppBar(const AppBarConfig &config, QWidget *parent): QWidget(parent) {
  switch (config.size) {
    case AppBarSize::kSearch: {
      class_name_ = "app_bar_container_search";
      break;
    }

    case AppBarSize::kSmall: {
      class_name_ = "app_bar_container_small";
      break;
    }

    case AppBarSize::kMedium: {
      class_name_ = "app_bar_container_medium";
      break;
    }

    case AppBarSize::kLarge: {
      class_name_ = "app_bar_container_large";
      break;
    }

    default: {
      qWarning() << "[M3QW] AppBar: Unknown AppBarSize provided."
        << "Now defaulting to AppBarSize::kSmall...";
      class_name_ = "app_bar_container_small";
      break;
    }
  }
  setProperty("class", class_name_);

  auto * app_bar_container_layout_internal = new QHBoxLayout();
  app_bar_container_layout_internal->setContentsMargins(0, 0, 0, 0);
  app_bar_container_layout_internal->setSpacing(0);
  this->setLayout(app_bar_container_layout_internal);

  auto * app_bar_widget_internal = new QWidget();
  app_bar_widget_internal->setProperty("class", class_name_);
  app_bar_container_layout_internal->addWidget(app_bar_widget_internal);

  auto * app_bar_layout_internal = new QVBoxLayout();
  app_bar_layout_internal->setContentsMargins(0, 0, 0, 0);
  app_bar_widget_internal->setLayout(app_bar_layout_internal);

  auto * app_bar_stack_container_internal = new QStackedWidget();
  app_bar_stack_container_internal->setContentsMargins(0, 0, 0, 0);
  app_bar_container_layout_internal->layout()->setContentsMargins(0, 0, 0, 0);
  app_bar_stack_container_internal->setProperty("class", "app_bar_container");
  app_bar_layout_internal->addWidget(app_bar_stack_container_internal);

  auto * main_page_bar_container = new QWidget();
  main_page_bar_container->setProperty("class", "app_bar_container");
  main_page_bar_container->setContentsMargins(0, 0, 0, 0);
  app_bar_stack_container_internal->insertWidget(0,
    main_page_bar_container);

  auto * main_page_bar_layout = new QHBoxLayout();
  main_page_bar_layout->setContentsMargins(24, 0, 24, 0);
  main_page_bar_layout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  main_page_bar_container->setLayout(main_page_bar_layout);

  auto * title_label_internal = new QLabel();
  title_label_internal->setProperty("class", "app_bar_title_label");
  title_label_internal->setText(config.title);
  main_page_bar_layout->addWidget(title_label_internal);
}

AppBar::~AppBar() {
  qInfo() << "[M3QW Frontend] AppBar: App Bar is being deleted.";
}

}  // namespace components
}  // namespace m3qw
