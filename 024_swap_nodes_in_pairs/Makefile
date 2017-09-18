APPS = swap_nodes_in_pairs
CLEAN_FILES = *.o
CC = g++ -g -std=c++11
BIN_DIR = .
SRC_FILES = ${wildcard *.cpp}
OBJ_FILES = ${patsubst %.cpp,%.o,${SRC_FILES}}
BIN_FILES = ${addprefix ${BIN_DIR}/,${APPS}}

CFLAGS = -g -Wall
INC_FLG =
LIBS =

build:${BIN_FILES}

.depend:${SRC_FILES}
	${CC} -MM ${INC_FLG} $^ > $@

sinclude .depend

${BIN_FILES}:${OBJ_FILES}
	${CC}  -o $@ $^ ${LIBS}
%.o:%.cpp
	${CC} ${CFLAGS} -c $< ${INC_FLG}  -o $@

all:${BIN_FILES}

rebuild:clean build

clean:
	rm -f ${CLEAN_FILES}
	rm -f ${BIN_FILES}
	rm -f .depend

.PHONY: build rebuild clean