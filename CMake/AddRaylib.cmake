#Required in-general.
set(CUSTOMIZE_BUILD  ON CACHE BOOL "" FORCE)

#Graphics
set(SUPPORT_IMAGE_MANIPULATION  ON CACHE BOOL "" FORCE)
set(SUPPORT_CAMERA_SYSTEM  OFF CACHE BOOL "" FORCE)
set(SUPPORT_DEFAULT_FONT  ON CACHE BOOL "" FORCE)
set(SUPPORT_FONT_TEXTURE  ON CACHE BOOL "" FORCE)
set(SUPPORT_QUADS_DRAW_MODE  ON CACHE BOOL "" FORCE)
set(SUPPORT_IMAGE_GENERATION  OFF CACHE BOOL "" FORCE)
set(SUPPORT_GESTURES_SYSTEM  ON CACHE BOOL "" FORCE)
set(SUPPORT_VR_SIMULATOR  OFF CACHE BOOL "" FORCE)
set(SUPPORT_DISTORTION_SHADER  ON CACHE BOOL "" FORCE)

#Image formats
set(SUPPORT_FILEFORMAT_PNG  ON CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_DDS  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_HDR  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_KTX  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_ASTC  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_BMP  ON CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_TGA  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_JPG  ON CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_PKM  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_PVR  OFF CACHE BOOL "" FORCE)

#Model formats
#We obviously don't need model loading for a purely 2D video game.
set(SUPPORT_FILEFORMAT_OBJ  OFF CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_MTL  OFF CACHE BOOL "" FORCE)

#Audio Formats
set(SUPPORT_FILEFORMAT_WAV  ON CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_OGG  ON CACHE BOOL "" FORCE)
set(SUPPORT_FILEFORMAT_XM  OFF CACHE BOOL "" FORCE) #Who tf is using XM?!?!
set(SUPPORT_FILEFORMAT_MOD  OFF CACHE BOOL "" FORCE) #Who tf is using MOD?!?!
set(SUPPORT_FILEFORMAT_FLAC  OFF CACHE BOOL "" FORCE) #Would be nice but OGG and Wave are bettter.

#Misc
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
set(SUPPORT_BUST_WAIT_LOOP  ON CACHE BOOL "" FORCE)
set(INCLUDE_EVERYTHING  OFF CACHE BOOL "" FORCE)
set(SUPPORT_TRACE_LOG  ON CACHE BOOL "" FORCE)

#CMake
set(BUILD_SHARED_LIBS  ON CACHE BOOL "" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)

IF ((WIN32 OR WIN64) OR APPLE OR LINUX)

    set(PLATFORM    "Desktop" CACHE BOOL "Desktop" FORCE)
    set(OPENGL_VERSION    "3.3" CACHE BOOL "3.3" FORCE)
    set(SUPPORT_SCREEN_CAPTURE  ON CACHE BOOL "" FORCE)
    set(SUPPORT_GIF_RECORDING  ON CACHE BOOL "" FORCE)
    set(WITH_PIC  OFF CACHE BOOL "" FORCE)

    if (APPLE)
        set(CMAKE_OSX_DEPLOYMENT_TARGET 10.15)
        set(MACOS_FATLIB  OFF CACHE BOOL "" FORCE)
    endif()

ELSEIF (ANDROID)

    set(PLATFORM    "Android" CACHE BOOL "Android" FORCE)
    set(OPENGL_VERSION    "ES 2.0" CACHE BOOL "ES 2.0" FORCE)
    set(BUILD_SHARED_LIBS  ON CACHE BOOL "" FORCE)
    set(SUPPORT_SCREEN_CAPTURE  OFF CACHE BOOL "" FORCE)
    set(SUPPORT_GIF_RECORDING  OFF CACHE BOOL "" FORCE)

ELSEIF (EMSCRIPTEN)
    set(PLATFORM    "Web" CACHE BOOL "Web" FORCE)
ENDIF()

#We need to get the path of the shared libs somehow.
add_subdirectory("${DEPENDENCY_DIR}/raylib-4.5.0")
set(RAYLIB_BIN_DIR ${raylib_BINARY_DIR})
file(GLOB_RECURSE RAYLIB_LIBS "${RAYLIB_BIN_DIR}/*.dylib")
