cmake_minimum_required(VERSION 3.18.0)

project(mpi_examples)

find_package(MPI REQUIRED)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
include_directories(${MPI_INCLUDE_PATH})

file (GLOB SRCS *.c)
foreach(src_path ${SRCS})
  get_filename_component(exe ${src_path} NAME_WE)
  message(STATUS "${exe}")
  add_executable(${exe} ${src_path})
  target_link_libraries(${exe} ${MPI_LIBRARIES})
endforeach(src ${SRCS})
