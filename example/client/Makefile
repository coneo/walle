CXX = g++
CXX_DEPS = -DTEST_SERVER
CXX_FLAGS= -std=c++11 -g -fPIC
CXX_LIBS = $(CXX_DEPS) -lpthread -lrt -L../../net -lnet

INC = -I ../../
TESTS = client server

all: $(TESTS)

$(TESTS):
	$(CXX) $(INC) $(CXX_FLAGS) -o $@ $(filter %.cpp,$^) $(CXX_LIBS)

test_Logger: test_Logger.cpp ../logger.cpp ../backend_logger.cpp ../log_file.cpp

client: client.cpp
server: server.cpp

clean:
	rm -f $(TESTS)
