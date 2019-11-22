# CMake Settings
cmake_minimum_required(VERSION 3.1.0)
# CMake Include
message( "***************************break line**********************************" )
# CMake Include
include("recursive_search.cmake")
include("choose_qt_sdk.cmake")
# CMake Find Package Path
if( NOT DEFINED CMAKE_PREFIX_PATH )
    CHOOSE_QT_SDK( QT_MSVC2015_32 )
else()
    message( "CMAKE_PREFIX_PATH from env: " ${CMAKE_PREFIX_PATH} )
endif( NOT DEFINED CMAKE_PREFIX_PATH )
set(CMAKE_BUILD_TYPE Debug)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# CMake moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
#CMake rcc automatically( handle qrc file )
set(CMAKE_AUTORCC ON)

# Solution Settings
project(Solution)

# set(<variable> <value>
#    [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE])
set( project_name QmlStandard )
message( "Project name is: " ${project_name} )

# Definitions
IF(WIN32)
  message( "WIN32." )
  SET(OS_PREFIX winnt_x86)
  IF(MSVC)
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DQT_QML_DEBUG ")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCMAKE_BUILD_TYPE=Debug ")
   add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
   add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  ENDIF() 
  
ELSE()

ENDIF()

IF(WIN64)
  message( "WIN64." )
ENDIF()
# Find the QtWidgets library
find_package( Qt5 REQUIRED 
# QuickWidgets means CMake would search for ".\lib\cmake\Qt5QuickWidgetsConfig.cmake"
    COMPONENTS Core Gui Widgets Qml Quick QuickWidgets QuickControls2 Network
)

include_directories(
# Qt5::Core means there is ".\include\QtCore""
    Qt5::Core   
    Qt5::Gui
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickWidgets
    Qt5::QuickControls2
    Qt5::Network
)

# Populate a CMake variable with the sources
FILE(GLOB project_sources
    main.cpp
    controllerwindow.cpp
    #sub test widget
    qwidgetbase.cpp
    qdialogsub.cpp
    qwidgetsub.cpp
    qwidgetfiledir.cpp
    #
    qthreadsub.cpp
    qcheckboxthread.cpp
    qcheckboxlayout.cpp
    qcheckboxtimer.cpp
)

FILE(GLOB project_headers
    *.h
)

SET( project_resources 
    choose_qt_sdk.cmake
    recursive_search.cmake
)

#Same type together
SOURCE_GROUP("Source Files" FILES ${project_sources})
SOURCE_GROUP("Header Files" FILES ${project_headers})
SOURCE_GROUP("Resource Files" FILES ${project_resources})

# mark as startup project
IF(WIN32 AND MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${project_name})
ENDIF()

# Tell CMake to create the project executable
add_executable( ${project_name} WIN32 ${project_sources} ${project_headers} ${project_resources})

# Output Path
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
# MESSAGE(STATUS "EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH} )
# set_target_properties(target1 target2 ...PROPERTIES prop1 value1 prop2 value2 ...)
# Output Path
set_target_properties( ${project_name}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)
# Output Name
SET_TARGET_PROPERTIES( ${project_name} PROPERTIES OUTPUT_NAME "posconfig")
# get_target_property
get_target_property(QtCore_location Qt5::Core LOCATION)
MESSAGE(STATUS "This is QtCore_location " ${QtCore_location})

# Must After add_executable
target_link_libraries( ${project_name}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Qml_LIBRARIES}
    ${Qt5Quick_LIBRARIES}
    ${Qt5QuickWidgets_LIBRARIES}
    ${Qt5QuickControls2_LIBRARIES}
    ${Qt5Network_LIBRARIES}
)

#Message Sln Path
MESSAGE(STATUS "Message:" )
MESSAGE(STATUS "This is BINARY dir " ${Solution_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${Solution_SOURCE_DIR})
#Message Qt Path
MESSAGE(STATUS "Message:" )
MESSAGE(STATUS "This is Qt5Widgets_INCLUDE_DIRS " ${Qt5Widgets_INCLUDE_DIRS})
MESSAGE(STATUS "This is Qt5Widgets_LIBRARIES " ${Qt5Widgets_LIBRARIES})
MESSAGE(STATUS "This is Qt5Qml_INCLUDE_DIRS " ${Qt5Qml_INCLUDE_DIRS})
