CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(OCLINT)

SET(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    )

INCLUDE(OCLintConfig)

INCLUDE_DIRECTORIES(${OCLINT_SOURCE_DIR}/include)

ADD_SUBDIRECTORY(lib)

IF(TEST_BUILD)
    ADD_SUBDIRECTORY(test)
ELSE(TEST_BUILD)
    ADD_EXECUTABLE(oclint-${OCLINT_VERSION_RELEASE} main.cpp)
    TARGET_LINK_LIBRARIES(oclint-${OCLINT_VERSION_RELEASE}
        OCLintRuleSet
        OCLintCore
        ${CLANG_LIBRARIES}
        ${REQ_LLVM_LIBRARIES}
        ${CMAKE_DL_LIBS}
        )
ENDIF()
