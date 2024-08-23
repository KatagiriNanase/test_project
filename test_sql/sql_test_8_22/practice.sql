#1.查询和Zlotkey相同部门的员工姓名和工资
#子查询：
SELECT last_name,salary
FROM employees
WHERE department_id=(
			SELECT department_id
			FROM employees
			WHERE last_name='Zlotkey'
			);
#自连接：			
SELECT e1.last_name,e1.salary
FROM employees e1 JOIN employees e2
ON e2.`last_name`='Zlotkey'
WHERE e1.`department_id`=e2.`department_id`;
	
			
#2.查询工资比公司平均工资高的员工的员工号，姓名和工资。
SELECT employee_id,last_name,salary
FROM employees
WHERE salary>(
SELECT AVG(salary)
FROM employees
);
#3.选择工资大于所有JOB_ID = 'SA_MAN'的员工的工资的员工的last_name, job_id, salary
SELECT last_name,job_id,salary
FROM employees
WHERE salary>ALL(
SELECT salary
FROM employees
WHERE job_id="SA_MAN"
);
 #4.查询和姓名中包含字母u的员工在相同部门的员工的员工号和姓名
SELECT employee_id,last_name
FROM employees
WHERE department_id IN(
			SELECT department_id
			FROM employees
			WHERE last_name LIKE '%u%'
			);
#5.查询在部门的location_id为1700的部门工作的员工的员工号
SELECT employee_id
FROM employees e1
WHERE 1700=(
		SELECT location_id
		FROM departments d
		WHERE e1.`department_id`=d.`department_id`
		);
#6.查询管理者是King的员工姓名和工资
SELECT e1.last_name,e1.salary
FROM employees e1
WHERE manager_id IN(
		SELECT employee_id
		FROM employees e2
		WHERE last_name='King'
		);
#7.查询工资最低的员工信息: last_name, salary
SELECT last_name,salary
FROM employees
WHERE salary <=ALL(
SELECT salary
FROM employees
);
#from 多拼了一个自己的表
SELECT last_name,salary
FROM employees JOIN (
			SELECT MIN(salary) avg_sal
			FROM employees 
			) t
WHERE salary=avg_sal;			
#8.查询平均工资最低的部门信息
#方式一：
SELECT 
  * 
FROM
  departments 
WHERE department_id = 
  (SELECT 
    department_id 
  FROM
    employees 
  GROUP BY department_id 
  HAVING AVG(salary) <= ALL 
    (SELECT 
      AVG(salary) 
    FROM
      employees 
    GROUP BY department_id)) ;
    
#方式二：用from子查询自己造一个avg_sal字段
SELECT 
  * 
FROM
  departments 
WHERE department_id = 
  (SELECT 
    department_id 
  FROM
    employees 
  GROUP BY department_id 
  HAVING AVG(salary) = 
    (SELECT 
      MIN(avg_sal) 
    FROM
      (SELECT 
        AVG(salary) avg_sal 
      FROM
        employees 
      GROUP BY department_id) t)) ;
  
#方式三：order by 排序获得平均最小工资
SELECT 
  * 
FROM
  departments 
WHERE department_id = 
  (SELECT 
    department_id 
  FROM
    employees 
  GROUP BY department_id 
  HAVING AVG(salary) = 
    (SELECT 
      AVG(salary) 
    FROM
      employees 
    GROUP BY department_id 
    ORDER BY AVG(salary) ASC 
    LIMIT 0, 1)) ;

					 

#9.查询平均工资最低的部门信息和该部门的平均工资（相关子查询）
SELECT 
  d.*,
  (SELECT 
    AVG(salary) 
  FROM
    employees  
  WHERE department_id=d.department_id
  ) dept_avg_sal 
FROM
  departments d
WHERE department_id = 
  (SELECT 
    department_id 
  FROM
    employees 
  GROUP BY department_id 
  HAVING AVG(salary) <= ALL 
    (SELECT 
      AVG(salary) 
    FROM
      employees 
    GROUP BY department_id) );


#10.查询平均工资最高的 job 信息
SELECT * 
FROM jobs
WHERE job_id=(
		SELECT job_id
		FROM employees
		GROUP BY job_id
		HAVING AVG(salary)<=ALL(
					SELECT AVG(salary)
					FROM employees
					GROUP BY job_id
					)
		);
#11.查询平均工资高于公司平均工资的部门有哪些?
SELECT department_id
FROM employees
WHERE department_id IS NOT NULL
GROUP BY department_id
HAVING AVG(salary)>(
			SELECT AVG(salary)
			FROM employees
			);			
 #12.查询出公司中所有 manager 的详细信息
SELECT * FROM employees e1
WHERE employee_id IN(
SELECT manager_id
FROM employees
);
#13.各个部门中最高工资中最低的那个部门的最低工资是多少?
SELECT MIN(salary)
FROM employees
GROUP BY department_id
HAVING department_id=(
			SELECT department_id
			FROM employees
			GROUP BY department_id
			HAVING MAX(salary) <=ALL(
							SELECT MAX(salary)
							FROM employees
							GROUP BY department_id
							)
);
 #14.查询平均工资最高的部门的 manager 的详细信息: last_name, department_id, email, salary
SELECT last_name,department_id,email,salary
FROM employees 
WHERE employee_id=(
			SELECT manager_id
			FROM departments
			WHERE department_id=(
						SELECT department_id
						FROM employees
						GROUP BY department_id
						HAVING AVG(salary)>=ALL(
									SELECT AVG(salary)
									FROM employees
									GROUP BY department_id
									)
						)
			);



 #15. 查询部门的部门号，其中不包括job_id是"ST_CLERK"的部门号

SELECT DISTINCT department_id
FROM departments d
WHERE d.`department_id`NOT IN(
				SELECT e.department_id
				FROM employees e
				WHERE e.`job_id`='ST_CLERK'
				);
#16. 查询所有没有管理者的员工的last_name
SELECT last_name
FROM employees e
WHERE e.`manager_id` IS NULL;


 #17．查询员工号、姓名、雇用时间、工资，其中员工的管理者为 'De Haan'
SELECT employee_id,last_name,hire_date,salary
FROM employees
WHERE manager_id=(
			SELECT employee_id
			FROM employees
			WHERE last_name='De Haan'
			);
 #18.查询各部门中工资比本部门平均工资高的员工的员工号, 姓名和工资（相关子查询）
SELECT employee_id,last_name,salary
FROM employees e1
WHERE salary>(
		SELECT AVG(salary)
		FROM employees e2
		WHERE e2.department_id=e1.`department_id`
		);
#19.查询每个部门下的部门人数大于 5 的部门名称（相关子查询）
SELECT department_name
FROM departments d
WHERE 5<(
		SELECT COUNT(1)
		FROM employees e
		WHERE e.department_id=d.`department_id`
		);
#20.查询每个国家下的部门个数大于 2 的国家编号（相关子查询）
SELECT country_id
FROM locations l
WHERE 2<(
	SELECT COUNT(1)
	FROM departments d
	WHERE d.`location_id`=l.`location_id`
	);

