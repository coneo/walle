CXXFLAGS= -std=c++11 -g -D_HXQ_DEBUG

#HEADERS=logger.h #FIXME
INC = -I ../
#TESTS= test_Logger test_WriteFile test_LogBuffer test_Vector test_FileLock test_FileLock2 test_ConditionVar
TESTS= test_Logger test_Format

all: $(TESTS)

#$(TESTS): $(HEADERS)

$(TESTS):
	g++ $(INC) $(CXXFLAGS) -o $@ $(filter %.cpp,$^) -lpthread -lrt

test_Logger: test_Logger.cpp ../logger.cpp ../backend_logger.cpp ../log_file.cpp

test_WriteFile: test_WriteFile.cpp ../log_file.cpp

test_LogBuffer: test_LogBuffer.cpp

test_Vector: test_Vector.cpp

test_FileLock: test_FileLock.cpp

test_FileLock2: test_FileLock2.cpp

test_ConditionVar: test_ConditionVar.cpp

test_Format: test_Format.cpp

clean:
	rm -f $(TESTS) *.log ../*.log*
