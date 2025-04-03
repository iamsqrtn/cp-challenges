#include "stdc++.h"

class Solution {
public:
    vector<long long>dp;
    long long solve(int idx, vector<vector<int>>& questions) {
        int n=questions.size(),i;
        long long take=0,notake=0;
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        take=questions[idx][0]+solve(idx+questions[idx][1]+1, questions);
        notake=solve(idx+1, questions);
        return dp[idx]=max(take, notake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        dp.resize(n, -1);
        return solve(0, questions);
    }
};

int main() {
    Solution sol;
    vector<vector<int>>questions={{3,2},{4,3},{4,4},{2,5}};
    cout<<sol.mostPoints(questions)<<endl;
    return 0;
}