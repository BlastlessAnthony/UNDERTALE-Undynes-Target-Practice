if (APPLE)

    #Create directories
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD 
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/MacOS"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Frameworks"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources"
    )

    set(BUNDLE_PLIST_PATH "${PROJECT_ASSETS_DIR}/Darwin/Info.plist")
    set(BUNDLE_ICON_PATH "${PROJECT_ASSETS_DIR}/Darwin/Icon.icns")

    #Copy important stuff
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${BUNDLE_PLIST_PATH} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents"
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/MacOS"
        COMMAND ${CMAKE_COMMAND} -E copy ${RAYLIB_LIBS} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Frameworks"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_ASSETS} ${BUNDLE_ICON_PATH} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources"
    )

    

elseif (LINUX)

    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD 
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/bin"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/lib"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/share"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/share/res"
    )

    set(APPIMAGE_DESKTOP_PATH "${PROJECT_ASSETS_DIR}/Linux/Undyne's Target Practice.desktop")
    set(APPIMAGE_APPRUN_PATH "${PROJECT_ASSETS_DIR}/Linux/AppRun")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy ${APPIMAGE_DESKTOP_PATH} ${APPIMAGE_APPRUN_PATH} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir"
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/bin"
        COMMAND ${CMAKE_COMMAND} -E copy ${RAYLIB_LIBS} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/lib"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_ASSETS} "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir/usr/share/res"
    )

endif()
