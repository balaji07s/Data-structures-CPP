/******************************************************************************

            Find the non duplicate element in a sorted array
TC: O(log n)
SC: O(1)
*******************************************************************************/

int singleNonDuplicate(vector<int>& arr) {
    int l = 0, h = arr.size()-1;
    if (arr.size() == 1)
        return arr[0];
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (((m-1) < 0) && arr[m+1] != arr[m])
        {
            return arr[m];
        }
        else if ((m+1) == arr.size() && arr[m-1] != arr[m])
        {
            return arr[m];
        }
        else if ((m+1) < arr.size() && (m-1) > 0)
        {
            if (arr[m+1] != arr[m] && arr[m-1] != arr[m])
                return arr[m];
        }
        if ((m%2 != 0) && (arr[m] == arr[m-1]) ||
                (m%2 == 0) && (arr[m] == arr[m+1]))
        {
            l = m + 1;
        } else {
            h = m - 1;
        } 
    }
    return -1;
}


int main ()
{
    vector<int> arr = {1, 2, 2, 3, 3, 4, 4};
    cout << singleNonDuplicate (arr) << endl;
}