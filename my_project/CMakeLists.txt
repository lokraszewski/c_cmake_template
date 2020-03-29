
add_executable(${PROJECT_NAME}_app src/main.c)

target_link_libraries(${PROJECT_NAME}_app PUBLIC ${PROJECT_NAME})