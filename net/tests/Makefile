CXX=g++
SOURCES=$(wildcard *.cpp)
BINS=$(patsubst %.cpp, %, $(SOURCES))
CXX_FLAGS= -std=c++11 -g -fPIC
CXX_LIBS = -lpthread -lrt -L../ -lnet
INC= -I ../../

all:
	@for src in $(SOURCES);\
	do \
	bin=`basename $$src .cpp`;\
	$(CXX) $(INC) $(CXX_FLAGS) -o $$bin $$src $(CXX_LIBS);\
	done
	
clean:
	@for bin in $(BINS);\
	do \
	rm $$bin;\
	done
