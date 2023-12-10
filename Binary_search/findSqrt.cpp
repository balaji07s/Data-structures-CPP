/******************************************************************************
 * 
 *              Binary search answers (Find the sqrt of an integer)
 * 
 * Brute force:
 * TC: O(n)
 * SC: O(1)
 * Optimal solution:
 * TC: O(log n)
 * SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


/*
Brute force approach
*/
// int findSqrt (int n)
// {
//     int ans = 1;
//     for (int i=1; i<n; i++)
//     {
//         if ((i * i) <= n)
//         {
//             ans = i;
//         }
//     }
//     return ans;
// }

/*
Optimal solution
*/
int findSqrt (int n)
{
    long l = 1,
        h = n;
        
    while (l <= h)
    {
        long m = (l + h)/2;
        if ((m*m) == n)
        {
            return m;
        }
        if ((m*m) < n)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return h;
}



int main()
{
    int n;
    cin >> n;
    cout << findSqrt(n) << endl;

    return 0;
}