# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
project ("Protobuf_Project")

set(Protobuf 1)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


include_directories(${CMAKE_SOURCE_DIR}/3dparty/include/)

# 包含子项目。
if(Protobuf)
	#add_subdirectory(${CMAKE_SOURCE_DIR}/src/Protobuf)
	add_subdirectory(${CMAKE_SOURCE_DIR}/src/RcfClient)
	add_subdirectory(${CMAKE_SOURCE_DIR}/src/RcfServer)
endif()
