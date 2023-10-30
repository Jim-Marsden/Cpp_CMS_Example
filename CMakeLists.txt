cmake_minimum_required(VERSION 3.26)
project(website_server_tests)
include(third_party_libs/fc_libs.cmake)
set(CMAKE_CXX_STANDARD 23)

add_executable(website_server_tests
        src/main.cpp)
target_link_libraries(website_server_tests PRIVATE fmt::fmt SQLiteCpp jinja2cpp httplib)

file(COPY "html/body_template.html" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/html")
