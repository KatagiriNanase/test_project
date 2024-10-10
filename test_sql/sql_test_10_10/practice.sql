#0.准备工作
CREATE DATABASE test15_pro_func;

USE test15_pro_func;

CREATE TABLE admin (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_name VARCHAR(15) NOT NULL,
    pwd VARCHAR(25) NOT NULL
);

CREATE TABLE beauty (
    id INT PRIMARY KEY AUTO_INCREMENT,
    NAME VARCHAR(15) NOT NULL,
    phone VARCHAR(15) UNIQUE,
    birth DATE
);

INSERT INTO
    beauty (NAME, phone, birth)
VALUES (
        '朱茵',
        '13201233453',
        '1982-02-12'
    ),
    (
        '孙燕姿',
        '13501233653',
        '1980-12-09'
    ),
    (
        '田馥甄',
        '13651238755',
        '1983-08-21'
    ),
    (
        '邓紫棋',
        '17843283452',
        '1991-11-12'
    ),
    (
        '刘若英',
        '18635575464',
        '1989-05-18'
    ),
    (
        '杨超越',
        '13761238755',
        '1994-05-11'
    );

#1. 创建存储过程insert_user(),实现传入用户名和密码，插入到admin表中
DESC admin;

delimiter / /

create procedure insert_user(in UserName varchar(15),in `password` varchar(25))
begin
    insert into admin(user_name,pwd)
    VALUES(UserName,`password`);
end //

delimiter;

-- 调用
CALL insert_user ('1001', '114514');

SELECT * FROM admin;
#2. 创建存储过程get_phone(),实现传入女神编号，返回女神姓名和女神电话
DESC beauty;

delimiter $

create PROCEDURE get_phone(in ID INT,OUT NAME varchar(25),OUT PHONE varchar(15))
begin
    -- set NAME=(select name from beauty where id=ID);
    -- set PHONE=(select phone from beauty where id=ID);
    select name,phone into NAME,PHONE
    from beauty
    where id=ID;
end $

delimiter;

DROP PROCEDURE get_phone;
-- 调用

CALL get_phone (2, @name, @phone);

print @name, @phone;

SELECT * FROM beauty;