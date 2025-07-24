# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Timers_default_library_list )

# Handle files with suffix s, for group default-XC32
if(Timers_default_default_XC32_FILE_TYPE_assemble)
add_library(Timers_default_default_XC32_assemble OBJECT ${Timers_default_default_XC32_FILE_TYPE_assemble})
    Timers_default_default_XC32_assemble_rule(Timers_default_default_XC32_assemble)
    list(APPEND Timers_default_library_list "$<TARGET_OBJECTS:Timers_default_default_XC32_assemble>")
endif()

# Handle files with suffix S, for group default-XC32
if(Timers_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(Timers_default_default_XC32_assembleWithPreprocess OBJECT ${Timers_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    Timers_default_default_XC32_assembleWithPreprocess_rule(Timers_default_default_XC32_assembleWithPreprocess)
    list(APPEND Timers_default_library_list "$<TARGET_OBJECTS:Timers_default_default_XC32_assembleWithPreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC32
if(Timers_default_default_XC32_FILE_TYPE_compile)
add_library(Timers_default_default_XC32_compile OBJECT ${Timers_default_default_XC32_FILE_TYPE_compile})
    Timers_default_default_XC32_compile_rule(Timers_default_default_XC32_compile)
    list(APPEND Timers_default_library_list "$<TARGET_OBJECTS:Timers_default_default_XC32_compile>")
endif()

# Handle files with suffix cpp, for group default-XC32
if(Timers_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(Timers_default_default_XC32_compile_cpp OBJECT ${Timers_default_default_XC32_FILE_TYPE_compile_cpp})
    Timers_default_default_XC32_compile_cpp_rule(Timers_default_default_XC32_compile_cpp)
    list(APPEND Timers_default_library_list "$<TARGET_OBJECTS:Timers_default_default_XC32_compile_cpp>")
endif()


add_executable(${Timers_default_image_name} ${Timers_default_library_list})
set_target_properties(${Timers_default_image_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${Timers_default_output_dir})

target_link_libraries(${Timers_default_image_name} PRIVATE ${Timers_default_default_XC32_FILE_TYPE_link})

# Add the link options from the rule file.
Timers_default_link_rule(${Timers_default_image_name})

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex Timers_default_image_name_hex ${Timers_default_image_name})
add_custom_target(Timers_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} ${Timers_default_output_dir}/${Timers_default_image_name}
    BYPRODUCTS ${Timers_default_output_dir}/${Timers_default_image_name_hex}
    COMMENT Convert built file to .hex)
add_dependencies(Timers_default_Bin2Hex ${Timers_default_image_name})



