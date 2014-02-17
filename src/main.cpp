#include "main.h"

int main( int argc, char *argv[]  ) {
    cout << PROG_NAME << " " << VERSION << endl;
    cout << PROG_DESC << endl << endl;

    string input;
    map< int, long double > table;

    bool run = true;
    while( run ) {
        cout << "Enter a number to be calculated (q to quit): ";
        cin >> input;

        if( input == "q" )
            run = false;

        int number = atoi( input.c_str() );
        int original_number = number;
        long double factorial = 1;

        if( table.count( number ) ) {
            factorial = table[ number ];
            cout << "used table" << endl;
        }
        else {
            while( number > 0 ) {
                factorial = factorial * number;
            number--;
            }
            table[ original_number ] = factorial;
            cout << "calculated and added" << endl;
        }

        cout << "Factorial of " << input << " is " << factorial << "." << endl;
        cin.get();
    }

    // Debug code. Verify that table is being added to
    for( map< int, double long >::const_iterator i = table.begin(); i != table.end(); ++i ) {
        cout << i->first << ": " << i -> second << endl;
    }
    return 0;
}
