/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        int flag = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (flag == 0)
            {
                flag = 1;
                ans.push_back(v);
            }
            else
            {
                flag = 0;
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};