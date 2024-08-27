
CREATE TABLE emp1(
id INT,
NAME VARCHAR(15),
hire_date DATE,
salary DOUBLE(10,2)
);

DESC emp1;

#添加数据：
INSERT INTO emp1
VALUES(1001,'nanase','2007-2-1',4000);

INSERT INTO emp1(id,salary,NAME,hire_date)
VALUES(1002,6000,'nimisora','2006-12-3');
-- 添加多条数据：
INSERT INTO emp1(id,NAME,hire_date)
VALUES
(1002,'nimisora','2006-12-3'),
(1003,'kurumi','2003-3-3');

TRUNCATE TABLE emp1;
COMMIT;
SET autocommit =TRUE;

#查询语句导入多行数据：
INSERT INTO emp1(id,NAME,hire_date,salary)
SELECT employee_id,last_name,hire_date,salary
FROM employees
WHERE department_id IN(60,70);

SELECT * FROM emp1;

#更新
UPDATE emp1
SET salary =8000
WHERE id=1002;

UPDATE emp1
SET hire_date=CURTIME(),salary=8000
WHERE id=1003;

#题目:将表中姓名中包含字符a的提薪20%
UPDATE emp1
SET salary =salary*1.2
WHERE NAME LIKE '%a%';

DELETE FROM emp1
WHERE id=103;

DELETE FROM departments
WHERE department_id=50;

CREATE TABLE test1(
a INT,
b INT,
c INT GENERATED ALWAYS AS (a+b) VIRTUAL #字段c即为计算列
);

INSERT INTO test1(a,b)
VALUES (1,2);

SELECT * FROM test1;

UPDATE test1
SET c=10;

