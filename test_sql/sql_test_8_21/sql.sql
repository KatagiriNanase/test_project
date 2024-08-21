#查询员工中工资大于本部门平均工资的员工的last_name,salary和其department_id
#方式二:在from中声明子查询
SELECT last_name,salary,e.department_id
FROM employees e LEFT JOIN (
			SELECT department_id,AVG(salary) avg_sal
			FROM employees
			GROUP BY department_id	
			) t_dept_avg_sal
ON e.`department_id`=t_dept_avg_sal.department_id
WHERE e.`salary`>t_dept_avg_sal.avg_sal;

	
#order by 中的子查询
#查询员工的id,salary,按照department_name 排序
#方式一：多表查询
SELECT employee_id,salary
FROM employees e LEFT JOIN departments d
ON e.`department_id`=d.`department_id`
ORDER BY d.`department_name`;

#方式二：子查询
SELECT employee_id,salary
FROM employees e1
ORDER BY (
	SELECT department_name 
	FROM departments d
	WHERE e1.`department_id`=d.`department_id`
	) ASC;

#：若employees表中employee_id与job_history表中employee_id相同的数目不小于2，输出这些相同
#id的员工的employee_id,last_name和其job_id
SELECT employee_id,last_name,job_id
FROM employees e
WHERE 2<=(
	SELECT COUNT(1)
	FROM job_history j
	WHERE e.`employee_id`=j.`employee_id`
	);	
#查询公司管理者的employee_id，last_name，job_id，department_id信息
#方式一：多行子查询
SELECT e.employee_id,e.last_name,e.job_id,e.department_id
FROM employees e
WHERE employee_id IN(
			SELECT manager_id
			FROM employees m
			);

#方式二：自连接
SELECT DISTINCT m.employee_id,m.last_name,m.job_id,m.department_id
FROM employees e JOIN employees m
ON e.`manager_id`=m.`employee_id`;	

#方式三：exists
SELECT e1.employee_id,e1.last_name,e1.job_id,e1.department_id
FROM employees e1
WHERE EXISTS (
		SELECT 1
		FROM employees e2
		WHERE e1.`employee_id`=e2.`manager_id`
		);

#查询departments表中，不存在于employees表中的部门的department_id和department_name
SELECT department_id,department_name
FROM departments d
WHERE NOT EXISTS (
		SELECT 1
		FROM employees e
		WHERE e.`department_id`=d.`department_id`
		);
		
SELECT d.department_id,d.department_name
FROM departments d LEFT JOIN employees e
ON d.`department_id`=e.`department_id`
WHERE e.`employee_id` IS NULL;		



 		