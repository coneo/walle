#ifndef WALLE_BASE_LOGGER_H
#define WALLE_BASE_LOGGER_H

#include "singleton.h"
#include "logger/front_logger.h"
#include "logger/backend_logger.h"

namespace walle{
namespace base{

class LoggerModule : public Singleton<LoggerModule>
{
public:
    void init(std::string filename)
    {
        using namespace std::placeholders;
        //m_bkLogger.reset(new BackendLogger(filename));
        m_bkLogger = new BackendLogger(filename);
        if (m_bkLogger)
            m_bkLogger->start();
        m_logger.setAppendCallback(std::bind(&LoggerModule::dumpfunc, this, _1, _2));
    }

    Logger& logger() { return m_logger; }

private:
    void dumpfunc(const char* msg, uint32_t len)
    {
        if (m_bkLogger)
        {
            m_bkLogger->append(msg, len);
        }
    }

private:
    Logger m_logger;
    BackendLogger* m_bkLogger = nullptr;
};

#define LOG_DEBUG(...) \
    do{\
        LoggerModule::getme().logger().log(LogLevel::LL_DEBUG, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_TRACE(...) \
    do{\
        LoggerModule::getme().logger().log(LogLevel::LL_TRACE, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_WARN(...) \
    do{\
        LoggerModule::getme().logger().log(LogLevel::LL_WARN, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

#define LOG_ERROR(...) \
    do{\
        LoggerModule::getme().logger().log(LogLevel::LL_ERROR, __FILE__,__LINE__, __VA_ARGS__); \
    }while(0)

}}
#endif
