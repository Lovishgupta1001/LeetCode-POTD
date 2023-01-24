// Q-909 https://leetcode.com/problems/snakes-and-ladders/
class Solution
{
public:
    vector<int> calc(int row, int nextstep)
    {
        int x = (nextstep - 1) / row;
        int y = (nextstep - 1) % row;
        if (x % 2 == 1)
            y = row - y - 1;
        x = row - x - 1;
        return {x, y};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int r = board.size();
        queue<int> q;
        q.push(1);
        int step = 0;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int t = q.front();
                q.pop();
                if (t == r * r)
                    return step;
                for (int i = 1; i <= 6; i++)
                {
                    int nextstep = t + i;
                    if (nextstep > r * r)
                        break;
                    auto v = calc(r, nextstep);
                    int x = v[0], y = v[1];
                    if (board[x][y] != -1)
                    {
                        nextstep = board[x][y];
                    }
                    if (board[x][y] != r * r + 1)
                    {
                        q.push(nextstep);
                        board[x][y] = r * r + 1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};