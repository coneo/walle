CXX = g++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, obj/%.o, $(SOURCES))
OBJECTS=$(patsubst logger/%.cpp, logger/%.o, $(wildcard logger/*.cpp))

CXX_FLAGS = -std=c++11 -g
TARGET = libbase.a


$(TARGET) : $(OBJECTS) 
	ar rs $(TARGET) $(OBJECTS)

$(OBJECTS): obj

obj:
	@mkdir -p $@

obj/%.o: %.cpp
	$(CXX) -std=c++11 -g -c $< -o $@

logger/%.o: logger/%.cpp
	$(CXX) -std=c++11 -g -c $< -o $@

test:
	@make -C tests;

clean:
	-rm -rf obj/ *.d *.d.*
	-rm $(TARGET)
	-rm logger/*.o
	make clean -C tests;

ctags:
	@ctags -R

.PHONY:
all: $(TARGET)
