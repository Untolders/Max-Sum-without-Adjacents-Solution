**********************************************************************************  Question  **************************************************************************************************

Given an array Arr of size N containing positive integers. Find the maximum sum of a any possible subsequence such that no two numbers in the subsequence should be adjacent in Arr.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous subsequence with maximum
sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers Arr and N as parameters and returns an the maximum sum possible of any valid subsequence.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arri ≤ 105



**********************************************************************************  Solution  **************************************************************************************************
  //{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	     int dp[n + 1];
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        dp[2] = max(dp[0] + arr[2], dp[1]);
    
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
        }
        return dp[n - 1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
