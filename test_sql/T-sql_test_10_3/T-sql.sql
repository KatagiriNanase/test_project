use jxgl;


create table 班级(
id int PRIMARY key
)

ALTER table 班级
add  班主任 varchar(6) constraint uk_班主任 unique;

alter 学生
add 邮政编码 char(6) check(邮政编号 like '2306[0-9][0-9]');

select  *
from 学生
where 姓名 like '[陈-方,许-张]%';


select * 
from 图书
where 类别 like '[^管]%';

select * into 计算机图书
from 图书
where 类别 ='计算机';

select * from 计算机图书;

drop table 计算机图书;

alter table 借阅
alter column 借书日期 date;

select getdate();
