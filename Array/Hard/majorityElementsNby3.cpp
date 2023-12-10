/******************************************************************************

                    majority elements (greater than floor(n/3))

BF:
TC: O(n^2)
SC: O(1)
BS:
TC: O(2n)
SC: O(n)
OS:
TC: O(2n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

/*
Hint:
    If N=8 then floor of (8/3) will give 2 then minimal count
    of an element in the array needed is 3. if we add 3 + 3 + 3 then
    it is exceeding the size of the array 8. So, atmost 2 elements can
    be repeated more than floor(n/3)
*/

/* Brute force */
// vector<int> majorityElements(vector<int> &arr)
// {
//     int count = 1;
//     vector<int> result;
//     for (int i=0; i<arr.size(); i++)
//     {
//         count = 1;
//         if (result.size() == 2)
//             break;
//         for (int j=i+1; j<arr.size(); j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 count++;
//             }
//         }
//         if (count > (arr.size()/3))
//         {
//             result.push_back(arr[i]);
//         }
//     }
//     return result;
// }

/* Better solution */
// vector<int> majorityElements(vector<int> &arr)
// {
//     vector<int> result;
//     unordered_map<int, int> mp;
    
//     for (auto x : arr)
//     {
//         mp[x]++;
//     }
//     for (auto x : mp)
//     {
//         if (x.second > (arr.size()/3))
//         {
//             result.push_back(x.first);
//         }
//         if (result.size() == 2)
//             break;
//     }
//     return result;
// }

/* Optimal solution */
vector<int> majorityElements(vector<int> &arr)
{
    int elem1, elem2, cnt1 = 0, cnt2 = 0;
    vector<int> res;
    
    for (int i=0; i<arr.size(); i++)
    {
        if(cnt1 == 0)
        {
            cnt1++;
            elem1 = arr[i];
        }
        else if (cnt2 == 0)
        {
            cnt2++;
            elem2 = arr[i];
        }
        else if (elem1 == arr[i])
        {
            cnt1++;
        }
        else if (elem2 == arr[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0; cnt2 = 0;
    for (int i=0; i<arr.size(); i++)
    {
        if(elem1 == arr[i])
            cnt1++;
        else if (elem2 == arr[i])
            cnt2++;
    }
    if (cnt1 > (arr.size()/3))
        res.push_back(elem1);
    if (cnt2 > (arr.size()/3))
        res.push_back(elem2);
    return res;
}


int main()
{
    vector<int> v1 = {6, 4, 3, 4, 2, 3, 1, 2, 3, 3, 4, 3, 4, 3};
    cout << "no.of.elements: " << v1.size() << endl;
    vector<int> result = majorityElements(v1);
    
    for (auto x : result)
        cout << x << " ";
    return 0;
}