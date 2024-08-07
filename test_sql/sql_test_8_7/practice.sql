DESC employees;
DESC departments;
DESC locations;
DESC jobs;
SELECT * FROM jobs;
# 1.显示所有员工的姓名，部门号和部门名称。
SELECT e.last_name,d.department_id,d.department_name -- 左外连接
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
UNION ALL
SELECT e.last_name,d.department_id,d.department_name -- 右半图
FROM employees e RIGHT JOIN departments d
ON e.`department_id`=d.`department_id`
WHERE e.`department_id` IS NULL;
# 2.查询90号部门员工的job_id和90号部门的location_id
SELECT e.job_id,l.location_id
FROM employees e JOIN departments d
ON e.`department_id`=d.`department_id`
JOIN locations l
ON d.`location_id` =l.`location_id`
WHERE d.`department_id`=90;
# 3.选择所有有奖金的员工的 last_name , department_name , location_id , city
SELECT e.last_name,d.department_name,l.location_id -- 每次都左外连接，保证所有员工都在表内
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
LEFT JOIN locations l
ON d.`location_id`=l.`location_id`
WHERE e.`commission_pct` IS NOT NULL;
# 4.选择city在Toronto工作的员工的 last_name , job_id , department_id , department_name 
SELECT e.last_name,e.`job_id`,d.`department_id`,d.`department_name`
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
LEFT JOIN locations l
ON d.`location_id`=l.`location_id`
WHERE l.`city`="Toronto";
# 5.查询员工所在的部门名称、部门地址、姓名、工作、工资，其中员工所在部门的部门名称为’Executive
SELECT d.department_name AS Executive,l.street_address,e.first_name,e.last_name,j.job_title,e.salary
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
LEFT JOIN locations l
ON d.`location_id`=l.`location_id`
LEFT JOIN jobs j
ON e.`job_id`=j.`job_id`;
# 6.选择指定员工的姓名，员工号，以及他的管理者的姓名和员工号，结果类似于下面的格式

# 7.查询哪些部门没有员工 -- 左表部门，右表员工 左半图
SELECT d.department_name,e.employee_id
FROM departments d LEFT JOIN employees e
ON d.`department_id`=e.`department_id`
WHERE e.`employee_id` IS NULL;
# 8. 查询哪个城市没有部门 -- 左半图
SELECT l.city,d.department_name
FROM locations l LEFT JOIN departments d
ON l.`location_id`=d.`location_id`
WHERE d.`department_name` IS NULL;
# 9. 查询部门名为 Sales 或 IT 的员工信息
SELECT * 
FROM employees e JOIN jobs j
ON e.`job_id`=j.`job_id`;