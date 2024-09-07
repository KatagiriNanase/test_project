SHOW DATABASES;

SELECT DATABASE();

SHOW TABLES;

CREATE TABLE test4 (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name varchar(10) NOT NULL
);

INSERT INTO test4 (name) VALUES ('nimisora');

INSERT INTO test4 (name) VALUES ('nanase'), ('kurumi');

SELECT * FROM test4;

DELETE FROM test4 WHERE id = 4;

#外键约束：foreign key
#创建主表
CREATE TABLE dept1 (
    dept_id int PRIMARY KEY,
    dept_name varchar(25) NOT NULL
);

CREATE TABLE emp1 (
    emp_id int PRIMARY KEY AUTO_INCREMENT,
    emp_name varchar(15) NOT NULL,
    department_id int,
    #表级约束：
    CONSTRAINT fk_emp1_dept_id FOREIGN KEY (department_id) REFERENCES dept1 (dept_id)
);

SHOW TABLES;

DESC dept1;

DESC emp1;

SELECT *
FROM information_schema.TABLE_CONSTRAINTS
WHERE
    table_name = 'emp1';

#添加失败：
INSERT INTO
    emp1
VALUES (1001, 'nimisora', '10')
    #添加十号部门后成功添加成功：
INSERT INTO
    dept1
VALUES (10, 'IT');

#删除失败：
DELETE FROM dept1 WHERE dept_id = '10';

#更改失败：
UPDATE dept1 SET dept_id = 20 WHERE dept_id = 10;

UPDATE FROM emp1 WHERE department_id = 20;

CREATE TABLE dept2 (
    dept_id int PRIMARY KEY,
    dept_name varchar(25) NOT NULL
);

CREATE TABLE emp2 (
    emp_id int PRIMARY KEY AUTO_INCREMENT,
    emp_name varchar(15) NOT NULL,
    department_id int
    #表级约束：
    #CONSTRAINT fk_emp1_dept_id FOREIGN KEY (department_id) REFERENCES dept1 (dept_id)
);

ALTER TABLE emp2
ADD CONSTRAINT fk_emp2_dept_id FOREIGN KEY (department_id) REFERENCES dept2 (dept_id);

SELECT *
FROM information_schema.TABLE_CONSTRAINTS
WHERE
    table_name = 'emp2';

# 约束等级：
-- ON UPDATE CASCADE ON DELETE SET NULL
-- 把更新操作变为级联模式，将删除操作变为子表设置为null模式：
CREATE TABLE dept ( did int PRIMARY KEY, dname varchar(50) );

CREATE TABLE emp (
    eid int PRIMARY KEY, #员工编号
    ename varchar(5),
    deptid int, #员工所在的部门
    FOREIGN KEY (deptid) REFERENCES dept (did) ON UPDATE CASCADE ON DELETE SET NULL
    #把修改操作设置为级联修改等级，把删除操作设置为set null等级
);

INSERT INTO dept VALUES (1001, '教学部');

INSERT INTO dept VALUES (1002, '财务部');

INSERT INTO dept VALUES (1003, '咨询部');

INSERT INTO emp VALUES (1, '张三', 1001);
#在添加这条记录时，要求部门表有1001部门
INSERT INTO emp VALUES (2, '李四', 1001);

INSERT INTO emp VALUES (3, '王五', 1002);

UPDATE dept SET did = 1004 WHERE did = 1002;

DELETE FROM dept WHERE did = 1004;

SELECT * FROM dept;

SELECT * FROM emp;

SELECT *
FROM information_schema.TABLE_CONSTRAINTS
WHERE
    table_name = 'employees';

SELECT database();
#查找外键约束：
SELECT *
FROM information_schema.TABLE_CONSTRAINTS
WHERE
    table_name = 'emp1';

#删除外键约束：
TABLALTER E emp1 DROP FOREIGN KEY fk_emp1_dept_id;
#再手动的删除外键约束对应的索引：
SHOW INDEX FROM emp1;

ALTER TABLE emp1 DROP INDEX fk_emp1_dept_id;

# check约束：
CREATE TABLE test5 (
    id int PRIMARY KEY,
    name varchar(15) NOT NULL,
    salary decimal(10, 2) CHECK (salary > 2000) #最低薪资
);

INSERT INTO test5 VALUES ('1001', 'nimisora', 2500);

-- INSERT INTO test5 VALUES ('1001', 'nimisora', 500);

SELECT *
FROM information_schema.TABLE_CONSTRAINTS
WHERE
    TABLE_NAME = 'test5';

ALTER TABLE test5 DROP CHECK test5_chk_1;

ALTER TABLE test5 MODIFY salary decimal(10, 2) CHECK (salary > 2000);

ALTER TABLE test5 ADD CHECK (id > 10);

DESC test5;

USE atguigudb;

SELECT * FROM employees;