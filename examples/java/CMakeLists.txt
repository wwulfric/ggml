cmake_minimum_required(VERSION 3.26)
project(jni_example)

set(CMAKE_CXX_STANDARD 11)

# use JAVA_HOME to find Java
set(JAVA_HOME $ENV{JAVA_HOME})

if (UNIX AND NOT APPLE)
    set(JAVA_INCLUDE_PATH ${JAVA_HOME}/include)
    set(JAVA_INCLUDE_PATH2 ${JAVA_HOME}/include/linux)
elseif (APPLE)
    set(JAVA_INCLUDE_PATH ${JAVA_HOME}/include)
    set(JAVA_INCLUDE_PATH2 ${JAVA_HOME}/include/darwin)
elseif (WIN32)
    set(JAVA_INCLUDE_PATH ${JAVA_HOME}/include)
    set(JAVA_INCLUDE_PATH2 ${JAVA_HOME}/include/win32)
endif()

include_directories(${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2})

#add_library(jni_example SHARED library.cpp library.h)

# 添加 C 文件
add_library(Hello SHARED NativeDemo.c)
target_link_libraries(Hello PRIVATE ggml common common-ggml)
add_custom_target(JavaCompile ALL
        COMMAND ${JAVA_HOME}/bin/javac -d ${CMAKE_BINARY_DIR}/examples/java ${CMAKE_SOURCE_DIR}/examples/java/*.java
        COMMENT "Compiling Java sources"
)
add_dependencies(JavaCompile Hello)