CXX = g++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, obj/%.o, $(SOURCES))

CXX_FLAGS = -std=c++11 -g
INC_FLAGS = -I../

TARGET = libnet.a

$(TARGET) : $(OBJECTS)
	ar rs $(TARGET) $(OBJECTS)

$(OBJECTS): obj

obj:
	@mkdir -p $@

obj/%.o: %.cpp
	$(CXX) $(CXX_FLAGS) $(INC_FLAGS) -c $< -o $@


test:
	@make -C example;

clean:
	-rm -f *.d *.d.*
	-rm -rf obj/ *.d *.d.*
	-rm $(TARGET)
	make clean -C example

ctags:
	@ctags -R

.PHONY:
all: $(TARGET)
