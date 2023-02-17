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
    TreeNode *prev = NULL;
    void fun(TreeNode *root, int &ans)
    {
        if (!root)
            return;
        if (root->left)
            fun(root->left, ans);
        if (prev != NULL)
            ans = min(ans, abs(prev->val - root->val));
        prev = root;
        if (root->right)
            fun(root->right, ans);
    }
    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX;
        fun(root, ans);
        return ans;
    }
};