# for each "main/x.cpp", generate target "x"
file(GLOB_RECURSE all_srcs CONFIGURE_DEPENDS *.cpp)
foreach(v ${all_srcs})
    string(REGEX MATCH "main/.*" relative_path ${v})
    # message(${relative_path})
    string(REGEX REPLACE "main/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    add_executable(${target_name} ${v})
endforeach()