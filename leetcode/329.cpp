#include "stdc++.h"

class Solution {
public:
    int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
    int dp[1001][1001];
    int solve(int r, int c, vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),x,y,k,ans=0;
        if(dp[r][c]!=0)
            return dp[r][c];
        for(k=0;k<4;k++) {
            x=r+dir[k][0];
            y=c+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<m && matrix[x][y]>matrix[r][c]) {
                ans=max(ans,1+solve(x,y,matrix));
            }
        }
        return dp[r][c]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),i,j,ans=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                ans=max(ans,1+solve(i,j,matrix));
            }
        }
        return ans;
    }
};

int main() {
	Solution sol;
	vector<vector<int>>nums={{9,9,4},{6,6,8},{2,1,1}};
	cout<<sol.longestIncreasingPath(nums)<<endl;
	return 0;
}