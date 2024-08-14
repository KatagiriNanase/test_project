#查询公司中平均中奖率
-- 错误：
SELECT AVG(commission_pct)
FROM employees;-- 将奖金为null的记录跳过了
-- 正确：
SELECT SUM(commission_pct)/COUNT(IFNULL(commission_pct,0)),SUM(commission_pct)/COUNT(1),
AVG(IFNULL(commission_pct,0))
FROM employees; 

# group by 分组
-- 查询各个部门员工的平均工资，最高工资
SELECT department_id,AVG(salary),MAX(salary)
FROM employees
GROUP BY department_id;

-- 查询各个job_id员工的平均工资
SELECT job_id,AVG(salary)
FROM employees
GROUP BY job_id;

-- 查询各个部门、job_id的平均工资
SELECT department_id,job_id,AVG(salary)
FROM employees
GROUP BY department_id,job_id
ORDER BY department_id;

SELECT department_id,job_id,AVG(salary)
FROM employees
GROUP BY department_id;

SELECT department_id,AVG(salary)
FROM employees
GROUP BY department_id WITH ROLLUP
ORDER BY salary ASC;

#having 过滤数据 
-- 查询各个部门中最高工资比10000高的部门
-- 错误写法：
SELECT department_id,MAX(salary)
FROM employees
WHERE MAX(salary)>10000
GROUP BY department_id;

#要求1：过滤条件中使用了聚合函数后，则必须使用having替换where
#要求2：having声明在group by的后面
SELECT department_id,MAX(salary)
FROM employees
GROUP BY department_id
HAVING MAX(salary)>10000;
