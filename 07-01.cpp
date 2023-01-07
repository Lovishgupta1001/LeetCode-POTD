// Q-134 https://leetcode.com/problems/gas-station/
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int currgas = 0, totalgas = 0, sInd = 0;

        for (int i = 0; i < gas.size(); i++)
        {

            currgas += gas[i] - cost[i];
            totalgas += gas[i] - cost[i];

            if (currgas < 0)
            {
                sInd = i + 1;
                currgas = 0;
            }
        }
        return (totalgas >= 0 ? sInd : -1);
    }
};