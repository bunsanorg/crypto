cmake_minimum_required(VERSION 3.0)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

project(bunsan_crypto)

if(BunsanCMakeBuiltin)
    BunsanCMakeLoad()
else()
    find_package(BunsanCMake CONFIG REQUIRED)
endif()

bunsan_add_library(${PROJECT_NAME}
    src/base64.cpp
)
bunsan_use_bunsan_package(${PROJECT_NAME} bunsan_common bunsan_common)
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_project()

bunsan_include_tests()
