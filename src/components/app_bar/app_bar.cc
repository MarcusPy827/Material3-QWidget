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
#include <QSpacerItem>

#include "components/app_bar/app_bar.h"

namespace m3qw {
namespace components {

AppBar::AppBar(const AppBarConfig &config, QWidget *parent): QWidget(parent) {
  config_ = config;
  switch (config_.size) {
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
  this->setProperty("class", class_name_);

  auto * app_bar_container_layout_internal = new QHBoxLayout();
  app_bar_container_layout_internal->setContentsMargins(0, 0, 0, 0);
  app_bar_container_layout_internal->setSpacing(0);
  this->setLayout(app_bar_container_layout_internal);

  auto * app_bar_background_layer_internal = new QWidget();
  app_bar_background_layer_internal->setProperty("class", class_name_);
  app_bar_container_layout_internal->addWidget(
    app_bar_background_layer_internal);

  auto * app_bar_container_multirow_layout_internal = new QVBoxLayout();
  app_bar_container_multirow_layout_internal->setContentsMargins(0, 0, 0, 0);
  app_bar_container_multirow_layout_internal->setSpacing(0);
  app_bar_background_layer_internal->setLayout(
    app_bar_container_multirow_layout_internal);

  auto * app_bar_row_1_internal = new QHBoxLayout();
  if (config_.leading_icon_btn == nullptr) {
    if (config_.trailing_icon_btns.isEmpty()) {
      app_bar_row_1_internal->setContentsMargins(16, 0, 16, 0);
    } else {
      app_bar_row_1_internal->setContentsMargins(16, 0, 4, 0);
    }
  } else {
    if (config_.trailing_icon_btns.isEmpty()) {
      app_bar_row_1_internal->setContentsMargins(4, 0, 16, 0);
    } else {
      app_bar_row_1_internal->setContentsMargins(4, 0, 4, 0);
    }
  }
  app_bar_row_1_internal->setSpacing(0);
  app_bar_row_1_internal->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  app_bar_container_multirow_layout_internal->addLayout(
    app_bar_row_1_internal);

  if (config_.leading_icon_btn != nullptr) {
    app_bar_row_1_internal->addWidget(config_.leading_icon_btn);
    QSpacerItem * leading_icon_btn_padding = new QSpacerItem(4, 48,
      QSizePolicy::Fixed, QSizePolicy::Fixed);
    app_bar_row_1_internal->addSpacerItem(leading_icon_btn_padding);
  }

  auto * titles_row_1_layout_internal = new QVBoxLayout();
  titles_row_1_layout_internal->setContentsMargins(0, 0, 0, 0);
  titles_row_1_layout_internal->setSpacing(0);
  app_bar_row_1_internal->addLayout(titles_row_1_layout_internal);

  if (title_label_row_1_internal == nullptr) {
    title_label_row_1_internal = new QLabel();
  }
  title_label_row_1_internal->setProperty("class", "app_bar_title_label");
  title_label_row_1_internal->setText(config_.title);
  if (config_.size != AppBarSize::kSmall) {
    title_label_row_1_internal->hide();
  }
  titles_row_1_layout_internal->addWidget(title_label_row_1_internal);

  if (subtitle_label_row_1_internal == nullptr) {
    subtitle_label_row_1_internal = new QLabel();
  }
  subtitle_label_row_1_internal->setProperty("class", "app_bar_subtitle_label");
  subtitle_label_row_1_internal->setText(config_.subtitle);
  if (config_.size != AppBarSize::kSmall) {
    subtitle_label_row_1_internal->hide();
  }
  if (config_.subtitle.isEmpty()) {
    subtitle_label_row_1_internal->hide();
  }
  titles_row_1_layout_internal->addWidget(subtitle_label_row_1_internal);

  QSpacerItem * title_trailing_spacer_internal = new QSpacerItem(48, 48,
    QSizePolicy::Expanding, QSizePolicy::Fixed);
  app_bar_row_1_internal->addSpacerItem(title_trailing_spacer_internal);

  if (!config_.trailing_icon_btns.isEmpty()) {
    for (auto * btn : config_.trailing_icon_btns) {
      app_bar_row_1_internal->addWidget(btn);
    }
  }

  auto * app_bar_row_2_internal = new QHBoxLayout();
  app_bar_row_2_internal->setContentsMargins(16, 0, 16, 0);
  app_bar_row_2_internal->setSpacing(0);
  app_bar_row_2_internal->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  if (config_.size == AppBarSize::kMedium || config_.size ==
      AppBarSize::kLarge) {
    app_bar_container_multirow_layout_internal->addLayout(
      app_bar_row_2_internal);
  }

  auto * titles_row_2_layout_internal = new QVBoxLayout();
  titles_row_2_layout_internal->setContentsMargins(0, 0, 0, 0);
  titles_row_2_layout_internal->setSpacing(4);
  app_bar_row_2_internal->addLayout(titles_row_2_layout_internal);

  if (title_label_row_2_internal == nullptr) {
    title_label_row_2_internal = new QLabel();
  }
  title_label_row_2_internal->setProperty("class", "app_bar_title_label");
  title_label_row_2_internal->setText(config_.title);
  titles_row_2_layout_internal->addWidget(title_label_row_2_internal);

  if (subtitle_label_row_2_internal == nullptr) {
    subtitle_label_row_2_internal = new QLabel();
  }
  subtitle_label_row_2_internal->setProperty("class",
    "app_bar_subtitle_label");
  subtitle_label_row_2_internal->setText(config_.subtitle);
  if (config_.subtitle.isEmpty()) {
    subtitle_label_row_2_internal->hide();
  }
  titles_row_2_layout_internal->addWidget(subtitle_label_row_2_internal);
}

AppBar::~AppBar() {
  qInfo() << "[ OK ] M3QW AppBar: App Bar is being deleted.";
}

AppBarConfig AppBar::GetConfig() {
  return config_;
}

QString AppBar::GetTitle() {
  return config_.title;
}

void AppBar::SetTitle(const QString &title) {
  config_.title = title;
  if (title_label_row_1_internal != nullptr) {
    title_label_row_1_internal->setText(title);
  }
  if (title_label_row_2_internal != nullptr) {
    title_label_row_2_internal->setText(title);
  }
}

QString AppBar::GetSubtitle() {
  return config_.subtitle;
}

void AppBar::SetSubtitle(const QString &subtitle) {
  config_.subtitle = subtitle;
  if (subtitle_label_row_1_internal != nullptr) {
    subtitle_label_row_1_internal->setText(subtitle);
  }
  if (subtitle_label_row_2_internal != nullptr) {
    subtitle_label_row_2_internal->setText(subtitle);
  }
  if (config_.subtitle.isEmpty()) {
    subtitle_label_row_1_internal->hide();
    subtitle_label_row_2_internal->hide();
  }
}

}  // namespace components
}  // namespace m3qw
