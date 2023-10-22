/******************************************************************************

        Find the element that appears once and others twice sorted array

BRUTE FORCE:
TC: O(n^2)
SC: O(1)
BETTER:
TC: O(2n)
SC: O(n)
BETTER:
TC: O(2n)
SC: O(n)
OPTIMAL:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* Brute force */
int elementAppearsOnce (vector<int> &nums, int n)
{
    int counter = 0;
    for (int i=0; i<n; i++)
    {
        counter = 0;
        for (int j=0; j<n; j++)
        {
            if(nums[i] == nums[j])
            {
                counter++;
            }
        }
        if(counter == 1)
            return nums[i];
    }
    return -1;
}

/* Better */
int elementAppearsOnce (vector<int> &nums, int n)
{
    int arr[nums[n-1]+1] = {};
    for (int i=0; i<n; i++)
    {
        arr[nums[i]]++;
    }
    for (int i=0; i<n; i++)
    {
        if (arr[nums[i]] == 1)
        {
            return nums[i];
        }
    }
    return -1;
}

/* Better two */
int elementAppearsOnce (vector<int> &nums, int n)
{
    map<int, int> m;
    int i=0;
    for (; i<n; i++)
    {
        m[nums[i]]++;
    }
    for (auto x : nums)
    {
        if (m[x] == 1)
            return x;
    }

    return -1;
}

int elementAppearsOnce (vector<int> &nums, int n)
{
    int xorsum = 0;
    for (auto x : nums)
    {
        xorsum ^= x;
    }
    return xorsum;
}

int main ()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    cout << elementAppearsOnce (nums, nums.size()) << endl;

    return 0;
}