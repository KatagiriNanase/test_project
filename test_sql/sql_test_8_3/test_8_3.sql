-- 单行注释
# mysql特有注释
# 只能用命令行使用source "C:\Users\時愺\Desktop\code_note\MySQL\资料\atguigudb.sql";
SHOW DATABASES;
SELECT * FROM employees;
SELECT 1+2
FROM DUAL;

SELECT * FROM employees;

SELECT last_name AS "name",salary*12 AS "Annual Salary"
FROM employees;

SELECT department_id
FROM employees;

SELECT DISTINCT department_id AS 'dep id'
FROM employees;

SELECT  department_id,DISTINCT salary
FROM employees;

SELECT first_name 'name',salary*(1+commission_pct)*12 '年工资'
FROM employees;

SELECT first_name 'name',salary*(1+IFNULL(commission_pct,0))*12 '年工资'
FROM employees;	

SELECT * FROM `order`;

SELECT 'sorakado' AS corporation, last_name FROM employees;

SELECT 123 ,last_name FROM employees;

DESCRIBE employees; # 显示了表中字段的详细信息

DESC `countries`;

DESC `job_grades`