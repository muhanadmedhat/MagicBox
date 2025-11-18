#include <iostream>
#include "magic.h"
using namespace std;

int main()
{
    int grid=0;
    cout << "Please Enter the number: ";
    cin >> grid;
    magicsquaregenerator(grid);
    return 0;
}