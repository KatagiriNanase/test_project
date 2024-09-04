USE test_constrain;

SHOW TABLES;

CREATE TABLE test1(
id INT UNIQUE,
last_name VARCHAR(10),
email VARCHAR(25),
salary DECIMAL(10,2),
CONSTRAINT uk_test1_email UNIQUE(email)
);

INSERT INTO test1
VALUES(1,'sorakado','33@qmail.com',6000);

INSERT INTO test1
VALUES(2,'sorakado',NULL,6000);

SELECT * FROM test1;

UPDATE test1
SET salary =5000
WHERE id =2;

UPDATE test1
SET last_name='nanase'
WHERE id=2;

DESC test1;

ALTER TABLE test1
ADD UNIQUE(salary);

ALTER TABLE test1
ADD CONSTRAINT uk_test1_name UNIQUE(last_name);

ALTER TABLE test1
ADD UNIQUE(id,last_name);

#查看约束：
SELECT * 
FROM information_schema.`TABLE_CONSTRAINTS`
WHERE table_name='test1';

ALTER TABLE test1
DROP INDEX salary;

SHOW INDEX FROM test1;

CREATE TABLE test2(
id INT,
NAME VARCHAR(25),
salary DECIMAL(10,2),
PRIMARY KEY(id)
);

DESC test2;

INSERT INTO test2(id)
VALUES(1),(1);

SHOW INDEX FROM test2;

CREATE TABLE temp(
id INT PRIMARY KEY,
NAME VARCHAR(25) PRIMARY KEY
);

ALTER TABLE test2
DROP PRIMARY KEY;

ALTER TABLE test2
ADD PRIMARY KEY(id);

CREATE TABLE test3(
id INT PRIMARY KEY AUTO_INCREMENT,
NAME VARCHAR(10) NOT NULL DEFAULT 'void'

);

DESC test3;

CREATE TABLE employee(
 eid INT PRIMARY KEY ,
 ename VARCHAR(20)
 );
 
ALTER TABLE employee
MODIFY eid INT AUTO_INCREMENT;

DESC employee;

ALTER TABLE employee
MODIFY eid INT NOT NULL;

DELETE FROM employee;

ALTER TABLE employee
DROP PRIMARY KEY ;

ALTER TABLE employee
MODIFY eid INT PRIMARY KEY;

ALTER TABLE employee
MODIFY eid INT UNIQUE;

INSERT INTO employee(eid)
VALUES(NULL);

SELECT * FROM employee;

ALTER TABLE employee
DROP INDEX eid;

ALTER TABLE employee
DROP COLUMN ename;

ALTER TABLE employee
ADD PRIMARY KEY(eid);

