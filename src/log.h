#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <fstream>

enum class Verbosity {
    Quiet = 0,
    Verbose = 1
};

class Log {
public:
    Log();
    Log( std::string log_file );
    void setVerbosity( Verbosity level );
    void write( std::string message, Verbosity level );
    ~Log();
private:
    Verbosity verbosity_level;
    std::ofstream log_stream;
    void checkStream( std::string filename );
};

#endif
