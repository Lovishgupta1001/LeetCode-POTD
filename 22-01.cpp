// Q-131 https://leetcode.com/problems/palindrome-partitioning/
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        fun(0, s, path, ans);
        return ans;
    }
    void fun(int index, string s, vector<string> &path, vector<vector<string>> &ans)
    {
        if (index == s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPal(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                fun(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
    bool isPal(string s, int i, int j)
    {
        while (i <= j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};