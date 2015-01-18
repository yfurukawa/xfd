CC = g++
RM = rm -f
JSON_C_DIR = /usr/local
INCLUDE = -I/usr/incude -I/usr/local/include -I. -I$(JSON_C_DIR)/include `pkg-config --cflags gtk+-3.0`
LIB_DIR = -L/usr/lib64 -L/usr/local/lib64 -L$(JSON_C_DIR)/lib `pkg-config --libs gtk+-3.0`
LIB = -lpthread -ljson-c -lwiringPi
OPT = -O0 -g3 -Wall
TARGET = xfdd
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

install:
	cp xfd /usr/local/bin
	cp xfd.sh /etc/init.d
	chmod +x /etc/init.d/xfd.sh

TEST_TARGET = xfdTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage
include testSources.mk
include testObjects.mk

test: $(SRC:.cpp=.o) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)
