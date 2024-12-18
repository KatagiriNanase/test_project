/*
 * @lc app=leetcode.cn id=100 lang=c
 *
 * [100] 相同的树
 *
 * https://leetcode.cn/problems/same-tree/description/
 *
 * algorithms
 * Easy (62.26%)
 * Likes:    1176
 * Dislikes: 0
 * Total Accepted:    621.1K
 * Total Submissions: 997.4K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 *
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：p = [1,2,3], q = [1,2,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：p = [1,2], q = [1,null,2]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：p = [1,2,1], q = [1,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两棵树上的节点数目都在范围 [0, 100] 内
 * -10^4
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)//全为空
        return true;

    if ((!p && q) || (p && !q))//不全为空
        return false;

    if (p->val != q->val)//当前节点不相等则false
        return false;

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));


}
// @lc code=end

