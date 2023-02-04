// Q-567 https://leetcode.com/problems/permutation-in-string/
class Solution
{
public:
    bool fun(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        vector<int> f1(26, 0), f2(26, 0);
        if (s1.size() > s2.size())
            return false;
        for (char it : s1)
        {
            f1[it - 'a']++;
        }
        int i = 0, j = 0;
        while (j < s2.size())
        {
            f2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size())
            {
                if (fun(f1, f2))
                    return true;
            }
            if (j - i + 1 < s1.size())
            {
                j++;
            }
            else
            {
                f2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};