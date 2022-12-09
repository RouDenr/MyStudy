CC = g++

# TESTS_FLAGS	= -fprofile-arcs -ftest-coverage
TESTS_FLAGS	= -lgtest -g

TEST_NAME	= test

BUILD	= build

SRCS	= solution.cpp gtests.cpp
OBJS	= ${SRCS:%.cpp=%.o}
DEP		= ${OBJS:%.o=%.d}


EXE		= ${BUILD}/${TEST_NAME}.out

all	: ${TEST_NAME}

${BUILD}	:
	@mkdir $@

${TEST_NAME}	: ${OBJS} ${BUILD}
	${CC} ${OBJS} ${TESTS_FLAGS} -o ${EXE}


%.o		:	%.cpp
	${CC} ${TESTS_FLAGS} -MMD -c $< -o $@

-include ${DEP}

run	: all
	./${EXE}


lldb	:
	lldb -- ./${EXE}
