add_executable(console_agnostic_rl)

target_sources(console_agnostic_rl
    PRIVATE
        main.c
)

add_subdirectory(display_lib)


if(MSVC)
    target_compile_options(console_agnostic_rl PRIVATE /W4)
else()
    target_compile_options(console_agnostic_rl PRIVATE -Wall -Wextra -Wpedantic)
endif()

if (UNIX)
    target_link_libraries(console_agnostic_rl)
endif()

if (WIN32)
    target_link_libraries(console_agnostic_rl)
endif()

set_property(TARGET console_agnostic_rl PROPERTY C_STANDARD 23)
#set_property(TARGET console_agnostic_rl PROPERTY C_STANDARD 23)
