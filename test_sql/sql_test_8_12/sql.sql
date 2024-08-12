SELECT DATE_ADD(NOW(),INTERVAL '1_1' YEAR_MONTH),DATE_ADD(NOW(),INTERVAL -1 MONTH)-- 可以为负数
FROM DUAL;

SELECT DATE_SUB(NOW(),INTERVAL '1_5' HOUR_MINUTE)-- 需要单引号
FROM DUAL;

# 格式化：日期字符串
# 解析：字符串日期
# 此时我们谈的是日期的显示格式化与解析

#之前我们接触过隐式的格式化或解析
SELECT *
FROM employees
WHERE hire_date ='abcd-01-13';

SELECT CURDATE(),CURDATE()+0;

#格式化
SELECT DATE_FORMAT(CURDATE(),'%Y-%M-%D'),TIME_FORMAT(CURTIME(),'%Y-%M-%D'),DATE_FORMAT(NOW(),'%H:%i:%m')
FROM DUAL;

SELECT DATE_FORMAT(NOW(),'%T %M %Y %i');

# 格式化的逆过程：解析
SELECT STR_TO_DATE('11:26:31','%T')+0;

#获取不同国家的常用格式
SELECT GET_FORMAT(DATE,'USA');

SELECT DATE_FORMAT(CURDATE(),GET_FORMAT(DATE,'USA')),DATE_FORMAT(NOW(),GET_FORMAT(DATE,'INTERNAL'));

#流程控制函数
-- IF()
SELECT last_name,salary,IF(salary>=6000,'高工资','低工资') details -- 二选一场景
FROM employees;

SELECT last_name,salary,commission_pct,IF(commission_pct IS  NULL,0,commission_pct) 'details',
salary*12*(1+IF(commission_pct IS  NULL,0,commission_pct)) annual_salary
FROM employees;

-- IFNULL() 看作是IF()的特殊情况
SELECT last_name,salary,commission_pct,IFNULL(commission_pct,0) 'details'
FROM employees;

-- case when...then... when...then... else... end 多选一的场景
-- 类似 if ... else if ... else... 可以没有最后的else
SELECT last_name,salary,CASE WHEN salary>=15000 THEN '高富帅/白富美'
			     WHEN salary>=10000 THEN '潜力股'
			     WHEN salary>=8000 THEN '不算屌丝'
			     ELSE '草根' END 'details'
FROM employees;

/*：查询员工信息,若部门号为10,则打印其工资的1.1 倍,20号部门,则打印其
工资的1.2倍,30号部门打印其工资的1.3倍数，其他部门打印其工资的1.4倍数。
*/
SELECT employee_id,last_name,department_id,CASE department_id WHEN 10 THEN salary*1.1
							      WHEN 20 THEN salary*1.2
							      WHEN 30 THEN salary*1.3
							      ELSE salary*1.4 END 'details'
FROM employees;	

/*：查询部门号为 10,20,30的员工信息,若部门号为10,则打印其工资的1.1 倍,20号部门,则打印其
工资的1.2倍,30号部门打印其工资的1.3倍数，其他部门打印其工资的1.4倍数。
*/						
SELECT employee_id,last_name,department_id,CASE department_id WHEN 10 THEN salary*1.1
							      WHEN 20 THEN salary*1.2
							      WHEN 30 THEN salary*1.3
							      END 'details'
FROM employees
WHERE department_id IN(10,20,30);

# 加密与解密函数
SELECT MD5('123456'),SHA('sorakado');-- 不可逆

# MySQL信息函数
SELECT VERSION(),CONNECTION_ID(),DATABASE(),USER(),CHARSET('新海天'),COLLATION('奈奈濑');

#benchmark() 用于测试表达式的执行效率
SELECT BENCHMARK(1000000,MD5('mysql'))
FROM DUAL;