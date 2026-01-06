set(LIB_SOURCES
  ${CMAKE_SOURCE_DIR}/res/resources.qrc
  interfaces/color_palette.h
  theme_loader/default_palette.h
  theme_loader/theme_conf.h
  theme_loader/theme_loader.h
  theme_loader/theme_loader.cc
  utils/utils.h
  utils/utils.cc
  utils/icon_variant.h
  components/app_bar/app_bar.h
  components/app_bar/app_bar.cc
  components/app_bar/app_bar_icon_btn.h
  components/app_bar/app_bar_icon_btn.cc
  components/buttons/icon_buttons.h
  components/buttons/icon_buttons.cc
  font_loader/font_loader.h
  font_loader/font_loader.cc
)

add_library(Material3QWControl SHARED ${LIB_SOURCES})
target_link_libraries(Material3QWControl 
  PRIVATE 
  Qt${QT_MAJOR_VERSION}::Widgets
)

target_link_libraries(Material3QWControl 
  PUBLIC 
  Qt${QT_MAJOR_VERSION}::Widgets
)

target_include_directories(Material3QWControl PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS Material3QWControl
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Material3QWControl.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})