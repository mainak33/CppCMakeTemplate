# Add headers for Version
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/demolibVersion.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/demolib/demolibVersion.h")

# Headers and Sources
# Globs are not recommended by CMake, but the following may be used if they are to be used
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
# file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set (SOURCE_LIST 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/demolib.cpp")

set (HEADER_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/include/demolib/demolib.h")


# Make an automatic library - will be static or dynamic based on user setting
add_library(demolib "${SOURCE_LIST}" "${HEADER_LIST}")

add_library(demolib::demolib ALIAS demolib) 

# Make the headers public
set_target_properties(demolib PROPERTIES 
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      )


target_include_directories(demolib PUBLIC 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/demolib>)  

install(TARGETS demolib
        EXPORT demolibTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT demolibTargets
        FILE demolibTargets.cmake
        NAMESPACE demolib::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/demolib")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/demolib"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/demolib"
        FILES_MATCHING PATTERN "*.h*")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/demolibConfigVersion.cmake"
    VERSION ${demolib_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/demolibConfig.cmake"
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/demolibConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/demolib")

