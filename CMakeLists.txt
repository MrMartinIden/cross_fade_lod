project(module_cross_fade_lod)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

add_subdirectory(entt)
target_link_libraries(${PROJECT_NAME} PUBLIC EnTT::EnTT)
