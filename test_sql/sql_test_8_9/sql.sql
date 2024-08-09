#字符串函数
SELECT ASCII("Abc"),CHAR_LENGTH('hello world'),CHAR_LENGTH("我们"),LENGTH("hello world"),LENGTH("我们")
FROM DUAL;

-- concat() xxx work for yyy
SELECT CONCAT(e.last_name,' work for ',m.last_name) details
FROM employees e LEFT JOIN employees m
ON e.`manager_id`=m.`employee_id`;

-- concat_ws()
SELECT CONCAT_WS('-','hello','world','hello','beijing')
FROM DUAL;

#字符串的索引（index）是从1开始的
SELECT INSERT('hello',2,2,'aaaa'),REPLACE('hello','el','aaaa');

SELECT UPPER('HelLo'),LOWER('HelLo');

SELECT last_name,salary
FROM employees e
WHERE UPPER(last_name)='king';

SELECT last_name,salary
FROM employees e
WHERE LOWER(last_name)='KING';

SELECT LEFT('hello',2),RIGHT('hello',3),RIGHT('hello',7);

SELECT last_name,LPAD(salary,10,'*')
FROM employees;

SELECT last_name,RPAD(salary,10,'*')
FROM employees;

SELECT TRIM('     h e ll  o   ');

SELECT SUBSTR('hello',2,3),LOCATE('ll','hello');

#日期和时间函数
SELECT CURDATE(),CURRENT_DATE(),CURTIME(),CURRENT_TIME(),NOW(),
UTC_DATE(),UTC_TIME();

#日期与时间戳的转换
SELECT UNIX_TIMESTAMP(NOW()),FROM_UNIXTIME(UNIX_TIMESTAMP()),LENGTH(UNIX_TIMESTAMP('2025-08-09 20:47:53')-UNIX_TIMESTAMP(q));
