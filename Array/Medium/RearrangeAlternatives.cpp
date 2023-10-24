/******************************************************************************

                Rearrange the array in alternatives based on signs (array size is always even)
BF:
TC: O(2n)
SC: O(n)
BS:
TC: O(n)
SC: O(n) -> to return answer
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Brute force */
vector<int> rearrangeAlternatives (vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;
    
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else if (arr[i] < 0)
            neg.push_back(arr[i]);
    }
    
    for (int i=0; i<(arr.size()/2); i++)
    {
        arr[2*i] = pos[i];
    }
    for (int i=0; i<(arr.size()/2); i++)
    {
        arr[2*i+1] = neg[i];
    }
    return arr;
}

/* Optimal solution */
// vector<int> rearrangeAlternatives(vector<int> &arr)
// {
//     int pos = 0, neg = 1;
//     vector<int> result(arr.size());
//     for (int i=0; i<arr.size(); i++)
//     {
//         if (arr[i] > 0)
//         {
//             result[pos] = arr[i];
//             pos += 2;
//         }
//         else if (arr[i] < 0)
//         {
//             result[neg] = arr[i];
//             neg += 2;
//         }
//     }
//     return result;
// }

int main()
{
    vector<int> arr = {-10, 4, 22, 8, -12, -13};
    vector<int> result = rearrangeAlternatives(arr);
    
    for (auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}