# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\GUI_BIBLIOTECA_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GUI_BIBLIOTECA_autogen.dir\\ParseCache.txt"
  "GUI_BIBLIOTECA_autogen"
  )
endif()
