USE test15_pro_func;

SET GLOBAL log_bin_trust_function_creators = 1;

#3. 创建存储过程date_diff()，实现传入两个女神生日，返回日期间隔大小
--创建
delimiter / /

create PROCEDURE date_diff(in birth1 date,in birth2 date,out diff int)
begin
    set diff = abs(datediff(birth1,birth2) );
end //

delimiter;
--调用
SET @birth1 = '1982-02-12';

SET @birth2 = '1988-12-09';

CALL date_diff (@birth1, @birth2, @result);

SELECT @result;
#4. 创建存储过程format_date(),实现传入一个日期，格式化成xx年xx月xx日并返回
DELIMITER / /

create PROCEDURE format_date(IN date_val date,out strdate varchar(25))
begin 
    select DATE_FORMAT(date_val,'%y年%m月%d日') into strdate;
end
DELIMITER;

SET @my_date = now();

CALL format_date (@my_date, @my_strdate);

SELECT @my_strdate;
#5. 创建存储过程beauty_limit()，根据传入的起始索引和条目数，查询女神表的记录
DELIMITER / /

create procedure beauty_limit(in start_index int,in size int)
begin
    select * from  beauty limit start_index,size;
end //

DELIMITER;

CALL beauty_limit (1, 3);

#创建带inout模式参数的存储过程

#6. 传入a和b两个值，最终a和b都翻倍并返回
DELIMITER / /

create PROCEDURE double_val(inout a float(10,2),inout b float(10,2))
begin
    set a:=a*2;
    set b:=b*2;
end //

DELIMITER;

SET @a = 1;

SET @b = 2;

CALL double_val (@a, @b);

SELECT @a, @b;

#7. 删除题目5的存储过程
DROP PROCEDURE beauty_limit;

#8. 查看题目6中存储过程的信息
SHOW CREATE PROCEDURE double_val;

SHOW PROCEDURE STATUS LIKE 'double_val';

#存储函数练习

#0. 准备工作
USE test15_pro_func;

CREATE TABLE employees AS SELECT * FROM atguigudb.`employees`;

CREATE TABLE departments AS SELECT * FROM atguigudb.`departments`;

#无参有返回
#1. 创建函数get_count(),返回公司的员工个数
DELIMITER / /

create Function get_count()
returns int
begin
    return (select count(*) from employees);
end //

DELIMITER;

SELECT get_count ();
#有参有返回
#2. 创建函数ename_salary(),根据员工姓名，返回它的工资
DELIMITER / /

create FUNCTION ename_salary(emp_name varchar(20))
returns DECIMAL(10,2)
begin 
    return (select salary from employees where last_name =emp_name);
end //

DELIMITER;

SELECT ename_salary ('abel');

#3. 创建函数dept_sal() ,根据部门名，返回该部门的平均工资
SELECT * FROM employees;

DELIMITER / /

create FUNCTION dept_sal(dname varchar(20))
returns DECIMAL(10,2)
begin
    DECLARE dept_id int;
    select department_id into dept_id from departments where department_name =dname;
    return (select avg(salary) from employees where department_id =dept_id);
end //

DELIMITER;

SELECT dept_sal ('Marketing');

#4. 创建函数add_float()，实现传入两个float，返回二者之和
DELIMITER / /

create Function add_float(a float(10,2),b float(10,2))
returns float(10,2)
begin 
    return (a+b);
end //

DELIMITER;

SELECT add_float (10, 20);

DELIMITER //
create Function test()
returns text
begin 
    return ('就喜欢sublime text低帧的感觉！');
end //
DELIMITER ;    

select test();
