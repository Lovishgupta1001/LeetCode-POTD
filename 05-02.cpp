// Q-438 https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution
{
public:
    bool cmp(map<char, int> &mp, map<char, int> &ms)
    {
        for (auto it : mp)
        {
            if (ms[it.first] != it.second)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        int i = 0, j = 0;
        map<char, int> mp, ms;
        vector<int> ans;

        for (auto it : p)
        {
            mp[it]++;
        }
        int n = s.size();
        int nn = p.size();
        while (j < n)
        {
            ms[s[j]]++;
            if (j - i + 1 < nn)
                j++;
            else
            {
                if (cmp(mp, ms))
                {
                    ans.push_back(i);
                }
                ms[s[i]]--;
                i++;
                j++;
            }
        }
        return ans;
    }
};