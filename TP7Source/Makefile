CC = gcc
CFLAGS = -Wall
EXEC = main runTest
TEST_DIR = test
TEST_DISKIO = $(TEST_DIR)/LibDiskIO
TEST_RELATION = $(TEST_DIR)/LibRelation
TEST_DISKSORTMERGE = $(TEST_DIR)/LibDiskSortMerge
TEST_GENERATE = $(TEST_DIR)/LibGenerate
TEST_OUTIL = $(TEST_DIR)/LibOutil
TEST = $(TEST_DISKIO)/diskIO $(TEST_RELATION)/relation $(TEST_DISKSORTMERGE)/diskSortMerge $(TEST_GENERATE)/generate $(TEST_OUTIL)/outil
SRC_DIR = src
DEMO_DIR = demo
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))

HEADERS_TEST = $(wildcard $(SRC_TEST)/*.h)
OBJECTS_TEST = $(patsubst $(SRC_TEST)/%.c, $(SRC_TEST)/%.o, $(wildcard $(SRC_TEST)/*.c))

all: $(EXEC)

main: $(OBJECTS)
	rm -fR $(DEMO_DIR)/R* $(DEMO_DIR)/Check*
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
diskIO: main
	$(CC) -o $(TEST_DISKIO)/$@ $(TEST_DISKIO)/main.c $(SRC_DIR)/diskIO.o $(SRC_DIR)/relation.o

relation: main
	$(CC) -o $(TEST_RELATION)/$@ $(TEST_RELATION)/main.c $(SRC_DIR)/relation.o

diskSortMerge: main
	$(CC) -o $(TEST_DISKSORTMERGE)/$@ $(TEST_DISKSORTMERGE)/main.c $(SRC_DIR)/diskSortMerge.o $(SRC_DIR)/sortMerge.o $(SRC_DIR)/relation.o $(SRC_DIR)/diskIO.o $(SRC_DIR)/outil.o

generate: main
	$(CC) -o $(TEST_GENERATE)/$@ $(TEST_GENERATE)/main.c $(SRC_DIR)/generate.o $(SRC_DIR)/relation.o $(SRC_DIR)/diskIO.o

outil: main
	$(CC) -o $(TEST_OUTIL)/$@ $(TEST_OUTIL)/main.c $(SRC_DIR)/outil.o 

runTest: diskIO relation diskSortMerge generate outil

run:
	./main

rmDemo:
	rm -fR $(DEMO_DIR)/*

clean:
	rm -f $(SRC_DIR)/*.o

mrproper: clean
	rm -f $(EXEC)
	rm -f $(TEST)
	rm -f $(SRC_DIR)/*.gch
