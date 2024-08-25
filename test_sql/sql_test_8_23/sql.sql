#创建数据库
#方式一：
CREATE DATABASE mytest1;
SHOW DATABASES;
SHOW CREATE DATABASE mytest1;

#方式二：
CREATE DATABASE mytest2 CHARACTER SET 'gbk';
SHOW CREATE DATABASE mytest2;

#方式三：
CREATE DATABASE IF NOT EXISTS mytest2;

#管理数据库：
#查看指定库下的所有表：
SHOW TABLES FROM atguigudb;

USE mysql;
SHOW TABLES;

#查看当前使用的数据库
SELECT DATABASE();

#修改字符集
ALTER DATABASE mytest1 CHARACTER SET 'utf8mb4';
ALTER DATABASE mytest2 CHARACTER SET 'utf8';

#删除数据库
-- 方式一：
DROP DATABASE mytest1;

-- 方式二：
DROP DATABASE IF EXISTS mytest1;

DROP DATABASE IF EXISTS mytest2;

#创建表：
#方式一：
CREATE TABLE IF NOT EXISTS myemp1(
id INT,
emp_name VARCHAR(15),
hire_date DATE
);

#方式二：基于现有的表创建，并导入数据：
CREATE TABLE IF NOT EXISTS myemp2
AS 
SELECT employee_id,last_name,salary
FROM employees
WHERE 1=2;

DESC myemp2;
DROP TABLE myemp2;

CREATE TABLE IF NOT EXISTS myemp3
AS 
SELECT e.employee_id,e.last_name,d.department_name
FROM employees e JOIN departments d
ON e.department_id=d.department_id;

SELECT * FROM myemp3;
DESC myemp3;

#练习：创建一个表employees blank，实现对employees表的复制，不包括表数据
CREATE TABLE IF NOT EXISTS employees_blank
AS
SELECT * FROM employees
WHERE 1=2;

SELECT * FROM employees_blank;

#修改表：alter table 
DESC myemp3;
-- 添加字段：
ALTER TABLE myemp3
ADD salary DOUBLE(10,2);

ALTER TABLE myemp3
ADD phone_num VARCHAR(20) FIRST;

