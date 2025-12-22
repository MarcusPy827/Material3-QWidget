cmake_minimum_required(VERSION 3.16)

project(M3QWExample VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories(${CMAKE_SOURCE_DIR})

set(TS_FILES 
  locales/examples_zh_CN.ts
)

set(PROJECT_SOURCES
  ${TS_FILES}
  main/main.cc
  main_window/mainwindow.h
  main_window/mainwindow.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(M3QWExample MANUAL_FINALIZATION ${PROJECT_SOURCES})
  qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
  if(ANDROID)
    add_library(M3QWExample SHARED ${PROJECT_SOURCES})
  else()
    add_executable(M3QWExample ${PROJECT_SOURCES})
  endif()

  qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(M3QWExample PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.M3QWExample)
endif()
set_target_properties(M3QWExample PROPERTIES
  ${BUNDLE_ID_OPTION}
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS M3QWExample
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(M3QWExample)
endif()

target_include_directories(M3QWExample PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(M3QWExample PRIVATE 
  Material3QWControl
)
