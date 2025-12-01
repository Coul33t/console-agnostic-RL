if (UNIX)
    target_sources(console_agnostic_rl
        PRIVATE
            display_lib_linux.c
    )
endif()

if (WIN32)
    target_sources(console_agnostic_rl
        PRIVATE
            display_lib_windows.c
    )
endif()
