cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
set(CMAKE_BUILD_TYPE Debug)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})


SET( o3dClientLib_SOURCE
    src/O3DClientLib/source/communication/clientsocket.cpp
    src/O3DClientLib/source/O3DClient.cpp    
    src/O3DClientLib/source/o3dCompleteData.cpp
    src/O3DClientLib/source/o3dCameraSettings.cpp
    src/O3DClientLib/source/o3dDataTypes.cpp
)

ADD_LIBRARY( o3dClientLib 
    ${o3dClientLib_SOURCE}
)


INCLUDE_DIRECTORIES(
	include/O3DClientLib/include
	include/O3DClientLib/include/communication
	${CMAKE_CURRENT_BINARY_DIR}
)

SET( SERVER_SOURCE
	src/pmdCamServer.cpp
	src/systemController.cpp
	src/system3d.cpp
)

#SET( GUI_SOURCE
#	src/pmdGUIview.cpp
#	src/pmdGUIcontroller.cpp
#	src/pmdGUImodel.cpp
#	src/qtros.cpp
#)

# add Qt library
FIND_PACKAGE(Qt4 REQUIRED)

#SET( GUI_HEADERS
#	include/pmdGUIview.hpp
#	include/qtros.h
#	include/pmdGUImodel.h
#)

#SET( GUI_FORMS
#	include/forms/window.ui
#)

SET( IFMoffline_SOURCE
	src/ifmoffline.cpp
	src/o3dcam.cpp
)

SET( IFMcam_SOURCE
	src/ifmcam.cpp
	src/o3dcam.cpp
)


#QT4_WRAP_CPP(GUI_HEADERS_MOC ${GUI_HEADERS})
#QT4_WRAP_UI(GUI_FORMS_HEADERS ${GUI_FORMS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

rosbuild_add_executable(IFMoffline ${IFMoffline_SOURCE})
rosbuild_add_executable(IFMcam ${IFMcam_SOURCE})
rosbuild_add_executable(pmdCamServer ${SERVER_SOURCE})
#rosbuild_add_executable(pmdGUI ${GUI_SOURCE} ${GUI_HEADERS_MOC} ${GUI_FORMS_HEADERS})

TARGET_LINK_LIBRARIES(IFMcam o3dClientLib)
TARGET_LINK_LIBRARIES(IFMoffline o3dClientLib)
TARGET_LINK_LIBRARIES(pmdCamServer)
#TARGET_LINK_LIBRARIES(pmdGUI ${QT_LIBRARIES})

# add boost libraries
rosbuild_add_boost_directories()
rosbuild_link_boost(o3dClientLib signals thread)




