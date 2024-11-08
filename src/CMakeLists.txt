#  _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
# /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
# \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
#  `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
# /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
# \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

cmake_minimum_required(VERSION 3.10.0)

project(SeatOccupancyDetector VERSION 0.1.0)

include_directories(include)

#adds src library named SeatOccupancyDetector as a library
add_library(${PROJECT_NAME} utils/Log.cpp)