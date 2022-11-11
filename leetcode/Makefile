CC = g++

# TESTS_FLAGS	= -fprofile-arcs -ftest-coverage
TESTS_FLAGS	= -lgtest -g

TEST_NAME	= test

BUILD	= build

SRCS	= solution.cpp gtests.cpp


EXE		= ${BUILD}/${TEST_NAME}.out

all	: ${TEST_NAME}

${BUILD}	:
	@mkdir $@

${TEST_NAME}	: ${SRCS} ${BUILD}
	${CC} ${SRCS} ${TESTS_FLAGS} -o ${EXE}
	./${EXE}


lldb	:
	lldb -- ./${EXE}
