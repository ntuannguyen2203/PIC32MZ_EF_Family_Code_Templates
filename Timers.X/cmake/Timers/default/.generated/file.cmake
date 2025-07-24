# The following variables contains the files used by the different stages of the build process.
set(Timers_default_default_XC32_FILE_TYPE_assemble)
set_source_files_properties(${Timers_default_default_XC32_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(Timers_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${Timers_default_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)
set(Timers_default_default_XC32_FILE_TYPE_compile "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c")
set_source_files_properties(${Timers_default_default_XC32_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Timers_default_default_XC32_FILE_TYPE_compile_cpp)
set_source_files_properties(${Timers_default_default_XC32_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(Timers_default_default_XC32_FILE_TYPE_link)
set(Timers_default_image_name "default.elf")


# The output directory of the final image.
set(Timers_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Timers")
