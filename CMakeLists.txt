cmake_minimum_required(VERSION 3.16)

################# Disallow in-source build #################
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
   message(FATAL_ERROR "plasma requires an out of source build. Please create a separate build directory and run 'cmake path_to_plasma [options]' there.")
endif()

set(PROJECT_VERSION "1.0")
set(PROJECT_VERSION_MAJOR 1)

set(QT_MIN_VERSION 5.15.0)
set(KF5_MIN_VERSION 5.79.0)


### PLUGIN
project(dtplugin)

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(KDEInstallDirs)
include(KDECMakeSettings)

set(SRC_LIST
	plugin/dtplugin.cpp
	plugin/dirtreemodel.cpp
	)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED
	Core
	Quick
	Qml
	)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
	KIO
	)

set_source_files_properties( qmltypes PROPERTIES GENERATED true)
add_custom_command(OUTPUT qmltypes
	COMMAND qmlplugindump -nonrelocatable com.github.tilorenz.dtplugin 1.0 > plugins.qmltypes
	WORKING_DIRECTORY ${CMAKE_BUILD_DIR} )

# add the executable
#add_library(${PROJECT_NAME} SHARED ${SRC_LIST} qmltypes)
add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

target_link_libraries(${PROJECT_NAME}
	Qt::Quick
	KF5::KIOWidgets
	)

install(TARGETS ${PROJECT_NAME} DESTINATION /usr/lib/qt/qml/com/github/tilorenz/${PROJECT_NAME})
install(FILES plugin/qmldir DESTINATION /usr/lib/qt/qml/com/github/tilorenz/${PROJECT_NAME})
#install(FILES build/plugins.qmltypes DESTINATION /usr/lib/qt/qml/com/github/tilorenz/${PROJECT_NAME})
