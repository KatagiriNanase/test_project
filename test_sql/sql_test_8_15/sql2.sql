# 子查询
# 需求：谁的工资比Abel高？
#方式一：查询两次
SELECT salary 
FROM  employees
WHERE last_name='Abel';

SELECT last_name,salary 
FROM employees
WHERE salary>10000;
#方式二：自连接
SELECT e2.`last_name`,e2.salary
FROM employees e1 JOIN employees e2 -- 首先将他们两个表进行笛卡尔积
ON e1.`last_name`='Abel'-- 留下名为Abel的与第二个表全部配对上，这样每一条记录上都存在着Abel的字段信息，就能够进行比较
AND e1.`salary`<e2.`salary`;

#方式三：子查询
SELECT last_name,salary 
FROM employees
WHERE salary>(
		SELECT salary 
		FROM  employees
		WHERE last_name='Abel'
	     );
	     
#相关子查询的需求:查询工资大于本部门平均工资的员工信息
	    