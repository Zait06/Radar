cmake_minimum_required(VERSION 3.16)

project(desktop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick SerialPort Qml QmlIntegration Core Widgets)

qt_standard_project_setup()

qt_add_executable(appdesktop
    main.cpp
)

qt_add_qml_module(
    appdesktop
    URI desktop
    VERSION 1.0
    RESOURCE_PREFIX /
    NO_PLUGIN
    QML_FILES
        Main.qml
        qml/components/Radar.qml
    SOURCES
        src/SerialCom.cpp
)

set_target_properties(appdesktop PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(appdesktop
    PRIVATE Qt6::Quick
    Qt6::SerialPort
    Qt6::Qml
    Qt6::QmlIntegration
    Qt6::Core
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS appdesktop
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(
    appdesktop
    INTERFACE src
    PRIVATE
    src
)