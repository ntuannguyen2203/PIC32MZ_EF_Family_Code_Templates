# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "C:/Users/ntuan/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(Timers_default_default_XC32_assemble_rule target)
    set(options
        "-g"
        "${ASSEMBLER_PRE}"
        "-mprocessor=32MZ2048EFM144"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-I${CMAKE_CURRENT_SOURCE_DIR}/../../.."
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MZ-EF_DFP/1.5.173")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Timers_default_default_XC32_assembleWithPreprocess_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "-g"
        "${MP_EXTRA_AS_PRE}"
        "-mprocessor=32MZ2048EFM144"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},-I${CMAKE_CURRENT_SOURCE_DIR}/../../..")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Timers_default_default_XC32_compile_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-x"
        "c"
        "-c"
        "-mprocessor=32MZ2048EFM144"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MZ-EF_DFP/1.5.173")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__MPLAB_DEBUGGER_SIMULATOR=1"
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Timers_default_default_XC32_compile_cpp_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-mprocessor=32MZ2048EFM144"
        "-frtti"
        "-fexceptions"
        "-fno-check-new"
        "-fenforce-eh-specs"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MZ-EF_DFP/1.5.173")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Timers_default_link_rule target)
    set(options
        "-g"
        "${MP_EXTRA_LD_PRE}"
        "-mprocessor=32MZ2048EFM144"
        "-Wl,--defsym=__MPLAB_BUILD=1${MP_EXTRA_LD_POST},--no-code-in-dinit,--no-dinit-in-serial-mem,-L${CMAKE_CURRENT_SOURCE_DIR}/../../..,--memorysummary,memoryfile.xml"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MZ-EF_DFP/1.5.173")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
