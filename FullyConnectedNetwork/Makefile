CC=g++
CFLAG = -c

all: compile

testN: NNet.o matrix.o testNet.o
	$(CC) -o Network NNet.o matrix.o testNet.o
	@valgrind ./Network

testM: matrix.o test.o
	$(CC) -o hw matrix.o test.o
	@valgrind ./hw

compile: NNet.o matrix.o test.o
	$(CC) -o tmp_file NNet.o matrix.o test.o
	@echo "All moduls has been successfully compiled!"
	@rm -rf tmp_file

NNet.o:
	$(CC) $(CFLAG) NNet.cpp

matrix.o:
	$(CC) $(CFLAG) matrix.cpp

testNet.o:
	$(CC) $(CFLAG) testNet.cpp

test.o:
	$(CC) $(CFLAG) test.cpp

clean:
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw
	@rm -rf Network
