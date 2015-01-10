CC = g++
RM = rm -f
JSON_C_DIR = /usr/local
INCLUDE = -I/usr/incude -I/usr/local/include -I. -I$(JSON_C_DIR)/include
LIB_DIR = -L/usr/lib64 -L/usr/local/lib64 -L$(JSON_C_DIR)/lib
LIB = -lpthread -ljson-c
OPT = -O3 -g0 -Wall
TARGET = a.out
include productionSources.mk

all: $(SRC:.cpp=.o) main.o
	$(CC) $(INCLUDE) $(LIB_DIR) $(LIB) $(OPT) -o $(TARGET) $(SRC:.cpp=.o) main.o
	
$(SRC:.cpp=.o): $(SRC)
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp
.PHONY: clean
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe *.txt Fuga.cpp Hoge.cpp


TEST_TARGET = a.outTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage
include testSources.mk
include testObjects.mk

test: $(SRC:.cpp=.o) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)
