/******************************************************************************

                                Pascal's triangle
Question 1:
Return the element present in the given row and column
BF:
TC: 
SC: 
OS:
TC: 
SC: 
Question 2:
Return the Nth row
BF:
TC: 
SC: 
OS:
TC: 
SC: 
Question 3:
Return the n * m pascal's triangle
BF:
TC: 
SC: 
OS:
TC: 
SC: 
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Question 1 */
/* Return the element present in given row and column */
/* Brute force */
int factorialRecursive (int n)
{
    if (n == 1 || n == 0)
        return 1;
    return factorialRecursive(n - 1) * n;
}
// int nThELementInpascalsTriangle (int row, int column)
// {
//     int n = row - 1, r = column - 1;
//     return factorialRecursive(n)/(factorialRecursive(r) * factorialRecursive(n-r));
// }

/* Optimal solution */
int factorialIterative (int n, int r)
{
    int result = 1;
    for (int i = 0; i<r; i++)
    {
        result = (n - i) * result;
    }
    return result;
}

int nThELementInpascalsTriangle (int row, int column)
{
    int n = row-1, r = column - 1;
    return factorialIterative(n, r)/factorialIterative(r, r);
}

/* Question 2 */
/* Return the Nth row */
/* Brute force */
// vector<int> nThRowInpascalsTriangle (int n)
// {
//     vector<int> result;
//     for (int i=1; i<=n; i++)
//     {
//         /* n is row and i is column */
//         result.push_back(nThELementInpascalsTriangle(n, i));
//     }
//     return result;
// }

/* Optimal Solution */
vector<int> nThRowInpascalsTriangle (int n)
{
    vector<int> result;
    long long ans = 1, prevAns;
    result.push_back(1);
    for (int i=1; i<n; i++)
    {
        prevAns = ans;
        ans = ((prevAns * (n-i))/i);
        cout << i <<" " << prevAns << " " <<  ans << endl;
        result.push_back(ans);
    }
    return result;
}

/* Question 3 */
vector<vector<int>> pascalsTriangle (int n)
{
    vector<vector<int>> result;
    for (int i=1; i<=n; i++)
    {
        result.push_back(nThRowInpascalsTriangle(i));
    }
    return result;
}


int main()
{
    /* Question 1 */
    // int row, col;
    // cout << "Enter the row ";
    // cin >> row;
    // cout << "Enter the column ";
    // cin >> col;
    
    // cout << nThELementInpascalsTriangle(row, col) << endl;

    /* Question 2 */
    int n;
    // vector<int> result;
    cin >> n;
    // result = nThRowInpascalsTriangle (n);
    // for (auto x : result)
    // {
    //     cout << x << " ";
    // }
    
    /* Question 3 */
    vector<vector<int>> result;
    result = pascalsTriangle (n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}