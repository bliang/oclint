MACRO(build_test name)
    ADD_EXECUTABLE(${name} ${name}.cpp)
    TARGET_LINK_LIBRARIES(${name}
        OCLintMetric
        OCLintUtil
        OCLintCore
        OCLintRuleSet
        gmock
        profile_rt
        ${CLANG_LIBRARIES}
        ${REQ_LLVM_LIBRARIES}
        )

    ADD_TEST(${name} ${EXECUTABLE_OUTPUT_PATH}/${name})
ENDMACRO(build_test)

BUILD_TEST(CanaryTest)

ADD_SUBDIRECTORY(basic)
ADD_SUBDIRECTORY(convention)
ADD_SUBDIRECTORY(empty)
ADD_SUBDIRECTORY(redundant)
ADD_SUBDIRECTORY(size)
ADD_SUBDIRECTORY(unused)
