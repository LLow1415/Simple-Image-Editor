cmake_minimum_required(VERSION 4.4)
find_package(PkgConfig REQUIRED)
pkg_check_modules(IMAGEMAGICK REQUIRED Magick++)

# Add your executable
add_executable(meme main.cpp)

# Link flags, include directories, and preprocessor definitions automatically
target_link_libraries(meme PRIVATE ${IMAGEMAGICK_LIBRARIES})
target_include_directories(meme PRIVATE ${IMAGEMAGICK_INCLUDE_DIRS})
target_compile_options(meme PRIVATE ${IMAGEMAGICK_CFLAGS_OTHER})
