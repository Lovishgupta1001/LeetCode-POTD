// Q-953 https://leetcode.com/problems/verifying-an-alien-dictionary/
class Solution
{
public:
    unordered_map<char, int> mp;
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!checkbool(words[i], words[i + 1]))
                return false;
        }
        return true;
    }
    bool checkbool(string &a, string &b)
    {
        int i = -1;
        while (++i < a.size() and i < b.size())
            if (mp[a[i]] != mp[b[i]])
                return mp[a[i]] < mp[b[i]];
        return (a.size() <= b.size());
    }
};