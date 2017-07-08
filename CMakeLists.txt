cmake_minimum_required(VERSION 3.0)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)
include(FindPkgConfig)

project(bunsan_crypto)

if(BunsanCMakeBuiltin)
    BunsanCMakeLoad()
else()
    find_package(BunsanCMake CONFIG REQUIRED)
endif()

bunsan_add_library(${PROJECT_NAME}
    src/base64.cpp
    src/checksum.cpp
)
bunsan_use_bunsan_package(${PROJECT_NAME} bunsan_common bunsan_common)

pkg_check_modules(BOTAN botan-2)
target_include_directories(${PROJECT_NAME} PUBLIC ${BOTAN_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${BOTAN_LIBRARIES})

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_project()

bunsan_include_tests()
