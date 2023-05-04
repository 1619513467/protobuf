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

    "msg_business.pb.h"
    "msg_business.pb.cc"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    gmock
    gmock_main
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    absl_bad_any_cast_impl
    absl_bad_optional_access
    absl_bad_variant_access
    absl_base
    absl_city
    absl_civil_time
    absl_cord_internal
    absl_cord
    absl_cordz_functions
    absl_cordz_handle
    absl_cordz_info
    absl_cordz_sample_token
    absl_crc_cord_state
    absl_crc_cpu_detect
    absl_crc_internal
    absl_crc32c
    absl_debugging_internal
    absl_demangle_internal
    absl_die_if_null
    absl_examine_stack
    absl_exponential_biased
    absl_failure_signal_handler
    absl_flags_commandlineflag_internal
    absl_flags_commandlineflag
    absl_flags_config
    absl_flags_internal
    absl_flags_marshalling
    absl_flags_parse
    absl_flags_private_handle_accessor
    absl_flags_program_name
    absl_flags_reflection
    absl_flags_usage_internal
    absl_flags_usage
    absl_flags
    absl_graphcycles_internal
    absl_hash
    absl_hashtablez_sampler
    absl_int128
    absl_kernel_timeout_internal
    absl_leak_check
    absl_log_entry
    absl_log_flags
    absl_log_globals
    absl_log_initialize
    absl_log_internal_check_op
    absl_log_internal_conditions
    absl_log_internal_format
    absl_log_internal_globals
    absl_log_internal_log_sink_set
    absl_log_internal_message
    absl_log_internal_nullguard
    absl_log_internal_proto
    absl_log_severity
    absl_log_sink
    absl_low_level_hash
    absl_malloc_internal
    absl_periodic_sampler
    absl_random_distributions
    absl_random_internal_distribution_test_util
    absl_random_internal_platform
    absl_random_internal_pool_urbg
    absl_random_internal_randen_hwaes_impl
    absl_random_internal_randen_hwaes
    absl_random_internal_randen_slow
    absl_random_internal_randen
    absl_random_internal_seed_material
    absl_random_seed_gen_exception
    absl_random_seed_sequences
    absl_raw_hash_set
    absl_raw_logging_internal
    absl_scoped_set_env
    absl_spinlock_wait
    absl_stacktrace
    absl_status
    absl_statusor
    absl_str_format_internal
    absl_strerror
    absl_strings_internal
    absl_strings
    absl_symbolize
    absl_synchronization
    absl_throw_delegate
    absl_time_zone
    absl_time
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