#include "main.h"

int main( int argc, char *argv[]  ) {
    std::cout << PROG_NAME << " " << VERSION << std::endl;
    std::cout << PROG_DESC << std::endl << std::endl;

    std::string input;
    std::map< int, long double > table;

    bool run = true;
    while( run ) {
        std::cout << "Enter a number to be calculated (q to quit): ";
        std::cin >> input;

        if( input == "q" )
            run = false;

        int number = std::atoi( input.c_str() );
        int original_number = number;
        long double factorial = 1;

        if( table.count( number ) ) {
            factorial = table[ number ];
            std::cout << "used table" << std::endl;
        }
        else {
            while( number > 0 ) {
                factorial = factorial * number;
            number--;
            }
            table[ original_number ] = factorial;
            std::cout << "calculated and added" << std::endl;
        }

        std::cout << "Factorial of " << input << " is " << factorial << "." << std::endl;
        std::cin.get();
    }

    // Debug code. Verify that table is being added to
    for( std::map< int, double long >::const_iterator i = table.begin(); i != table.end(); ++i ) {
        std::cout << i->first << ": " << i -> second << std::endl;
    }
    return 0;
}
