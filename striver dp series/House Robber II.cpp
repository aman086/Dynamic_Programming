#include <bits/stdc++.h> 

long long int solution(int index , vector<int> valueInHouse){
    int n = valueInHouse.size();
    valueInHouse[index] = 0;
    vector<long long int> dp(n);
    dp[0] = valueInHouse[0];
    for(int i=1;i<n;i++){
        int pick = valueInHouse[i];
        if(i>1) pick += dp[i-2];
        int not_pick = 0 + dp[i-1];
        dp[i] = max(pick , not_pick);
    }
    return dp[n-1];
}

long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    long long leaveStart = solution(0 , valueInHouse);
    long long leaveEnd = solution(n-1 , valueInHouse);
    return max(leaveStart , leaveEnd);
}
