# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "src\\RcfClient\\CMakeFiles\\RcfClient_autogen.dir\\AutogenUsed.txt"
  "src\\RcfClient\\CMakeFiles\\RcfClient_autogen.dir\\ParseCache.txt"
  "src\\RcfClient\\RcfClient_autogen"
  "src\\RcfServer\\CMakeFiles\\RcfServer_autogen.dir\\AutogenUsed.txt"
  "src\\RcfServer\\CMakeFiles\\RcfServer_autogen.dir\\ParseCache.txt"
  "src\\RcfServer\\RcfServer_autogen"
  )
endif()
