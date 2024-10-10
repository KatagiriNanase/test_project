-- 局部变量的声明和赋值
DECLARE @a AS int,
@b int,
@sum int
SET
    @a = 10
SET
    @b = 20
SET
    @sum = @a + @b print @sum
    -- DECLARE @avgscore AS float,@sumscore AS float
    -- SELECT @avgscore = avg(成绩), @sumscore = sum(成绩)
    -- FROM 学生
    --     INNER JOIN 选修 ON 学生.学号 = 选修.学号
    -- WHERE
    --     性别 = '男'
    -- 信息打印
    print 'hello sql!'
SELECT 'hello sql!'
    --变量：（1）局部变量 （2）全局变量
    -- 局部 @
    DECLARE @str varchar(15)
    --set @str ='I like sql'
SELECT @str = 'I like sql'
    -- 全局@@

if(select avg(成绩) from 选修 where 学号='19010101')>=60
begin 
    print '该同学通过全部考试，没有挂科'
end    

-- 判断教师本校工龄是否在30年以上
if(select datediff(year,工作日期,getdate()) >=30 from 教师 where 姓名='李老师')
    print '超过30年'
else
    print '未超过30年'

-- 判断是否存在记录
if exists (select * from 课程 where 课程类别 ='考察')
    select count(*) as 考查课数量 from 课程 where  课程类别 ='考察'        
else
    print '没有考查课'    

--求1-100的奇数之和
DECLARE @i int,@sum
set @i=1
set @sum=0
while(@i<100)
begin 
    @sum=@sum+@1
    @i=@i+2
end
print '奇数之和为'+convert(char(6),@sum)        

--fsum，求两个数的和
create function fsum(@a int,@b int)
returns int
begin 
    return @a+@b
end
go




