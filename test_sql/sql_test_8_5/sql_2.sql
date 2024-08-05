# 第五章_排序与分页
SELECT * FROM employees;
# 按照salary从高到低的顺序显示员工信息
-- 使用ORDER BY 对查询到的数据进行排序
SELECT last_name,salary
FROM employees
ORDER BY salary DESC;
# 按照salary从低到高的顺序显示员工信息
SELECT last_name,salary
FROM employees
ORDER BY salary ASC;
# 结合列的别名进行排序
SELECT last_name,salary*12 annual_salary
FROM employees
ORDER BY annual_salary ASC;

SELECT last_name,salary*12 annual_salary
FROM employees
WHERE annual_salary >30000;
# 显示员工信息，按照department id的降序排列，salary的升序排列
SELECT employee_id,salary,department_id
FROM employees
ORDER BY department_id ,salary ASC;

#分页
-- 关键字 LIMIT
# 需求：每页显示20条记录，此时显示第一个页
SELECT employee_id,last_name
FROM employees
LIMIT 0,20;
