CXX = g++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, obj/%.o, $(SOURCES))

CXX_FLAGS = -std=c++11 -g
TARGET = libbase.a


$(TARGET) : $(OBJECTS)
	ar rs $(TARGET) $(OBJECTS)

$(OBJECTS): obj

obj:
	@mkdir -p $@

obj/%.o: %.cpp
	$(CXX) -std=c++11 -g -c $< -o $@

test:
	@make -C tests;

clean:
	-rm -rf obj/ *.d *.d.*
	-rm $(TARGET)
	make clean -C tests;

ctags:
	@ctags -R

.PHONY:
all: $(TARGET)
