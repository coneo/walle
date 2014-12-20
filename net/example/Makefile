CXX = g++
CXX_DEPS = -DTEST_SERVER
CXX_FLAGS= -std=c++11 -g -fPIC
CXX_LIBS = $(CXX_DEPS) -lpthread -lrt -L../ -lnet

INC = -I ../
TESTS = socket_srv_test socket_cli_test

all: $(TESTS)

$(TESTS):
	$(CXX) $(INC) $(CXX_FLAGS) -o $@ $(filter %.cpp,$^) $(CXX_LIBS)

test_Logger: test_Logger.cpp ../logger.cpp ../backend_logger.cpp ../log_file.cpp

socket_srv_test: socket_srv_test.cpp ../socket.cpp ../sock_op.h ../sock_op.cpp ../endpoint.cpp
socket_cli_test: socket_cli_test.cpp ../socket.cpp ../sock_op.h ../sock_op.cpp ../endpoint.cpp

clean:
	rm -f $(TESTS)
