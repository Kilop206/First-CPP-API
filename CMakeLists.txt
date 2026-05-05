cmake_minimum_required(VERSION 3.16)
project(cpp_api)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.15.3
)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(httplib json)

add_executable(cpp_api
    src/main.cpp
    src/routes/routes.cpp
    src/controllers/UserController.cpp
    src/services/UserService.cpp
    src/models/User.cpp
    src/utils/JsonResponse.cpp
)

target_include_directories(cpp_api PRIVATE include ${httplib_SOURCE_DIR})
target_link_libraries(cpp_api PRIVATE nlohmann_json::nlohmann_json)