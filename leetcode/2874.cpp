#include "stdc++.h"

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size(),i;
        long long ans=0;
        vector<int>pre(n),suff(n);
        pre[0]=nums[0];
        for(i=1;i<n;i++)
            pre[i]=max(pre[i-1],nums[i]);
        suff[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--)
            suff[i]=max(suff[i+1],nums[i]);
        for(i=1;i<n-1;i++)
            ans=max(ans, 1ll*(pre[i-1]-nums[i])*suff[i+1]);    
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int>nums={12,6,1,2,7};
    cout<<sol.maximumTripletValue(nums)<<endl;
    return 0;
}