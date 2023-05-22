if (APPLE)

    #Create directories
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD 
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/MacOS"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Frameworks"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources"
    )

    #Copy important stuff
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/MacOS"
        COMMAND ${CMAKE_COMMAND} -E copy ${RAYLIB_LIBS} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Frameworks"
    )

endif()
