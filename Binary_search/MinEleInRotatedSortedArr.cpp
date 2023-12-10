/******************************************************************************

            Find the minimum element in a rotated sorted array [Unique elements]
TC: O(log n)
SC: O(1)
*******************************************************************************/

int findMin(vector<int>& nums) {
    int l =0, h = nums.size()-1;
    int minele = INT_MAX;
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (nums[l] <= nums[h])
        {
            minele = min(minele, nums[l]);
            break;
        }
        if (nums[l] <= nums[m])
        {
            minele = min(minele, nums[l]);
            l = m + 1;
        }
        else
        {
            minele = min(minele, nums[m]);
            h = m - 1;
        }
    }
    return minele;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int key;
    cin >> key;
    cout << findMin (arr) << endl;

    return 0;
}