DESC employees;
# 查询90号部门的员工信息
SELECT * FROM employees
# 过滤条件
WHERE department_id = 90;

SELECT * FROM employees
WHERE last_name  ="King";

SELECT 100+'1' # 隐式转换
FROM DUAL;

SELECT 100+'a'
FROM DUAL;

#取模运算 MOD
SELECT 12%3,12%5,12 MOD -5,-12%5,-12%-5
FROM DUAL;

#员工id为偶数的员工
USE atguigudb;
SELECT first_name,last_name,employee_id
FROM employees
WHERE employee_id%2 = 0;

#比较运算符
SELECT 1=2,1<>2
FROM DUAL;

SELECT 1='1',1='a',0='a	'
FROM DUAL;

SELECT 'ab'='ab','a'='b'
FROM DUAL;

SELECT NULL=NULL;-- 只要有null参与运算……

SELECT last_name,salary,commission_pct
FROM employees
WHERE commission_pct IS NULL;
-- WHERE commission_pct <=>NULL;

SELECT last_name,salary,commission_pct
FROM employees
WHERE ISNULL(commission_pct);

SELECT last_name,salary,commission_pct
FROM employees
WHERE commission_pct IS NOT NULL;

SELECT last_name,salary,commission_pct
FROM employees
WHERE NOT commission_pct <=> NULL;

SELECT LEAST('b','p','h','m'),GREATEST('b','p','h','m')
FROM DUAL;

SELECT first_name,last_name,LEAST(first_name,last_name) AS least_name,
LEAST(LENGTH(first_name),LENGTH(last_name)) AS short_name
FROM employees;

# 查询工资在6000到8000的员工信息
SELECT employee_id,last_name,salary
FROM employees
 -- where salary between 6000 and 8000;
WHERE salary >=6000 && salary<=8000;

SELECT employee_id,last_name,salary
FROM employees
WHERE  salary NOT BETWEEN 6000 AND 8000;

SELECT employee_id,last_name,salary
FROM employees
WHERE salary <6000 || salary > 8000;

# 查询部门为10,20,30部门的员工信息
SELECT last_name,salary,department_id
FROM employees
WHERE department_id = 10 OR 20 OR 30;

SELECT last_name,salary,department_id
FROM employees
WHERE department_id IN (10,20,30);

# 查询工资不是6000，7000,8000，的员工信息
SELECT last_name,salary,department_id
FROM employees
WHERE salary NOT IN (6000,7000,8000);

# LIKE 模糊查询
-- % 代表不确定个数的字符（包含0,1,2，多个都是可以的）
SELECT last_name
FROM employees
WHERE last_name LIKE '%a%';

SELECT last_name
FROM employees
WHERE last_name LIKE 'a%';

# 查询last_name中包含字符'a'且包含字符'e'的员工信息
SELECT last_name
FROM employees
WHERE last_name LIKE '%a%' AND last_name LIKE '%e%';

SELECT last_name
FROM employees
WHERE last_name LIKE '%a%e%' OR last_name LIKE '%e%a%';

# _ 代表一个不确定的字符
# 查询第三个字符是'a'的员工信息
SELECT last_name
FROM employees
WHERE last_name LIKE '__a%';

# 查询第二个字符是_且第三个字符是'a'的员工信息
# 使用转义字符
SELECT last_name
FROM employees
WHERE last_name LIKE '_\_a%';

#或者 使用escape
SELECT last_name
FROM employees
WHERE last_name LIKE '_$_a%' ESCAPE '$';

#REGEXP 正则表达式
SELECT 'sorakado' REGEXP '^s','nanase' REGEXP 'e$','nimosora' REGEXP 'mo'
FROM DUAL;