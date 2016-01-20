CXX = g++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

CXX_FLAGS = -std=c++11 -g
TARGET = libbase.a

.PHONY:
all: $(TARGET)


$(TARGET) : $(OBJECTS)
	ar rs $(TARGET) $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@


#%.d: %.cpp
#	@#set -x ; 
#	@set -e ; \
#	rm -f $@; \
#	$(CXX) -MM $(CXX_FLAGS) $< > $@.$$$$;  \
#	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;  \
#	rm -f $@.$$$$

#-include $(OBJECTS:.o=.d)

test:

clean:
	-rm -f *.o *.d *.d.*
	-rm $(TARGET)

ctags:
	@ctags -R
