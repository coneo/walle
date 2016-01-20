/*
 * date: 2014-07-27 12:02:02
 * format : data time level msg file line 
 * example: 2014-07-27 09:41:23 DEBUG: hello shok - Loggging_test.cpp:34
 *
 */
#ifndef WALLE_BASE_LOGGER_HPP
#define WALLE_BASE_LOGGER_HPP

#include "../format.h"
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <time.h>

namespace water{

typedef std::stringstream LogStream; //FIXME: move to a better one
extern thread_local LogStream m_stream;

enum class LogLevel : uint8_t
{
	LL_DEBUG,
	LL_TRACE,
	LL_WARN,
	LL_ERROR,
	LL_MAX
};

class Logger
{
public:
    typedef std::function<void(const char*,uint32_t)> AppendCallback;

    Logger();
    ~Logger() = default;

    template<typename... Args>
    void log(LogLevel level, const char* file, int line,  Args... args)
    {
        formatTime();
        m_stream <<" "<< getLevelStr(level) << ": ";
        //print(args...);
        m_stream << format(args...);
        m_stream << " - " << file << ":" << line;
        m_stream << "\n";

        if (m_appendcb)
            m_appendcb(m_stream.str().data(), (uint32_t)(m_stream.str().size()));
        m_stream.str("");
        m_stream.clear();
    }

    void setAppendCallback(AppendCallback cb){ m_appendcb = cb; }

    void formatTime();

    void setLogLevel(LogLevel l){ m_level = l; }

    LogLevel level() const { return m_level; }

    const char* getLevelStr(LogLevel l);

private:
    LogLevel m_level;
    AppendCallback m_appendcb;
};


#define LOG_DEBUG(...) \
    do{\
        gLogger.log(LogLevel::LL_DEBUG, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_TRACE(...) \
    do{\
        gLogger.log(LogLevel::LL_TRACE, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_WARN(...) \
    do{\
        gLogger.log(LogLevel::LL_WARN, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_ERROR(...) \
    do{\
        gLogger.log(LogLevel::LL_ERROR, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

}

extern water::Logger gLogger;

#endif //#define WATER_BASE_LOGGER_HPP
