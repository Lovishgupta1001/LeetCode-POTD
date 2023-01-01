// Q-290 https://leetcode.com/problems/word-pattern/
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, int> mp;
        map<string, int> ms;

        vector<string> v;
        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            temp += s[i];
            if (s[i + 1] == ' ')
            {
                v.push_back(temp);
                temp = "";
                i++;
                continue;
            }
            if (i == s.size() - 1)
            {
                v.push_back(temp);
                break;
            }
        }
        int i = 0, n = pattern.size();
        if (v.size() != n)
            return false;
        while (i < n)
        {
            if (i == n || mp[pattern[i]] != ms[v[i]])
                return false;
            mp[pattern[i]] = i + 1;
            ms[v[i]] = i + 1;
            i++;
        }
        return i == n;
    }
};