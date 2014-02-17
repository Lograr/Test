#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

using namespace std;

enum Verbosity {
    Quiet,
    Verbose
};

class Log {
public:
    Log() {}
    Log( string log_file ) {}
    void setVerbosity( Verbosity level ) {}
private:
    Verbosity verbosity_level;
};

#endif
