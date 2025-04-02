#include "stdc++.h"

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size(),i,j,k;
        long long ans=0;
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                for(k=j+1;k<n;k++) {
                    if(i!=j && j!=k && k!=i)
                        ans=max(ans,1ll*(nums[i]-nums[j])*nums[k]);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int>nums={12,6,1,2,7};
    Solution sol;
    cout<<sol.maximumTripletValue(nums)<<endl;
    return 0;
}