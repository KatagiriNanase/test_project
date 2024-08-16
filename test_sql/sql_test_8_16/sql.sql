#单行操作符
#子查询的编写技巧：①从里往外 ②从外往里
#查询工资大于149号员工工资的员工的信息
SELECT 
  employee_id,
  last_name,
  salary 
FROM
  employees 
WHERE salary > 
  (SELECT 
    salary 
  FROM
    employees 
  WHERE employee_id = 149) ;

#返回job_id与141号员工相同，salary比143号员工多的员工姓名，job_id和工资
SELECT 
  last_name,
  job_id,
  salary 
FROM
  employees 
WHERE job_id = 
  (SELECT 
    job_id 
  FROM
    employees 
  WHERE employee_id = 141) 
  AND salary > 
  (SELECT 
    salary 
  FROM
    employees 
  WHERE employee_id = 143) ;
#：返回公司工资最少的员工的last_name,job_id和salary
SELECT 
  last_name,
  job_id,
  salary 
FROM
  employees 
WHERE salary = 
  (SELECT 
    MIN(salary) 
  FROM
    employees) ;
/*查询与141号的manager_id和department_id相同的其他员工的employee_id，
manager_id，department_id*/
SELECT 
  employee_id,
  manager_id,
  department_id 
FROM
  employees 
WHERE (manager_id, department_id) = 
  (SELECT 
    manager_id,
    department_id 
  FROM
    employees 
  WHERE employee_id = 141) ;
#查询最低工资大于50号部门最低工资的部门id和其最低工资
SELECT department_id,MIN(salary)
FROM employees
GROUP BY department_id
HAVING MIN(salary)>(
SELECT MIN(salary)
FROM employees
GROUP BY department_id
HAVING department_id=50
);

SELECT 
  department_id,
  MIN(salary) 
FROM
  employees 
WHERE department_id IS NOT NULL 
GROUP BY department_id 
HAVING MIN(salary) > 
  (SELECT 
    MIN(salary) 
  FROM
    employees 
  WHERE department_id = 50) ;

  
#显式员工的employee_id,last_name和location。其中，若员工department_id与location_id为1800
#的department_id相同，则location为’Canada’，其余则为’USA’。
SELECT employee_id,last_name,CASE  WHEN department_id =(
							SELECT department_id
							FROM departments
							WHERE location_id=1800
							) 
				   THEN 'Canada'
				   ELSE 'USA' END AS locations 				
FROM employees;

#多行子查询 IN ANY ALL SOME 
#：返回其它job_id中比job_id为‘IT_PROG’部门任一工资低的员工的员工号、姓名、job_id 以及salary
SELECT employee_id,last_name,job_id,salary
FROM employees

