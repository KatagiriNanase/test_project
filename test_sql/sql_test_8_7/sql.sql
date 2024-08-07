# 非等值连接
SELECT e.last_name,e.salary,j.grade_level
FROM employees e,job_grades j
WHERE e.`salary` BETWEEN j.`lowest_sal` AND j.`highest_sal`;

# 练习:查询员工id,员工姓名及其管理者的id和姓名
SELECT e.employee_id,e.last_name,m.employee_id,m.last_name
FROM employees e,employees m
WHERE e.`manager_id`=m.`employee_id`;

#练习:查询所有的员工的last name,department name信息
-- sql92实现内连接：
SELECT e.last_name,d.department_name
FROM employees e,departments d
WHERE e.`department_id`=d.`department_id`

-- sql92实现外连接：+ 哪条腿短了就给他垫高
SELECT e.last_name,d.department_name
FROM employees e,departments d
WHERE e.`department_id`=d.`department_id`(+);
-- 然而MySQL并不支持sql92

#sql99语法中使用 JOIN ... ON 的方式实现多表查询。这种方式也能解决外连接的的问题。Mysql支持
#SQL99实现多表查询

#99实现内连接：
SELECT e.last_name,d.department_name
FROM employees e JOIN departments d
ON e.`department_id`=d.`department_id`;

SELECT e.last_name,d.department_name,city
FROM employees e INNER JOIN departments d
ON e.`department_id`=d.`department_id`
JOIN locations l
ON d.location_id = l.location_id;

# 99实现外连接
-- 左外连接
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`;

-- 右外连接
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`;

-- 满外连接 MySQL不支持FULL OUTER JOIN
SELECT last_name,department_name
FROM employees e FULL OUTER JOIN departments d
ON e.`department_id`=d.`department_id`;

# UNION 和UNION ALL 的使用


#内连接
SELECT last_name,department_name
FROM employees e JOIN departments d
ON e.`department_id`=d.`department_id`;

# 左外连接
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`;

#右外连接
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`;

#左中图 -- ：A - A∩B
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE d.`department_id` IS NULL;

#右中图 -- ：B-A∩B
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE e.`department_id` IS NULL;

#满外连接：
-- 方式一：左外连接 UNION ALL 右中图
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
UNION ALL
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE e.`department_id` IS NULL;

-- 方式二： 左中图 UNION ALL 右外连接
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id` = d.`department_id`
WHERE d.`department_id` IS NULL
UNION ALL
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`;

# 右下图 == 左中图 UNION ALL 右中图
SELECT last_name,department_name
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE d.`department_id` IS NULL
UNION ALL
SELECT last_name,department_name
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE e.`department_id` IS NULL;











