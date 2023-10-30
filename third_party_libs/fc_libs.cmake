include(fetchcontent)

# Jinja also includes libfmt
FetchContent_Declare(
        Jinja2Cpp
        GIT_REPOSITORY https://github.com/jinja2cpp/Jinja2Cpp.git
        GIT_TAG        master
)

FetchContent_Declare(
        SQLiteCpp
        GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
        GIT_TAG        master
)

FetchContent_Declare(
        httplib
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(
        Jinja2Cpp
        SQLiteCpp
        httplib
)


