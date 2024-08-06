DESC `employees`;

SELECT employee_id,salary
FROM employees
LIMIT 20;

SELECT employee_id,salary
FROM employees
LIMIT 0,20;
#0~19 20~39 40~59
#第n页 (n-1)*pagesize+1-1

SELECT employee_id,last_name,salary
FROM employees
WHERE salary > 6000
ORDER BY salary DESC
LIMIT 10;

#表里有 107 条数据，我们只想要显示第 32、33 条数据怎么办呢？
SELECT 
  employee_id,
  last_name,
  salary 
FROM
  employees  
LIMIT 31, 2;

SELECT 
  employee_id,
  last_name,
  salary 
FROM
  employees  
LIMIT 2 OFFSET 31;

#查询员工表中工资最高的员工信息
SELECT employee_id,last_name,salary
FROM employees
ORDER BY salary DESC
LIMIT 1;
# 多表查询
DESC departments;
DESC locations;
SELECT * 
FROM locations
WHERE location_id = 2500;
# 出现了笛卡尔积错误
#错误原因： 缺少了多表的连接条件
# 错误的实现方式：每个员工都与每个部门匹配了一遍
SELECT employee_id,department_name
FROM employees,departments
LIMIT 28;

SELECT employee_id,department_name
FROM employees CROSS JOIN departments
LIMIT 28;
# 多表查询的正确方式：需要有连接条件
SELECT employee_id,department_name
FROM employees,departments
# 两个表的连接条件：
WHERE employees.`department_id`=departments.`department_id`;
#如果查询语句中出现了多个表中都存在的字段，则必须指明此字段所在的表
SELECT employee_id,department_name,employees.department_id
FROM employees,departments
WHERE employees.`department_id`=departments.`department_id`;
#建议:从sql优化的角度，建议多表查询时，每个字段前都指明其所在的表。
SELECT employees.employee_id,employees.department_name,employees.department_id
FROM employees,departments
WHERE employees.`department_id`=departments.`department_id`;
# 列的别名
SELECT emp.employee_id,dept.department_name,emp.department_id
FROM employees emp,departments dept
WHERE emp.`department_id`=dept.`department_id`;
#练习:查询员工的employee_id,last_name,department_name,city
SELECT emp.`employee_id`,dept.`department_name`,loc.`city`
FROM employees emp,departments dept,locations loc
WHERE emp.`department_id`=dept.`department_id` 
AND dept.`location_id`=loc.`location_id`
ORDER BY employee_id ASC;

# 非等值连接
SELECT *
FROM job_grades;