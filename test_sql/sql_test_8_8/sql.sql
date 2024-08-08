# SQL99新特性：自然连接
SELECT employee_id,last_name,department_name
 FROM employees e JOIN departments d
 -- ON e.`department_id` = d.`department_id`
 ON e.`manager_id` = d.`manager_id`;
 
 SELECT * FROM departments;
 SELECT * FROM employees;
 
 SELECT * 
 FROM employees e LEFT JOIN departments d
 ON e.`manager_id`=d.`manager_id`
 WHERE d.`manager_id` IS NULL;
 
 #单行函数
-- 取随机数 
 SELECT RAND(),RAND(),RAND(4),RAND(10)
 FROM DUAL;
-- 四舍五入，截断操作
SELECT ROUND(123.456),ROUND(123.456,1),ROUND(123.456,-1);

SELECT TRUNCATE(123.456,-2);

#单行函数可以嵌套
SELECT TRUNCATE(ROUND(123.456,2),0);\

#三角函数
SELECT SIN(RADIANS(30)),SIN(PI()/6),DEGREES(ASIN(0.5));

#指数、对数
SELECT POW(2,3),POWER(2,3),EXP(0),LN(EXP(2)),LOG(2,8);

#进制转换
SELECT BIN(10),HEX(10),OCT(10),CONV(10,10,2);
