# <center>Markdown Study</center>
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 最高支持六级标题 注意#后要加空格

2. > 这是一段引用，用>大于号标识 这一行都有一个竖杠 
>> 还可以进行嵌套！！
>>> 三级嵌套来一手

3. **无序列表**
   - -减号
   + +加号
   * *乘号
   * 他们都能表示列表
      1. 在列表内也能进行列表的嵌套。
      2. 换成罗马的排序了。
      3. 只要在附属列表前加四个空格（tab）就能实现列表的嵌套
      4. ToDoList (代办事件)
           - [x] a
           - [x] b
           - [ ] 点我可以进行打钩
 4. **表格**
    | 左对齐 | 居中对齐 | 右对齐 |
    | :----- | :------: | -----: |
    | a      |    b     |      c |

5. **段落**
   - 换行-- 就是让你md文档中的段落换行，我们不能直接回车，不然就会多出一个空格，而是要两个以上空格后回车/或者空一行   
    
        就像现在我能新起一行！
   - 分割线*** 三个及以上的乘号就行
***

6. **字体**
    |     字体      |    代码    |
    | :-----------: | :--------: |
    |    *斜体*     |    * *     |
    |   ==高亮==    |   == ==    |
    |   **粗体**    |   ** **    |
    | ***斜粗体***  |  *** ***   |
    |   ~~删除~~    |   ~~ ~~    |
    | <u>下划线</u> | `<u> </u>` |

7. **脚注**
    我是一个脚注[^1]！！
    
8. 代码
    - 单句的代码用``就足够了
        - `printf("hello world\n");`
    - 代码块的话就要用三个``````将他包裹起来
       ```
        #include <stdio.h>
        int main()
        {
            printf("hello markdown!\n");
            return 0;
        }
        ```
        ==我发现代码块和列表的相性不是很好哦……==

9. 超链接
    - [我是一个超链接]：https://www.bilibili.com/
    - 也可以换一种[超链接方式](https://www.bilibili.com/)

10. **图床**
    - 使用图床保存图片并实现插入
    [路过凸窗]: https://imgse.com/
[^1]: 这是脚注的解释~只有在文章里写入`[^1]`我才会标注成功！