set(CMAKE_CXX_STANDARD 20)

project(module_cross_fade_lod)

file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

add_subdirectory(entt)
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)
