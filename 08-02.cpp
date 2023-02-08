class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return 0;
        
        vector<int>vis(n,0);
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=1;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int ind=it.first;
            int step=it.second;
            int move=nums[ind];
            
            if(ind==n-1)    return step;
            
            for(int j=ind;j<=ind+move;j++){
                if(j >= n)
                    break;
                
                else if(!vis[j]){
                    vis[j]=1;
                    q.push({j,step+1});
                }
            }
        }
        return -1;
    }
};