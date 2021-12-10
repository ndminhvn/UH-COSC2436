#include <iostream>
#include <cstdlib>

using namespace std;

int getSum (int val, int dist )
{
   // Implement function
    int sum = 0;
    if (dist == 1) {
        if (val % 2 == 0) {
            return val;
        } else return 0;
    }
    else if (dist != 0) {
        if (val % 2 == 0) {
            sum = val + getSum(val - 1, dist - 1);
            return sum;
        } else {
            sum = getSum(val - 1, dist - 1);
            return sum;
        }
    }
}


int main ( int argc, char **argv )
{
    int startval=1, startdist=1;

    if ( argc == 2 ) {
        startval = std::atoi(argv[1]);
    }
    if (argc == 3 ) {
        startval = std::atoi(argv[1]);
        startdist = std::atoi (argv[2]);
    }

    int sum = getSum(startval, startdist);
    cout << "Input start value was " << startval << " Distance " << startdist << " Sum : " << sum << endl;

    return 0;
}

