#include "Logging.h"

void Logging::Init(uint8_t level, Print* printer)
{
    _printer = printer;
    _level = level;
}

boolean Logging::IsInitialized()
{
    return _printer != 0;
}

Logger* Logging::getLogger(String file_name)
{
    return new Logger(file_name, this);
}

void Logging::Debug(const char* message, ...)
{
    if(_level <= LOG_LEVEL_DEBUG)
    {
        char buffer[MAX_BUFFER_SIZE];
        va_list args;
        va_start(args, message);
        vsnprintf(buffer, MAX_BUFFER_SIZE, message, args);
        va_end(args);

        _printer->print("DEBUG: ");
        _printer->println(buffer);
    }
}

void Logging::Info(const char* message, ...)
{
    if(_level <= LOG_LEVEL_INFO)
    {
        char buffer[MAX_BUFFER_SIZE];
        va_list args;
        va_start(args, message);
        vsnprintf(buffer, MAX_BUFFER_SIZE, message, args);
        va_end(args);

        _printer->print("INFO: ");
        _printer->println(buffer);
    }
}

void Logging::Warn(const char* message, ...)
{
    if(_level <= LOG_LEVEL_WARN)
    {
        char buffer[MAX_BUFFER_SIZE];
        va_list args;
        va_start(args, message);
        vsnprintf(buffer, MAX_BUFFER_SIZE, message, args);
        va_end(args);

        _printer->print("WARN: ");
        _printer->println(buffer);
    }
}

void Logging::Error(const char* message, ...)
{
    if(_level <= LOG_LEVEL_ERROR)
    {
        char buffer[MAX_BUFFER_SIZE];
        va_list args;
        va_start(args, message);
        vsnprintf(buffer, MAX_BUFFER_SIZE, message, args);
        va_end(args);

        _printer->print("ERROR: ");
        _printer->println(buffer);
    }
}

Logging Log = Logging();


void Logger::Debug(const char* message, ...)
{
    va_list args;
    va_start(args, message);
    logger->Debug((file_name + " :: " + String(message)).c_str(), args);
    va_end(args);
}

void Logger::Info(const char* message, ...)
{
    va_list args;
    va_start(args, message);
    logger->Info((file_name + " :: " + String(message)).c_str(), args);
    va_end(args);
}

void Logger::Warn(const char* message, ...)
{
    va_list args;
    va_start(args, message);
    logger->Warn((file_name + " :: " + String(message)).c_str(), args);
    va_end(args);
}

void Logger::Error(const char* message, ...)
{
    va_list args;
    va_start(args, message);
    logger->Error((file_name + " :: " + String(message)).c_str(), args);
    va_end(args);
}
