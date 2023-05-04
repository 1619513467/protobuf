# CMakeList.txt: Protobuf 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project ("Protobuf")


set(CMAKE_AUTOMOC ON)	# 针对信号和槽 帮助我们处理，含有信号和槽的源文件
set(CMAKE_AUTOUIC ON)	# 针对UI文件
set(CMAKE_AUTORCC ON)	# 针对图片的打包
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} 
	"Protobuf.cpp"
	"Protobuf.h"
)

link_directories(${CMAKE_SOURCE_DIR}/3dparty/lib/)
target_link_libraries(${PROJECT_NAME} PRIVATE
    gmock
    gmock_main
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} PRIVATE
        libprotobufd
        libprotobuf-lited
        libprotocd
    )
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE 
        libprotobuf
        libprotobuf-lite
        libprotoc
    )
endif()

find_package(Qt5 COMPONENTS Core Widgets Network)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Protobuf PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
