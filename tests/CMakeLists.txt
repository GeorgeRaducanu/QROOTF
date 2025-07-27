# Tests for QROOTF

add_executable(test_complex_ops test_complex_ops.c)
target_include_directories(test_complex_ops PRIVATE ../inc)
target_link_libraries(test_complex_ops qrootf_static)
add_test(NAME ComplexOpsTest COMMAND test_complex_ops)

add_executable(test_version test_version.c)
target_include_directories(test_version PRIVATE ../inc)
target_link_libraries(test_version qrootf_static)
add_test(NAME VersionTest COMMAND test_version)
