#### 初始化仓库:
- `git init -b 主干名`

#### **克隆仓库：**
- `git clone URL CustomName`  自定义名称可加可不加。

#### **配置仓库:**
  1. 局部配置：
 ```
git config user.name your_name
git config user.email your_email

```
==你要让git知道你是谁，这是必须要配置的名称和邮箱地址==
但是每个仓库都配置一遍的话就太麻烦了，因此我们可以使用我们的**全局配置**   
  2. 全局配置：
```
git config --global user.name your_name 
git config --global user.email your_email
```

#### 查看暂存区状态：
`git status`

#### 提交文件到暂存区:
1. `git add file_name`
2. 若想要提交所有后缀名相同的文件，就用**通配符`*`**
`git add *.txt`

#### 将缓存区的文件放回工作区：
`git rm --cached <file>...`

#### 将文件从暂存区提交到库中
`git commit -m`   
其中`-m`后填写你所需要说明的信息，可以直接写中文不用双引号。

#### 查看历史提交记录：
`git log`   
觉得版本号太长了，可以加上参数
`git log --oneline`

#### 恢复误操作文件：
`git restore file_name`
但是如果你如果已经将最新的删除操作提交了，那就不能用此方法恢复，所以我们用另一种方法：
1. `git log --oneline` 查看提交记录和版本号
2. `git reset --hard 版本号` 重置回指定版本，但是从此版本之后的提价都会消失。
3. `git revert 你想要回到的版本的下一次版本号` revert可以理解为撤销，相当于撤销了删除的操作，同时这次revolt 操作也会被提交，并产生新的版本号。

#### 创建分支
`git branch 分支名`
**注意**：分支是基于提交的，如果你一次都没有提交，那连main都还没有，就创建不了分支了。   

#### 查看分支
`git branch -v`

#### 切换分支
`git checkout 分支名`

#### 一键创建分支+切换分支
`git checkout -b 分支名`

#### 删除分支 
`git branch -d 分支名`

#### 添加标签
  1. `git tag 完整版本号`
  2. **标签的作用：**
     1. 标签相当于版本的别名，每个版本的标题不能相同。
     2. `git log 标签` 获得历史数据的时候，不再是单纯的版本号，而是添加了标签
  3. 创建分支的版本时添加标签：
      `有待商议`

#### 关联远程仓库
首先在config文件中，存在[remote "origin"]配置文件，如若没有，则需进行配置：   
`git remote add origin URl`    
origin是我们给这个远程仓库起的名字，如果我们想给他改名字，则：
`git remote rename 你想改的名字`     
如果想删除这个关联的苍库，那么就：
`git remote remove 仓库名`
想将本地的库上传到远程库，则：
`git push 仓库名`
远程仓库做改动后要同步到本地仓库，则：
`git pull 仓库名`
