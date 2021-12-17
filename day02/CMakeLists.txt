cmake_minimum_required(VERSION 3.5)

project(day02)

set(CMAKE_CXX_STANDARD 20)


add_executable(out day02.cpp)
# add_executable(out benchmark.cpp mtests.cpp mtests.hh tests.cpp tests.hh)
# add_executable(out presentation.cpp mtests.cpp mtests.hh tests.cpp tests.hh)

# Declare dependency on the absl libraries
# target_link_libraries(out absl::flat_hash_map absl::flat_hash_set absl::node_hash_set benchmark::benchmark)
