/******************************************************************************

                        Superior elements in an array
BF:
TC: O(n^2)
SC: O(n) -> to return result in a new array
OS:
TC: O(n)
SC: O(n) -> to return result in a new array
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Brute force */
vector<int> superiorElements (vector<int> &arr)
{
    bool flag = false;
    vector<int> result;
    for (int i=0; i<arr.size(); i++)
    {
        flag = false;
        for (int j=i+1; j<arr.size(); j++)
        {
            if (arr[j] >= arr[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            result.push_back(arr[i]);
    }
    sort(result.begin(), result.end());
    return result;
}

/* Optimal solution */
// vector<int> superiorElements (vector<int> &a)
// {
    // vector<int> result;
    // result.push_back(a[a.size()-1]);
    // for (int i=(a.size() - 2); i>=0; i--)
    // {
    //     if (a[i] > result[result.size()-1])
    //         result.push_back(a[i]);
    // }
    // return result;
// }

int main()
{
    vector<int> a = {10, 7, 16, 12, 8, 9};
    vector<int> result = superiorElements(a);
    for (auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}