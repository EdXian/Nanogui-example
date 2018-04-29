cmake_minimum_required (VERSION 3.8)
project ("guitest")
set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)


add_subdirectory(ext/nanogui)
set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")


include_directories(  ext/nanogui/include/nanogui  
			ext/nanogui/include

 )
add_definitions(${NANOGUI_EXTRA_DEFS})


include_directories(${NANOGUI_EXTRA_INCS})


add_executable( gui2  gui2.cpp   )
target_link_libraries(gui2 nanogui ${NANOGUI_EXTRA_LIBS})


add_executable( gui1  gui1.cpp   )
target_link_libraries(gui1 nanogui ${NANOGUI_EXTRA_LIBS})


add_executable( gui3  gui3.cpp   )
target_link_libraries(gui3 nanogui ${NANOGUI_EXTRA_LIBS})

add_executable( gui4  gui4.cpp   )
target_link_libraries(gui4 nanogui ${NANOGUI_EXTRA_LIBS})



set(CPACK_PACKAGE_NAME "gui")
set(CPACK_PACKAGE_VENDOR "edxian.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "gui example")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "gui")
set(CPACK_NSIS_MODIFY_PATH ON)
#set(CPACK_GENERATOR WIX)
include(CPack)
