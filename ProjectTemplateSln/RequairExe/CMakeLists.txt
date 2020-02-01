# CMakeLists for Requair executable 

cmake_minimum_required (VERSION 3.8)

add_executable(RequairExe 
  "source/main.cpp"
)

target_link_libraries(RequairExe PRIVATE Requair)

# Include own header files
target_include_directories(RequairExe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)