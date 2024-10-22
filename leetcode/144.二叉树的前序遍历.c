/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (72.35%)
 * Likes:    1284
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 *
 * 输出：[1,2,3]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * 输出：[1,2,4,5,6,7,3,8,9]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1]
 *
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */
int BiTreeSize(struct TreeNode* root)
{
    if (!root)
        return 0;
    return BiTreeSize(root->left) + BiTreeSize(root->right) + 1;
}

void PreOrder(struct TreeNode* root, int* ret_arr, int* count)
{
    if (!root)
        return;
    ret_arr[(*count)++] = root->val;//访问根节点
    PreOrder(root->left, ret_arr, count);
    PreOrder(root->right, ret_arr, count);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = BiTreeSize(root);
    int count = 0;
    int* ret_arr = (int*)malloc(sizeof(int) * (*returnSize));
    PreOrder(root, ret_arr, &count);
    return ret_arr;

}
// @lc code=end

