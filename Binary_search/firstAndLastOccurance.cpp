/******************************************************************************
 * 
 *                      First and last occurance
 * lower_bound
 * TC: O(2n)
 * SC: O(1)
 * binary search
 * TC: O(2logn)
 * SC: O(1)
 ******************************************************************************/

/* Optimal solution */
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int key)
{
    pair<int, int> ans = {-1, -1};
    int l, h;
    l = 0;
    h = arr.size()-1;
    /* Finding first occurance */
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (arr[m] == key)
        {
            ans.first = m;
            h = m-1;
        }
        else if (arr[m] > key)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (ans.first == -1)
        return {-1, -1};
    l = 0;
    h = arr.size()-1;
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (arr[m] == key)
        {
            ans.second = m;
            l = m + 1;
        }
        else if (arr[m] > key)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}


/* Better solution */
vector<int> searchRange(vector<int>& arr, int key) {
    vector<int> ans = {-1, -1};
    int l, m, h;
    l = 0;
    h = arr.size()-1;
    if (arr.size() == 0)
        return ans;
    if (arr.size() == 1 && arr[0] == key)
    {
        ans[0] = ans[1] = 0;
        return ans;
    }
    while (l <= h)
    {
        m = l + (h - l)/2;
        if (arr[m] >= key)
        {
            h = m-1;
            ans[0] = m;
        }
        else if (arr[m] < key)
        {
            l = m+1;
        }
    }
    if ((ans[0] < arr.size()) && (arr[ans[0]] == key))
    {
        for (int i=ans[0]; (i<arr.size()) && (arr[i] == key); i++)
        {
            ans[1] = i;
        }
        return ans;
    }
    ans[0] = ans[1] = -1;
    return ans;
}