cmake_minimum_required(VERSION 3.9)
project(TimTex)
SET(PACKAGE_NAME TimTex)
SET(PACKAGE_VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "-lboost_system -lboost_filesystem")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
find_package(Boost REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(POPPL poppler-cpp)
pkg_check_modules(CAIRO cairo)
pkg_check_modules(PANGO pango)

add_subdirectory(src)

ADD_DEFINITIONS(-DPACKAGE_NAME=\"${PACKAGE_NAME}\")
ADD_DEFINITIONS(-DPACKAGE_VERSION=\"${PACKAGE_VERSION}\")
