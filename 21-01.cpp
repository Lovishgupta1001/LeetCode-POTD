// Q-93 https://leetcode.com/problems/restore-ip-addresses/
class Solution
{
public:
    bool valid(string s)
    {
        if (s.size() > 3 or s.size() == 0)
            return false;
        if (s.size() > 1 and s[0] == '0')
            return false;
        if (s.size() and stoi(s) > 255)
            return false;
        return true;
    }
    void f(vector<string> &ans, string output, int ind, string s, int dots)
    {
        if (dots == 3)
        {
            if (valid(s.substr(ind)))
            {
                ans.push_back(output + s.substr(ind));
                return;
            }
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (valid(s.substr(ind, i - ind + 1)))
            {
                output.push_back(s[i]);
                output.push_back('.');
                f(ans, output, i + 1, s, dots + 1);
                output.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string res;
        f(ans, res, 0, s, 0);
        return ans;
    }
};