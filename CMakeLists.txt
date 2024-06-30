cmake_minimum_required(VERSION 3.5)
project(uavcalc VERSION 0.1.0 LANGUAGES CXX)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

include_directories(include)

set(HEADER_FILES
        include/uavcalc/common/air.hpp
        include/uavcalc/parameters/reynolds_number.hpp
)

add_library(uavcalc
    ${HEADER_FILES}
    src/common/air.cpp 
    src/parameters/reynolds_number.cpp 
)

enable_testing()
add_subdirectory(test)

include(GNUInstallDirs)
install(TARGETS uavcalc
    EXPORT uavcalcTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT uavcalcTargets
    FILE uavcalcTargets.cmake
    NAMESPACE uavcalc::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uavcalc
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/uavcalcConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uavcalc
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uavcalc
)