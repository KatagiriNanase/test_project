CREATE database test_for_vscode;

use test_for_vscode;

CREATE TABLE test(
    id int PRIMARY KEY,
    name varchar(10),
    email varchar(25) UNIQUE,
    salary DECIMAL(10,2)
);

desc test;

insert into test
VALUES(1001,'nanase','nanase33@qq,com','100000');

select * from test;

# 玩的还是挺爽的嘛~

select database();

select *
from information_schema.TABLE_CONSTRAINTS
where TABLE_NAME='test1';
