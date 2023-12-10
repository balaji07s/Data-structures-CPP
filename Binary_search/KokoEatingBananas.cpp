/*
BF:
TC: O(n)
SC: O(1)

OS:
TC: O(log n)
SC: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

/* Brute force solution using linear search */
long long findTotalHours (int mid, vector<int> &v)
{
    long long sum = 0;
    for (int i=0; i<v.size(); i++)
    {
        sum = sum + ceil((double)v[i]/(double)mid);
    }
    return sum;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int max_ele = max_element(v.being(), v.end());
    long long final_ans = 0;
    for (int i = 1; i<max_ele; i++)
    {
        long long ans = findTotalHours(i, v);
        if (ans > h)
            break;
        final_ans = ans;
    }
    return ans;
}

/* Optimal solution using binary search */
long long findTotalHours (int mid, vector<int> &v)
{
    long long sum = 0;
    for (int i=0; i<v.size(); i++)
    {
        sum = sum + ceil((double)v[i]/(double)mid);
    }
    return sum;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = *(max_element(v.begin(), v.end()));
    while (low <= high)
    {
        int mid = low + ((high - low)/2);
        long long ans = findTotalHours(mid, v);
        if (ans <= h)
        {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main ()
{
    vector<int> v = {7, 15, 6, 3};
    int h;
    cin >> h;

    minimumRateToEatBananas(v, h);
    return 0;
}