// Q-1962 https://leetcode.com/problems/remove-stones-to-minimize-the-total/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        for(auto it:piles){
            pq.push(it);
        }
        while(k){
            int t=pq.top();
            pq.pop();
            t-=floor(t/2);
            pq.push(t);
            k--;
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};