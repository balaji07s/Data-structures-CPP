/******************************************************************************
 * 
 *                      Floor and ceil
 * linear search
 * TC: O(2n)
 * SC: O(1)
 * lower bound
 * TC: O(2logn)
 * SC: O(1)
 ******************************************************************************/

/* Using lower bound */
int findCeil (vector<int> &arr, int key)
{
	int l, m, h;
    l = 0;
    h = arr.size()-1;
    long long ans = -1;
    while (l <= h)
    {
        m = l + (h - l)/2;
        /* To find ceil */
		if (arr[m] >= key)
        {
            h = m-1;
            ans = m;
		} else if (arr[m] < key) {
            l = m + 1;
		}
    }
	if (ans >= arr.size())
		return -1;
    return arr[ans];
}

/* using modified lower bound */
int findFloor (vector<int> &arr, int key)
{
	int l, m, h;
    l = 0;
    h = arr.size()-1;
    long long ans = -1;
    while (l <= h)
    {
        m = l + (h - l)/2;
        /* To find ceil */
		if (arr[m] > key)
        {
            h = m-1;
		} else if (arr[m] <= key) {
            l = m + 1;
			ans = m;
		}
    }
	if (ans < 0)
		return -1;
    return arr[ans];
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int floor, ceil;
	ceil = findCeil(arr, x);
	floor = findFloor(arr, x);
	return make_pair(floor, ceil);
}


int main ()
{
    vector<int> arr = {10, 20, 20, 25, 30, 50, 55, 55, 60};
    int key;
    cin >> key;
    pair<int, int> result;
    result = getFloorAndCeil(arr, arr.size(), key);
}