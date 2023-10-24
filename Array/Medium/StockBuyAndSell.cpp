/******************************************************************************

                            stock buy and sell
BF:
TC: O(n^2)
SC: O(1)
OP:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/* Brute force */
// int stockBuyAndSell (vector<int> &arr)
// {
//     int preProfit, finalProfit = 0;
//     for (int i=0; i<arr.size(); i++)
//     {
//         for (int j=i; j<arr.size(); j++)
//         {
//             preProfit = arr[j] - arr[i];
//             if (preProfit > finalProfit)
//                 finalProfit = preProfit;
//         }
//     }
//     return finalProfit;
// }

/* Optimal solution */
int stockBuyAndSell (vector<int> &arr)
{
    int minElement = arr[0], maxPro = 0;
    
    for (int i=1; i<arr.size(); i++)
    {
        minElement = min(minElement, arr[i]);
        if ((arr[i] - minElement) > maxPro)
        {
            maxPro = arr[i] - minElement;
        }
    }
    return maxPro;
}

int main()
{
    vector<int> arr = {7, 3, 6, 1, 5, 2, 8};
    cout << stockBuyAndSell(arr) << endl;

    return 0;
}