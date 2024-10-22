/*
 * @lc app=leetcode.cn id=572 lang=c
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode.cn/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (48.66%)
 * Likes:    1100
 * Dislikes: 0
 * Total Accepted:    232K
 * Total Submissions: 476.8K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 *
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true
 * ；否则，返回 false 。
 *
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
 *
 *
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
  //比较两颗二叉树是否相同
bool isSame(struct TreeNode* p, struct TreeNode* q)
{
    if (!q && !p)//根节点都为空则true
        return true;

    if ((!q && p) || (q && !p))//结构不同则为false
        return false;

    if (q->val != p->val)//值不同则为false
        return false;

    return (isSame(p->left, q->left) && isSame(p->right, q->right));
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root && !subRoot)
        return true;

    if ((!root && subRoot) || (root && !subRoot))//结构不同则为false
        return false;

    if (isSubtree(root->left, subRoot))
        return true;

    if (isSubtree(root->right, subRoot))
        return true;

    if (isSame(root, subRoot))
        return true;

    return false;

}
// @lc code=end

