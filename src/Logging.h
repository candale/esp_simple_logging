#ifndef LOGGING_H
#define LOGGING_H

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define NO_EVEL 0
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4

#define MAX_BUFFER_SIZE 528

class Logging
{
private:
    uint8_t _level = 0;
    Print* _printer = 0;


public:
    void Init(uint8_t level, Print* printer);
    boolean IsInitialized();

    void Debug(const char* message, ...);
    void Info(const char* message, ...);
    void Warn(const char* message, ...);
    void Error(const char* message, ...);
};

extern Logging Log;

#endif
