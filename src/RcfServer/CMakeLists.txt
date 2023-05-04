# CMakeList.txt: CMakeProjectTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project("RcfServer")

set(CMAKE_AUTOMOC ON)	# 针对信号和槽 帮助我们处理，含有信号和槽的源文件
set(CMAKE_AUTOUIC ON)	# 针对UI文件
set(CMAKE_AUTORCC ON)	# 针对图片的打包
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(absl_DIR "E:\\Project_CMake\\CMakeProjectTest\\3dparty\\lib\\install\\lib\\cmake\\absl\\")
#find_package(absl REQUIRED)
link_directories(${CMAKE_SOURCE_DIR}/3dparty/google/protobuf/lib/)
link_directories(${CMAKE_SOURCE_DIR}/3dparty/lib/)
link_directories(${CMAKE_SOURCE_DIR}/3dparty/lib/absl)

# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} WIN32
    "main.cpp"
    "rcfserver.h"
    "rcfserver.cpp"
    "rcfserver.ui"
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
   set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
# TODO: 如有需要，请添加测试并安装目标。

find_package(Qt5 COMPONENTS Core Widgets Network)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)


if(MSVC)     
    # Use the static C library for all build types
    foreach(var 
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
      )
      if(${var} MATCHES "/MD")
        # 正则表达式替换/MD为/MT
        string(REGEX REPLACE "/MD" "/MT" ${var} "${${var}}")
      endif()
    endforeach()    
endif(MSVC)