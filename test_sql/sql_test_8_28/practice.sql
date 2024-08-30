CREATE DATABASE IF NOT EXISTS dbtest11 CHARACTER SET 'utf8';

USE dbtest11;
 CREATE TABLE my_employees(
 id INT(10),
 first_name VARCHAR(10),
 last_name VARCHAR(10),
 userid VARCHAR(10),
 salary DOUBLE(10,2)
 );
 CREATE TABLE users(
 id INT,
 userid VARCHAR(10),
 department_id INT
 );
#3. 显示表my_employees的结构
DESC `my_employees`;

#4. 向my_employees表中插入下列数据
INSERT INTO my_employees
VALUES
(1,'patel','Ralph','Rpatel',895),
(2,'patel','Dancs','Betty',860),
(3,'Biri','Ben','Bbiri',1100),
(4,'Newman','Chad','Cnewman',750),
(5,'Ropeburn','Audrey','Aropebur',1550);

#5. 向users表中插入数据
DESC users;
INSERT INTO users
VALUES
(1,'Rpatel',10),
(2,'Bdancs',10),
(3,'Bbiri',20),
(4,'Cnewman',30),
(5,'Aropebur',40);

#6. 将3号员工的last_name修改为“drelxer”
UPDATE `my_employees`
SET last_name ='drelxer'
WHERE id=3;

#7. 将所有工资少于900的员工的工资修改为1000
UPDATE my_employees
SET salary=1000
WHERE salary<900;

#8. 将userid为Bbiri的user表和my_employees表的记录全部删除
DELETE u,m
FROM `my_employees` m JOIN `users` u
ON m.userid=u.userid
WHERE u.userid='Bbiri';

#9. 删除my_employees、users表所有数据
DELETE u,m
FROM `my_employees` m JOIN `users` u;

#11. 清空表my_employees
TRUNCATE TABLE my_employees;