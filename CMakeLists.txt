cmake_minimum_required(VERSION 2.8.12)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(console_agnostic_rl CXX)

if (UNIX)
    
endif()

if (WIN32)

endif()

set (APP_SRC    src/main.cpp)

add_executable(console_agnostic_rl ${APP_SRC})

if(MSVC)
  target_compile_options(console_agnostic_rl PRIVATE /W4 /WX)
else()
  target_compile_options(console_agnostic_rl PRIVATE -Wall -Wextra -Wpedantic)
endif()

if (UNIX)
    target_link_libraries(console_agnostic_rl -lm)
endif()

if (WIN32)
    target_link_libraries(console_agnostic_rl)
endif()

set_property(TARGET console_agnostic_rl PROPERTY LINKER_LANGUAGE CXX)
#set_property(TARGET console_agnostic_rl PROPERTY C_STANDARD 23)
