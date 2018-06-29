# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


include_directories(
	C:/Android_Projects/code_ubleam/image-library/UcvApi/PureC/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Config/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/hdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Logger/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/hdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/ghdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/IConvLight
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/include
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar
)

set(LIB_SOURCE_FILES
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/src/rijndael.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/src/ub_key.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_algebra.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_blas.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_ellipse.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_homog.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_matrix.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_rs.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/src/ub_vector.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/src/ub_debug.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/src/ub_timings.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/src/ub_image.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/src/ub_img_io.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/src/ub_img_oper.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_access.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_al_kalinox.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_ambig_homog.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_authorization.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_bleam_list.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_common.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_core.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_debug.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_debug_display.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_debug_write.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_demod_decode.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_effect.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_ellipse_detector.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_gradient.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_gradient_std.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_helper.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_inner_ellipse.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_matching.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_merge.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_pose.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_qrcode.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_ref_point.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_rosin.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_seeds.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/src/ubar_stab_regist.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/IConvLight/iconvl.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/decoder.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/error.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/image.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/img_scanner.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/refcnt.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/scanner.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/symbol.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/decoder/qr_finder.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/bch15_5.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/binarize.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/isaac.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/qrdec.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/qrdectxt.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/rs.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/util.c

	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_authorization.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_bleam_list.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_convert_roi.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_demod_decode.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_homog_list.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_inner.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_merge.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_processing.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_propa.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_qrcode.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_reading.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_ref_point.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_throw_small.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/ub_winner.c
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/src/UBDecoder.c
)

set( ubleam_LIB_HDRS
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Config/ghdr/ucvcore_config.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_matching.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_debug_write.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_merge.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_debug.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_al_kalinox.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_stab_regist.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_common.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_rosin.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_inner_ellipse.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_prstvars.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_authorization.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_ambig_homog.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_settings.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_demod_decode.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_gradient_std.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_debug_display.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_seeds.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_pose.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_gradient_asm.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_qrcode.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_bleam_list.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_ellipse_detector.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_gradient.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_conn_comp.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_effect.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/hdr/ubar_ref_point.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/ghdr/ubar_codes.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/ghdr/ubar_definitions.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/ghdr/ubar.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Tracking/ghdr/ubar_types.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/hdr/ub_blas.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_math.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_matrix.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_homog.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_ellipse.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_rs.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_algebra.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Math/ghdr/ub_vector.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/hdr/rijndael.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Key/ghdr/ub_key.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/ghdr/ub_timings.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/ghdr/ub_assert.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Misc/ghdr/ub_debug.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_proc_settings.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_homog_list.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_inner.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_throw_small.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_qrcode.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_demod_decode.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_authorization.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_ref_point.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_bleam_list.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_reading.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_propa.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_convert_roi.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_processing.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_merge.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/hdr/ub_winner.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Reading/ghdr/UBDecoder.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/decoder.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/util.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/qrdec.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/rs.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/bch15_5.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/binarize.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/qrcode/isaac.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/img_scanner.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/refcnt.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/decoder/qr_finder.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/svg.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/image.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/error.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/symbol.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/zbar/debug.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/IConvLight/icl_table.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/IConvLight/iconvl.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/include/config.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/ZBarLight/include/zbar.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/ghdr/ub_image.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/ghdr/ub_img_io.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Picture/ghdr/ub_img_oper.h
	C:/Android_Projects/code_ubleam/image-library/UcvCore/Logger/ghdr/ub_logger.h
	C:/Android_Projects/code_ubleam/image-library/UcvApi/PureC/ghdr/api_config.h

)

add_library(ubleam STATIC ${LIB_SOURCE_FILES})
find_library(M_LIB m)
target_link_libraries(ubleam ${M_LIB})


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       ubleam)

