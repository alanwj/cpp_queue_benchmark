include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Never run clang-tidy on the googletest targets.
set_target_properties(gtest gtest_main gmock gmock_main
                      PROPERTIES CXX_CLANG_TIDY "")

mark_as_advanced(
  BUILD_GMOCK
  BUILD_GTEST
  BUILD_SHARED_LIBS
  gmock_build_tests
  gtest_build_samples
  gtest_build_tests
  gtest_disable_pthreads
  gtest_force_shared_crt
  gtest_hide_internal_symbols)
