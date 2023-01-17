// Q-926 https://leetcode.com/problems/flip-string-to-monotone-increasing/
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int cf = 0, co = 0;
        for (auto i : s)
        {
            if (i == '1')
                co++;
            else
            {
                cf++;
                cf = min(cf, co);
            }
        }
        return cf;
    }
};