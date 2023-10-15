/******************************************************************************

                                FACTORIAL USING RECURSION

*******************************************************************************/

#include <iostream>

using namespace std;

/* using linear recursion */
int fact (int n)
{
    if (n == 0)
        return 1;
    
    return n * fact(n - 1);
}

/* using tail recursion */
int fact (int n, int result=1)
{
    if (n == 1)
        return result;
    return fact(n - 1, n * result);
}

int main()
{
    int n;
    cin >> n;
    cout << fact (n) << endl;

    return 0;
}