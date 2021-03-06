CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Recompiler)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(Recompiler main.cpp)

IF (NOT TARGET InputLibrary)
	ADD_SUBDIRECTORY(InputLibrary)
ENDIF ()
IF (NOT TARGET LLParserLibrary)
	ADD_SUBDIRECTORY(LLParserLibrary)
ENDIF ()

FIND_PACKAGE(LLVM REQUIRED CONFIG)

MESSAGE(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
MESSAGE(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

INCLUDE_DIRECTORIES(${LLVM_INCLUDE_DIRS})
ADD_DEFINITIONS(${LLVM_DEFINITIONS})

LLVM_MAP_COMPONENTS_TO_LIBNAMES(llvm_libs support core irreader executionengine target X86 interpreter BPF AArch64 Hexagon Sparc ARM XCore NVPTX MSP430 SystemZ PowerPC AMDGPU Mips Lanai)

TARGET_LINK_LIBRARIES(Recompiler InputLibrary LLParserLibrary ${llvm_libs})
