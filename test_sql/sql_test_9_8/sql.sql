CREATE DATABASE dbtest_9_8;

CREATE TABLE emps AS SELECT * FROM atguigudb.employees;

CREATE TABLE depts AS SELECT * FROM atguigudb.departments;

CREATE VIEW vu_emp1 AS SELECT employee_id, last_name, salary FROM emps;

SELECT * FROM vu_emp1;

CREATE VIEW vu_emp2 AS
SELECT
    employee_id emp_id,
    last_name lname,
    salary sal
FROM emps;

SELECT * FROM vu_emp2;

DELETE FROM vu_emp3 WHERE sal < 8000;

CREATE VIEW vu_emp3(emp_id,lname,sal) AS
SELECT
    employee_id ,
    last_name,
    salary
FROM emps;