cmake_minimum_required(VERSION 3.0)

project(mycpprest)

find_package(Boost REQUIRED COMPONENTS system thread log program_options chrono)
find_package(Threads REQUIRED)
find_package(OpenSSL 1.0.1 REQUIRED)
set(OPENSSL_VERSION "1.0.1")

message("-- configuring gcc options")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -DBOOST_LOG_DYN_LINK")

add_executable(${PROJECT_NAME}  ./src/main.cpp
                                ./src/controller/controller.cpp
                                ./src/controller/example_controller.cpp)

# header locations
set(CPPRESTSDK_INCLUDE_DIR "/usr/include")
set(CONTROLLER_INCLUDE_DIR "./src/controller")
set(HEADER_PATHS ${CPPRESTSDK_INCLUDE_DIR} ${CONTROLLER_INCLUDE_DIR} ${Boost_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})

# library paths
set(OPENSSL_LIBS "${OPENSSL_LIBRARIES}")
set(CPPRESTSDK_LIBRARY "-lcpprest")
set(LIBRARIES_SEARCH_PATHS ${CPPRESTSDK_LIBRARY} ${OPENSSL_LIBS} ${Boost_LIBRARIES})

message(BOOST_LIBS " ${Boost_LIBRARIES}")
message(OPENSSL_LIBRARIES " ${OPENSSL_LIBRARIES}")
message(CPPRESTSDK_LIBRARY " ${CPPRESTSDK_LIBRARY}")
message(LIBRARIES_SEARCH_PATHS " ${LIBRARIES_SEARCH_PATHS}")
message(CONTROLLER_INCLUDE_DIRECTORY " ${CONTROLLER_INCLUDE_DIRECTORY}")

include_directories(${HEADER_PATHS})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES_SEARCH_PATHS})