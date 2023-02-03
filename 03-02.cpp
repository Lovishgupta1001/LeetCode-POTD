// Q-6 https://leetcode.com/problems/zigzag-conversion/
class Solution
{
public:
    string convert(string s, int nrow)
    {
        if (nrow <= 1)
            return s;
        int n = s.size();
        string res = "";
        int cycle = 2 * nrow - 2;
        for (int i = 0; i < nrow; i++)
        {
            for (int j = i; j < n; j = j + cycle)
            {
                res = res + s[j];
                int secondj = (j - i) + cycle - i;
                if (i != 0 && i < nrow - 1 && secondj < n)
                {
                    res = res + s[secondj];
                }
            }
        }
        return res;
    }
};