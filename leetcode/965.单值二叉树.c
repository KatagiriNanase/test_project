/*
 * @lc app=leetcode.cn id=965 lang=c
 *
 * [965] 单值二叉树
 *
 * https://leetcode.cn/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (69.76%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    94.8K
 * Total Submissions: 135.9K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 *
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[2,2,2,5,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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

bool isUnivalTree(struct TreeNode* root)
{
    if (!root)
        return true;
    //当前树
    if (root->left && root->val != root->left->val)
        return false;
    if (root->right && root->val != root->right->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
// @lc code=end

