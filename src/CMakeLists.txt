include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Security/Nonce/Api/ErrorCode.cpp
        "../public/PiSubmarine/Security/Nonce/Api/ErrorCode.h"
        "../public/PiSubmarine/Security/Api/INonceProvider.h"
        "../public/PiSubmarine/Security/Api/Nonce.h")
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Error.Api)
