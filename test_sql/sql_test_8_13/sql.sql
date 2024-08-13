# 聚合函数

#常见的聚合函数
# 1.avg/sum :只适用于数值类型的字段（或变量）
SELECT ROUND(AVG(salary),2),SUM(salary)
FROM employees;
-- 无意义操作
SELECT SUM(last_name),SUM(hire_date)
FROM employees;

#1.2 max/min 适用于数值类型，字符串类型，日期时间类型的字段（或变量）
SELECT MAX(salary),MIN(salary)
FROM employees;

SELECT MAX(last_name),MIN(last_name),MAX(hire_date),MIN(hire_date)-- 字符串用ASCII码值进行比较
FROM employees;

SELECT COUNT(employee_id) ,COUNT(salary),COUNT(salary*2),COUNT(1),COUNT(2),COUNT(*)
FROM employees;

#计算表中有多少天条数据的方法：
-- 方式一：count(1)
-- 方式二：count(*)
-- 方式三：count(具体字段）存在null，不一定对，不要用了	
SELECT COUNT(commission_pct)
FROM employees;

SELECT AVG(commission_pct),SUM(commission_pct)/COUNT(commission_pct),SUM(commission_pct)/107
FROM employees;

# 查询公司的平均奖金率
SELECT AVG(1*12)
FROM DUAL;





