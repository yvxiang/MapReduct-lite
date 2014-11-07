# Build library strutil.
add_library(binary_search_tree binary_search_tree.cc)

# Build unittests.
set(LIBS base binary_search_tree gtest pthread)

#add_executable(md5_hash_test md5_hash_test.cc)
#target_link_libraries(md5_hash_test gtest_main ${LIBS})

# Install library and header files
install(TARGETS binary_search_tree DESTINATION lib/paralgo)
FILE(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${HEADER_FILES} DESTINATION include/paralgo/binary_search_tree)
