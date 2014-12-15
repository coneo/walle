CXX = g++
CXX_FLAGS= -std=c++11 -g -fPIC

INC = -I ../
TESTS = socket_test

all: $(TESTS)

#$(TESTS): $(HEADERS)

$(TESTS):
	$(CXX) $(INC) $(CXX_FLAGS) -o $@ $(filter %.cpp,$^) -lpthread -lrt -L../ -lnet

test_Logger: test_Logger.cpp ../logger.cpp ../backend_logger.cpp ../log_file.cpp

socket_test: socket_test.cpp ../socket.cpp ../sock_op.cpp

clean:
	rm -f $(TESTS)
