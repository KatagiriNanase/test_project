/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (58.81%)
 * Likes:    1556
 * Dislikes: 0
 * Total Accepted:    656.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是 平衡二叉树  
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 <= Node.val <= 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int BiTreeDepth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int left = BiTreeDepth(root->left);
    int right = BiTreeDepth(root->right);

    return 1 + (left > right?left : right);

    
}
bool isBalanced(struct TreeNode* root)
{
    if (!root)
        return true;

    if (!isBalanced(root->left))
        return false;

    if (!isBalanced(root->right))
        return false;

    if (abs(BiTreeDepth(root->left) - BiTreeDepth(root->right)) > 1)
        return false;

    return true;

    
}
// @lc code=end

