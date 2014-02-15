#include "main.h"


int main( int argc, char *argv[]  ) {
    cout << PROG_NAME << " " << VERSION << endl;
    cout << PROG_DESC << endl << endl;

    if( argc != 2 ) {
        cout << "Error: Incorrect number of arguments; use only one number." << endl;
        return 0;
    }

    int number = atoi( argv[1] );
    long double factorial = 1;

    while( number > 0 ) {
        factorial = factorial * number;
        number--;
    }

    cout << "Factorial of " << argv[1] << " is " << factorial << "." << endl;

    return 0;
}
