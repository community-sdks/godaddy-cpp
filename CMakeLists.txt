cmake_minimum_required(VERSION 3.20)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")
endif()

project(godaddy_cpp LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(godaddy_cpp
    src/api_client.cpp
    src/client.cpp
    src/runtime/request.cpp
    src/runtime/response.cpp
    src/runtime/http_transport.cpp
    src/runtime/errors.cpp
    src/services/abuse_service.cpp
    src/services/aftermarket_service.cpp
    src/services/agreements_service.cpp
    src/services/ans_service.cpp
    src/services/auctions_service.cpp
    src/services/certificates_service.cpp
    src/services/countries_service.cpp
    src/services/domains_service.cpp
    src/services/orders_service.cpp
    src/services/parking_service.cpp
    src/services/shoppers_service.cpp
    src/services/subscriptions_service.cpp
)

target_include_directories(godaddy_cpp PUBLIC include)

add_executable(godaddy_cpp_tests
    tests/test_main.cpp
    tests/test_error_mapping.cpp
    tests/test_query_encoding.cpp
    tests/test_generated_services.cpp
)

target_link_libraries(godaddy_cpp_tests PRIVATE godaddy_cpp)

add_test(NAME godaddy_cpp_tests COMMAND godaddy_cpp_tests)
