/******************************************************************************

                Rearrange the array in alternatives based on signs (array size is always even)
OS:
TC: O(2n)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Optimal solution */
vector<int> rearrangeAlternatives (vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;
    int posIdx, negIdx, min, start;
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else if (arr[i] < 0)
            neg.push_back(arr[i]);
    }
    min = arr.size()/2;
    for (posIdx=0; posIdx<min; posIdx++)
    {
        arr[2*posIdx] = pos[posIdx];
    }
    for (negIdx=0; negIdx<min; negIdx++)
    {
        arr[2*(negIdx)+1] = neg[negIdx];
    }
    start = negIdx * 2;
    for (int i=posIdx; i<pos.size(); i++)
    {
        arr[start] = pos[i];
        start++;
    }
    for (int i=negIdx; i<neg.size(); i++)
    {
        arr[start] = neg[i];
        start++;
    }
    return arr;
}

int main()
{
    vector<int> arr = {-10, 4};
    vector<int> result = rearrangeAlternatives(arr);

    for (auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}