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

#方式二：