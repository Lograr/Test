#include "log.h"

Log::Log() {
    log_stream.open( "log.txt" );
    verbosity_level = Verbosity::Quiet;
}

Log::Log( std::string log_file ) {
    log_stream.open( log_file.c_str() );
    verbosity_level = Verbosity::Quiet;
}

void Log::setVerbosity( Verbosity level ) {
    verbosity_level = level;
}

void Log::write( std::string message, Verbosity level ) {
    if( level <= verbosity_level ) {
        if( log_stream.is_open() ) {
            log_stream << message;
        }
        else {
            std::cout << message;
        }
    }
}

void Log::checkStream( std::string filename ) {
    if( !log_stream.is_open() ) {
        std::cout << "Log file, " << filename << ", could not be opened." << std::endl;
        std::cout << "Errors/warnings will be redirected to console output." << std::endl;
    }
    else {
        write( "Using log file: " + filename + ".", Verbosity::Verbose );
    } 
}

Log::~Log() {
    log_stream.close();
}
