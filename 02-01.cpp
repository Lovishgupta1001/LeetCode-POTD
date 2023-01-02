// Q-520 https://leetcode.com/problems/detect-capital/submissions/
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (isupper(word[i]))
                count++;
        }
        if (count == 1 and isupper(word[0]))
            return true;
        if (count == 0 or count == n)
            return true;
        else
            return false;
    }
};