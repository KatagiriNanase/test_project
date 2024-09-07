CREATE DATABASE test04_emp;

USE test04_emp;

CREATE TABLE emp2 (id INT, emp_name VARCHAR(15));

CREATE TABLE dept2 (id INT, dept_name VARCHAR(15));

#1.向表emp2的id列中添加PRIMARY KEY约束
ALTER TABLE emp2 ADD PRIMARY KEY (id);

#2. 向表dept2的id列中添加PRIMARY KEY约束
ALTER TABLE dept2 ADD PRIMARY KEY (id);
#3. 向表emp2中添加列dept_id，并在其中定义FOREIGN KEY约束，与之相关联的列是dept2表中的id列。
ALTER TABLE emp2 ADD dept_id int;

ALTER TABLE emp2 ADD FOREIGN KEY (dept_id) REFERENCES dept2 (id);

# 1、创建数据库test01_library
CREATE DATABASE test01_library;

# 2、创建表 books，表结构如下：
CREATE TABLE books (
    id int,
    name VARCHAR(50),
    authors VARCHAR(100),
    price FLOAT,
    pubdate YEAR,
    note VARCHAR(100),
    num int
);

ALTER TABLE books MODIFY id int PRIMARY KEY AUTO_INCREMENT;

ALTER TABLE books MODIFY name VARCHAR(50) NOT NULL;

ALTER TABLE books MODIFY authors VARCHAR(100) NOT NULL;

ALTER TABLE books MODIFY price float NOT NULL;

ALTER TABLE books MODIFY pubdate YEAR NOT NULL;

ALTER TABLE books MODIFY num VARCHAR(100) NOT NULL;

DESC books;

#1. 创建数据库test04_company

CREATE DATABASE test04_company;

USE test04_company;
#2. 按照下表给出的表结构在test04_company数据库中创建两个数据表offices和employees
CREATE TABLE offices (
    officeCode int(10) PRIMARY KEY,
    city VARCHAR(50) NOT NULL,
    address VARCHAR(50),
    country VARCHAR(50) NOT NULL,
    postalCode VARCHAR(15) UNIQUE
);

CREATE TABLE employees (
    employeeNumber int(11) PRIMARY KEY AUTO_INCREMENT,
    lastName VARCHAR(50) NOT NULL,
    firstName VARCHAR(25) NOT NULL,
    mobile VARCHAR(25) UNIQUE,
    officeCode int(10),
    jobTile VARCHAR(50) NOT NULL,
    birth datetime NOT NULL,
    note VARCHAR(255),
    sex varchar(5),
    CONSTRAINT FOREIGN KEY (officeCode) REFERENCES offices (officeCode)
);

DESC employees;

#3. 将表employees的mobile字段修改到officeCode字段后面
ALTER TABLE employees MODIFY mobile VARCHAR(25) after officeCode;
#4. 将表employees的birth字段改名为employee_birth
ALTER TABLE employees CHANGE birth employee_birth datetime NOT NULL;
#5. 修改sex字段，数据类型为CHAR(1)，非空约束
ALTER TABLE employees MODIFY sex char(1);
#6. 删除字段note
ALTER TABLE employees DROP COLUMN note;
#7. 增加字段名favoriate_activity，数据类型为VARCHAR(100)
ALTER TABLE employees ADD favoriate_activity VARCHAR(100);
#8. 将表employees名称修改为employees_info
ALTER TABLE employees RENAME TO employees_info;

DESC employees_info;