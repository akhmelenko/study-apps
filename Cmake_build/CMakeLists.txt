
## check CMake version 
cmake_minimum_required(VERSION 2.8)

## project parameters
# project(test)

# Требовать обработку файла "core/CMakeFiles.txt":
# add_subdirectory(core)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB my_lib.cpp)
set(SOURCE_LIB_BYE my_lib_bye.cpp)

# Добавить в сборку исполняемый файл "MyProgram":
# add_executable(TestProgram main_test.cpp)

add_executable(myprog ${SOURCE_EXE})

# Добавить в сборку статическую библиотеку:
add_library(my_lib STATIC ${SOURCE_LIB})
add_library(my_lib_bye STATIC ${SOURCE_LIB_BYE})

# Скомпоновать исполняемый файл "MyProgram" со
# скомпилированной статической библиотекой "MyProgramCore":
target_link_libraries(myprog my_lib my_lib_bye)

# Установить исполняемый файл "MyProgram" в директорию "bin":
# install(TARGETS myprog DESTINATION /home/test/dest)




