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


add_executable( gui  main.cpp   )


target_link_libraries(gui nanogui ${NANOGUI_EXTRA_LIBS})


