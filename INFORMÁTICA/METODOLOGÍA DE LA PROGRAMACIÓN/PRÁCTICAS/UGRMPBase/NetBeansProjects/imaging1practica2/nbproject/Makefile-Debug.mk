#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Byte.o \
	${OBJECTDIR}/src/Image.o \
	${OBJECTDIR}/src/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/00Main.o \
	${TESTDIR}/tests/01UnitByte.o \
	${TESTDIR}/tests/02UnitImage.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../MPTools/dist/Debug/GNU-Linux/libmptools.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/imaging1practica2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/imaging1practica2: ../MPTools/dist/Debug/GNU-Linux/libmptools.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/imaging1practica2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/imaging1practica2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Byte.o: src/Byte.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Byte.o src/Byte.cpp

${OBJECTDIR}/src/Image.o: src/Image.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Image.o src/Image.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:
	cd ../MPTools && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd ../MPTools && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/00Main.o ${TESTDIR}/tests/01UnitByte.o ${TESTDIR}/tests/02UnitImage.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}  -pthread ../MPTools/dist/Debug/GNU-Linux/libmptools.a 


${TESTDIR}/tests/00Main.o: tests/00Main.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -I. -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/00Main.o tests/00Main.cpp


${TESTDIR}/tests/01UnitByte.o: tests/01UnitByte.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -I. -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/01UnitByte.o tests/01UnitByte.cpp


${TESTDIR}/tests/02UnitImage.o: tests/02UnitImage.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -I. -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/02UnitImage.o tests/02UnitImage.cpp


${OBJECTDIR}/src/Byte_nomain.o: ${OBJECTDIR}/src/Byte.o src/Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Byte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Byte_nomain.o src/Byte.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Byte.o ${OBJECTDIR}/src/Byte_nomain.o;\
	fi

${OBJECTDIR}/src/Image_nomain.o: ${OBJECTDIR}/src/Image.o src/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Image.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Image_nomain.o src/Image.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Image.o ${OBJECTDIR}/src/Image_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -I../MPTools/googletest-master/googletest/include -I../MPTools/include -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../MPTools && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
