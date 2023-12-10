/******************************************************************************

                    Spiral traversal of matrix
OS:
TC: O(n * m)
SC: O(n) -> result
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Optimal solution 
Only one solution is there that is optimal
*/
vector<int> spiralTraversalOfMatrix (vector<vector<int>> &arr)
{
    int top = 0,
        right = arr[0].size()-1,
        left = 0,
        bottom = arr.size()-1;
    vector<int> resMat;
        
    while (top <= bottom && left <= right)
    {
        // print right to left
        for (int i=left; i<=right; i++)
        {
            resMat.push_back(arr[top][i]);
        }
        top++;
        // print top to bottom
        for (int i=top; i<=bottom; i++)
        {
            resMat.push_back(arr[i][right]);
        }
        right--;
        // print right to left
        if (top <= bottom)
        {
            for (int i=right; i>=left; i--)
            {
                resMat.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        // print bottom to top
        if (left <= right)
        {
            for (int i=bottom; i>=top; i--)
            {
                resMat.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return resMat;
}


int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9},
                     {10, 11, 12},
                     {13, 14, 15}};

    cout << mat.size() << endl;
    cout << mat[0].size() << endl;
    
    spiralTraversalOfMatrix (mat);

    return 0;
}