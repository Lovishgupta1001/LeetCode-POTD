//Q-918 https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=-1e9;
        for(auto it:nums){
            sum+=it;
            ans=max(ans,sum);
            if(sum<0)
                sum=0;
        }
        sum=0;
        vector<int>maxTill(n);
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxTill[i]=max(i>0?maxTill[i-1]:nums[i],sum);
        }
        
        int curr=0;
        for(int i=n-1;i>=1;i--){
            curr+=nums[i];
            ans=max(ans,maxTill[i-1]+curr);
        }
        return ans;
    }
};