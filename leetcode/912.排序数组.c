/*
 * @lc app=leetcode.cn id=912 lang=c
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (48.60%)
 * Likes:    1039
 * Dislikes: 0
 * Total Accepted:    697.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void InsertSort(int* a, int n)
{
    assert(a);

    for (int i = 0;i <= n - 2;i++)//end 只循环到(n-1)-1的下标中，不然后续访问a[end+1]就会越界
    {   //把第end个有序插入到已经有序的[0,end]数组中
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
                break;
        }
        a[end + 1] = tmp;
    }
}


int* sortArray(int* a, int n, int* returnSize)
{
    *returnSize = n;
    int gap = n;
    while (gap > 1)
    {
        //预排序
        gap = gap / 3 + 1;//+1保证了最后一次的gap一定是1，就能进行直接插入排序了
        for (int i = 0;i <= n - 1 - gap;i++)//后gap个已经不需要被排序了
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                    break;
            }
            a[end + gap] = tmp;

        }

    }
    InsertSort(a, n);
    return a;
}
// @lc code=end

