// Q-2389 https://leetcode.com/problems/longest-subsequence-with-limited-sum/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        // sort(q.begin(),q.end());
        // 1 2 4 5 
        int sum=0;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        int i=0;
        while(i<q.size()){
            int j=0;
            while(j<nums.size() and nums[j]<=q[i])
                j++;
            ans.push_back(j);
            i++;
        }
        return ans;
    }
};