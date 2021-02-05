
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

# Create executable, just in case
add_executable(${BINARY}_run ${SOURCES})

# Create static library, to be linked with tests
add_library(${BINARY}_lib STATIC ${SOURCES})

# Manually connect all the subdirectories
add_subdirectory(Arrays)
add_subdirectory(Search)