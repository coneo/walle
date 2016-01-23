SOURCES=$(wildcard *.cpp)
BINS=$(patsubst %.cpp, %, $(SOURCES))

all:
	@for src in $(SOURCES);\
	do \
	bin=`basename $$src .cpp`;\
	g++ -std=c++11 -o $$bin $$src -L../ -lbase;\
	done
	
clean:
	@for bin in $(BINS);\
	do \
	rm $$bin;\
	done
