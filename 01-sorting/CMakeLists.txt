file(GLOB APP_SOURCES *.cpp)
foreach (testsourcefile ${APP_SOURCES})
    get_filename_component(testname ${testsourcefile} NAME_WLE)
    message("   ${testname}")
    add_executable("${testname}" ${testname}.cpp)
    target_link_directories("${testname}" PUBLIC 
                            "${PROJECT_SOURCE_DIR}/01-sorting")
endforeach (testsourcefile ${APP_SOURCES})
