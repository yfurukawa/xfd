CC = g++
RM = rm -f
INCLUDE = -I/usr/incude -I/usr/local/include
LIB_DIR = -L/usr/lib64 -L/usr/local/lib64
LIB = -lpthread
OPT = -O0 -g3 -Wall -Wnon-virtual-dtor -Woverloaded-virtual -fmessage-length=0 -fprofile-arcs -ftest-coverage
TARGET = a.out
include productionSources.mk

all: $(SRC:.cpp=.o) main.o
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(SRC:.cpp=.o) main.o
$(SRC:.cpp=.o): $(SRC)
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp
.PHONY: clean
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe *.txt


TEST_TARGET = a.outTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage
include testSources.mk

test: $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o) $(LIB) $(TEST_LIB)

$(TEST_SRC:.cpp=.o): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)
