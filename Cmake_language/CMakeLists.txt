# project(MyProject VERSION 1.2.3.4 LANGUAGES C CXX)

# # Запустить скрипт `MyCMakeScript.cmake` на выполнение:
# include(MyCMakeScript.cmake)

# # Скомпилировать статическую библиотеку "MyLibrary" из
# # исходников "ObjectHandler.c", "TimeManager.c" и "MessageConsumer.c":
# add_library(MyLibrary STATIC ObjectHandler.c TimeManager.c MessageConsumer.c)
# # Статические библиотеки задаются ключевым словом STATIC вторым аргументом и представляют из себя архивы объектных файлов, связываемых с исполняемыми файлами и другими библиотеками во время компиляции;
# # Динамические библиотеки задаются ключевым словом SHARED вторым аргументом и представляют из себя двоичные библиотеки, загружаемые операционной системой во время выполнения программы;
# # Модульные библиотеки задаются ключевым словом MODULE вторым аргументом и представляют из себя двоичные библиотеки, загружаемые посредством техник выполнения самим исполняемым файлом;
# # Объектные библиотеки задаются ключевым словом OBJECT вторым аргументом и представляют из себя набор объектных файлов, связываемых с исполняемыми файлами и другими библиотеками во время компиляции.

# # Блок 1
# # Задать исполняемый файл "MyExecutable" из исходников
# # "ObjectPrinter.c" и "SystemEvaluator.c":
# add_executable(MyExecutable ObjectPrinter.c SystemEvaluator.c)
# # Добавить к цели "MyExecutable" исходник "MessageConsumer.c":
# target_sources(MyExecutable MessageConsumer.c)
# # Добавить к цели "MyExecutable" исходник "ResultHandler.c":
# target_sources(MyExecutable ResultHandler.c)

# # Блок 2 (аналогичен блоку 1)
# # Аналогично сдедующему: Задать исполняемый файл "MyExecutable" из исходников
# # "ObjectPrinter.c", "SystemEvaluator.c", "MessageConsumer.c" и "ResultHandler.c":
# add_executable(MyExecutable ObjectPrinter.c SystemEvaluator.c MessageConsumer.c
# ResultHandler.c)

# # Скомпилировать исполняемый файл "MyExecutable" из
# # исходников "ObjectHandler.c", "TimeManager.c" и "MessageGenerator.c":
# add_executable(MyExecutable ObjectHandler.c TimeManager.c MessageGenerator.c)

## check CMake version 
cmake_minimum_required(VERSION 2.8)

## project parameters
project(test)

# Добавить в сборку исполняемый файл "MyProgram":
# add_executable(MyProgram StartProgram.c)
# add_executable(myprog ${SOURCE_EXE})

# Требовать обработку файла "core/CMakeFiles.txt":
# add_subdirectory(core)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB my_lib.cpp)
set(SOURCE_LIB_BYE my_lib_bye.cpp)

# Добавить в сборку исполняемый файл "MyProgram":
# add_executable(MyProgram StartProgram.c)
add_executable(myprog ${SOURCE_EXE})

# Добавить в сборку статическую библиотеку:
add_library(my_lib STATIC ${SOURCE_LIB})
add_library(my_lib_bye STATIC ${SOURCE_LIB_BYE})

# Скомпоновать исполняемый файл "MyProgram" со
# скомпилированной статической библиотекой "MyProgramCore":
target_link_libraries(myprog my_lib my_lib_bye)

# Установить исполняемый файл "MyProgram" в директорию "bin":
install(TARGETS myprog DESTINATION /home/test/dest)






## messages
message("\nmessages:")
message("Hello " "CMake" "!")
message(Next  ; example)

## comments

## variables
message("\nvariables:")
set(VAR "Superuser") # set variable
message("Username is " ${VAR}) # use variable
message("Undefined variable is " ${UNDEF_VAR}) # use undefined variable
unset(VAR) # unset variable

## options: opiont(NAME "Description" ON/OFF)
message("\noptions:")
option(INIT_BY_STARTUP "Is initialization will done by start?" ON)

## condition operators
message("\ncondition operators")
if (1 LESS 5)
    message("Of course 1 < 5")
elseif(1 GREATER 5) 
    message("1 > 5")
else()
    message("Oh no, 1 == 5!")
endif()

## cycle while
message("\ncycle while:")
set(NUMBER 1)
while(${NUMBER} LESS 4)
    message("Number = " ${NUMBER})
    MATH(EXPR NUMBER "${NUMBER} + 1")
endwhile()

## cycle foreach strings
message("\ncycle foreach strings:")
foreach(VAR Give me every word!) # separarte by space
    message(${VAR})
endforeach()

## cycle foreach numeric
message("\ncycle foreach numeric every from start:")
foreach(VAR RANGE 5) 
    message(${VAR})
endforeach()

message("\ncycle foreach numeric every from value:")
foreach(VAR RANGE 2 5) 
    message(${VAR})
endforeach()

message("\ncycle foreach numeric every from value with step:")
foreach(VAR RANGE 1 7 2) 
    message(${VAR})
endforeach()

## function
message("\nfunctions:")
function(print_add ARG1 ARG2)
    set(SUM 0)
    MATH(EXPR SUM "${ARG1} + ${ARG2}")
    message("Sum=" ${SUM})
endfunction()
print_add(2 3)

## macro
macro(print_str ARG)
        message(${ARG})
endmacro()
print_str("HELLO CMAKE HEY")

## parse arguments in function
message("\nparse arguments in function:")
function(custom_function)
    # Вызвать механизм обработки аргументов для текущей функции:
    cmake_parse_arguments(CUSTOM_FUNCTION "LOW;HIGH" "NUMBER" "COLORS" ${ARGV})

    # Напечатает "'LOW' = [TRUE]":
    message("'LOW' = [${CUSTOM_FUNCTION_LOW}]")
    #Напечатает "'HIGH' = [FALSE]":
    message("'HIGH' = [${CUSTOM_FUNCTION_HIGH}]")
    # Напечатает "'NUMBER' = [30]":
    message("'NUMBER' = [${CUSTOM_FUNCTION_NUMBER}]")
    # Напечатает "'COLORS' = [red;green;blue]":
    message("'COLORS' = [${CUSTOM_FUNCTION_COLORS}]")
endfunction()

# Вызвать функцию "custom_function" с произвольными аргументами:
custom_function(LOW NUMBER 30 COLORS red green blue)

## variables visibility
message("\nvariable visiblity:")
function(set_variable_in_parent)
    set(VAR2 "Parent_var_value" PARENT_SCOPE)
endfunction()
set_variable_in_parent()
message("Parent scope var is " ${VAR2})
