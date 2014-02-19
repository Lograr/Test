#include "main.hpp"

int main( int argc, char *argv[]  ) {
    std::cout << PROG_NAME << " " << VERSION << std::endl;
    std::cout << PROG_DESC << std::endl << std::endl;

    std::string input;
    std::map< int, long double > table;
    Log log( default_log_file );

    if( argc == 2 and std::string( argv[1] ) == "-v" ) {
        log.write( "Option -v used; log will be verbose.\n" );
        log.verbosity_level = Verbosity::Verbose;
    }

    bool run = true;
    while( run ) {
        std::cout << "Enter a number to be calculated (q to quit): ";
        std::cin >> input;

        if( input == "q" )
            break;

        int number = std::atoi( input.c_str() );
        int original_number = number;
        long double factorial = 1;

        if( table.count( number ) ) {
            factorial = table[ number ];
            log.write( "Using table: " + std::to_string( original_number ) + ", " + std::to_string( factorial)  + ".\n", Verbosity::Verbose );
        }
        else {
            while( number > 0 ) {
                factorial = factorial * number;
            number--;
            }
            table[ original_number ] = factorial;
            log.write( "Calculated:  " + std::to_string( original_number ) + ", " + std::to_string( factorial )+ ".\n", Verbosity::Verbose );
        }

        std::cout << "Factorial of " << input << " is " << factorial << "." << std::endl;
        std::cin.get();
    }

    // Debug code. Verify that table is being added to
    for( std::map< int, double long >::const_iterator i = table.begin(); i != table.end(); ++i ) {
        log.write( "Stored: " + std::to_string( i->first ) + ", " + std::to_string( i -> second ) + ".\n", Verbosity::Verbose );
    }
    return 0;
}
