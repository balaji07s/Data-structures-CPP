/******************************************************************************

                            Find the next permutation
OS:
TC: O(3n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Optimal solution */
void next_permutation_temp (vector<int> &arr)
{
    int index;
    
    for (int i=(arr.size()-2); i>=0; i--)
    {
        if (arr[i] < arr[i+1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    for (int i=(arr.size()-1); i>=0; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    index++;
    int j = arr.size()-1;
    while (index < j)
    {
        swap(arr[index], arr[j]);
        j--;
        index++;
    } 
}

int main()
{
    vector<int> arr = {1,3,2};
    next_permutation_temp(arr);
    
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}