#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1);
    if(n==1) return nums[0];
    if(n==2) return nums[1];
    dp[0] = nums[0];
    dp[1] = nums[1];
    int currMax = dp[0];
    int overallMax = max(dp[0] , dp[1]);
    for(int i=2;i<n;i++){
        // dp[i] = max(overallMax , dp[i-1]);
        dp[i] = nums[i] + currMax;
        currMax = max(currMax , dp[i-1]);
        overallMax = max(overallMax , dp[i]);
    }
    return overallMax;
}
