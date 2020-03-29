
add_executable(fuzz_my_project fuzz_my_project.cxx)

set_target_properties(fuzz_my_project
        PROPERTIES
        COMPILE_FLAGS "-fsanitize=fuzzer"
        LINK_FLAGS "-fsanitize=fuzzer")

target_link_libraries(fuzz_my_project
        PRIVATE
        ${PROJECT_NAME}
        )