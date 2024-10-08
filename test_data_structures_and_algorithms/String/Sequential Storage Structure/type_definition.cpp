#include "type_definition.hpp"

#include "windows.h"

// int IndexStringBF(SString S, SString T)
// {
//     int i = 1, j = 1;//定义双指针
//     while (i <= S.length)//遍历完主串
//     {
//         if (S.ch[i] != T.ch[j])
//         {
//             i++;
//             continue;
//         }
//         if (S.ch[i] == T.ch[j])//S串中有与T中第一个字符匹配上的话
//         {
//             while (j <= T.length)
//             {
//                 i++, j++;
//                 if (S.ch[i] != T.ch[j])//匹配到不相等的就回溯
//                 {
//                     i = i - j + 1;
//                     j = 1;
//                     break;
//                 }
//                 if (j == T.length)//如果j已经到了最后一个字符还没有break的话
//                     return i - T.length + 1;
//             }
//         }
//     }
//     return -1;
// }

int IndexStringBF(SString S, SString T, int pos)
{
    int i = pos, j = 1;
    while (i <= S.length && j <= T.length)//让两个下标其中之一走到底
    {
        if (S.ch[i] == T.ch[j])//如果相等的话就继续比较
            i++, j++;
        else//不相等的话i，j回溯
        {
            i = i - j + 1;//此时的i已经从原来的位置自加1了
            j = 1;
        }
    }
    if (i > S.length)//i走到底了，没匹配上子串
        return -1;
    if (j > T.length)//j走到底了，匹配上了
        return i - T.length;
}

void GetNext(SString T, int(&next)[])
{
    int i = 1;next[1] = 0;int j = 0;
}

int IndexStringKMP(SString S, SString T, int pos)
{
    int i = pos, j = 1, next[T.length];
    GetNext(T, next);
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] = T.ch[i])
            i++, j++;
        else
            j = next[j];//只有j需要回溯
    }
    if (i > S.length)//i走到底了，没匹配上子串
        return -1;
    if (j > T.length)//j走到底了，匹配上了
        return i - T.length;
}


