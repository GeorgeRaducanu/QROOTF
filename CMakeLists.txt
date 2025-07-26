# Minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# Function to extract version string from header file
function(extract_version_from_header header_file)
    file(READ ${header_file} version_file_content)
    
    # Extract version string from QROOTF_VERSION_STRING
    string(REGEX MATCH "#define QROOTF_VERSION_STRING \"([0-9]+\\.[0-9]+\\.[0-9]+)\"" _ ${version_file_content})
    set(QROOTF_VERSION ${CMAKE_MATCH_1} PARENT_SCOPE)
endfunction()

# Extract version from header
extract_version_from_header(${CMAKE_CURRENT_SOURCE_DIR}/inc/version.h)

# Fallback if version extraction failed
if(NOT QROOTF_VERSION)
    set(QROOTF_VERSION "0.0.1")
endif()

# Extract major version for SOVERSION
string(REGEX MATCH "^([0-9]+)" QROOTF_VERSION_MAJOR_MATCH "${QROOTF_VERSION}")
set(QROOTF_VERSION_MAJOR ${CMAKE_MATCH_1})

project(qrootf VERSION ${QROOTF_VERSION} LANGUAGES C)

# Product metadata
set(QROOTF_PRODUCT_NAME "QROOTF - Quick Root Finder")
set(QROOTF_DESCRIPTION "A library and application for finding quickly roots of polynomials")

set (SOURCES
    src/qrootf.c
)
set (HEADERS
    inc/qrootf.h
    inc/version.h
)

set (CMAKE_C_STANDARD 99)
set (CMAKE_C_STANDARD_REQUIRED ON)

# Static library
add_library(qrootf_static STATIC ${SOURCES})
if (WIN32)
    target_sources(qrootf_static PRIVATE src/qrootf.rc)
    set_target_properties(qrootf_static PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()
target_include_directories(qrootf_static PUBLIC inc)
set_target_properties(qrootf_static PROPERTIES
    VERSION ${QROOTF_VERSION}
    SOVERSION ${QROOTF_VERSION_MAJOR}
    OUTPUT_NAME qrootf_static
)

# Dynamic library
add_library(qrootf_shared SHARED ${SOURCES})
if(WIN32)
    target_sources(qrootf_shared PRIVATE src/qrootf.rc)
    set_target_properties(qrootf_shared PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()
target_include_directories(qrootf_shared PUBLIC inc)
set_target_properties(qrootf_shared PROPERTIES
    VERSION ${QROOTF_VERSION}
    SOVERSION ${QROOTF_VERSION_MAJOR}
    OUTPUT_NAME qrootf
    DESCRIPTION "${QROOTF_DESCRIPTION}"
)

# Executable
add_executable(qrootf_exe src/main.c)
if(WIN32)
    target_sources(qrootf_exe PRIVATE src/qrootf.rc)
endif()
target_include_directories(qrootf_exe PUBLIC inc)
target_link_libraries(qrootf_exe qrootf_static)
set_target_properties(qrootf_exe PROPERTIES
    OUTPUT_NAME qrootf
)