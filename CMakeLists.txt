#  _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
# /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
# \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
#  `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
# /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
# \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

cmake_minimum_required(VERSION 3.10.0)

project(main)

#determine whether running on 32 of 64 bit machine
set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

#set output exe locations
set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}-${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/staticLib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

#add subdirs
include_directories(src)

if (NOT TARGET src)
    add_subdirectory(src)
endif()

add_executable(${PROJECT_NAME} main.cpp)

#link dependencies from src
target_link_libraries(${PROJECT_NAME} SeatOccupancyDetector)