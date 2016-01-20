CXX = g++
CXX_DEPS = -DTEST_SERVER
CXX_FLAGS= -std=c++11 -g -fPIC
INC_FLAGS= -I../../
CXX_LIBS = $(CXX_DEPS) -lpthread -lrt -L../../net -lnet

TESTS = server

all: $(TESTS)

$(TESTS):
	$(CXX) $(INC_FLAGS) $(CXX_FLAGS) -o $@ $(filter %.cpp,$^) $(CXX_LIBS)

client: client.cpp
server: server.cpp

clean:
	@echo "make clean .....";\
	rm -f $(TESTS)
