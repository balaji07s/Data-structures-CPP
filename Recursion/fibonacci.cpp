/******************************************************************************

                                FIBONACCI NUMBER

*******************************************************************************/

#include <iostream>

using namespace std;

/* using Linear recursion */
int linearfibonacci (int n)
{
    if (n <= 1)
        return n;
    int prevnum = linearfibonacci(n-1);
    int sprevnum = linearfibonacci(n-2);
    return prevnum + sprevnum;
}

/* Using tail recursion */
int tailFibonacci(int n, int prev = 0, int current = 1) {
    if (n == 0) {
        return prev;
    }
    if (n == 1) {
        return current;
    }
    return tailFibonacci(n - 1, current, prev + current);
}

/* Using binary recursion */
int binfibonacci (int n)
{
    if (n <= 1)
    {
        return n;
    }
    
    return binfibonacci (n - 1) + binfibonacci (n - 2);
}

int main ()
{

    int n;
    cin >> n;
    cout << tailFibonacci(n) << endl;

  return 0;
}