// Q-352 https://leetcode.com/problems/data-stream-as-disjoint-intervals/
class SummaryRanges
{
public:
    set<int> values;

    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        values.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (values.empty())
            return {};
        vector<vector<int>> intr;
        int left = -1, right = -1;
        for (int value : values)
        {
            if (left < 0)
                left = right = value;
            else if (value == right + 1)
            {
                right = value;
            }
            else
            {
                intr.push_back({left, right});
                left = right = value;
            }
        }
        intr.push_back({left, right});
        return intr;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */