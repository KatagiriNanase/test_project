USE test_8_30;

CREATE TABLE test_text(
tx TEXT
);

INSERT INTO test_text
VALUES('atguigu   ');

SELECT CHAR_LENGTH(tx)
FROM test_text; #10

CREATE TABLE test_enum(
season ENUM('spring','summer','fall','winter','unkown')
);

ALTER TABLE test_enum
MODIFY season ENUM('spring','summer','fall','winter','unknow');

INSERT INTO test_enum
VALUES('spring'),('fall'),('winter');

SELECT * FROM test_enum;

INSERT INTO test_enum
VALUES('spring','winter');

INSERT INTO test_enum
VALUES('UNKNOW');

INSERT INTO test_enum
VALUES(1),('2');

INSERT INTO test_enum
VALUES(NULL);

CREATE TABLE test_set(
s SET ('A', 'B', 'C')
);

INSERT INTO test_set (s) VALUES ('A'), ('A,B');
 #插入重复的SET类型成员时，MySQL会自动删除重复的成员
INSERT INTO test_set (s) VALUES ('A,B,C,A');
 #向SET类型的字段插入SET成员中不存在的值时，MySQL会抛出错误。
INSERT INTO test_set (s) VALUES ('A,B,C,D');

SELECT *
FROM test_set;

CREATE TABLE temp_mul(
 gender ENUM('男','女'),
 hobby SET('吃饭','睡觉','打豆豆','写代码')
 );
 
INSERT INTO temp_mul
VALUES('男','睡觉,打豆豆');

SELECT* FROM temp_mul;

CREATE TABLE test_binary1(
 f1 BINARY,
 f2 BINARY(3),
 # f3 VARBINARY,
 f4 VARBINARY(10)
 );
 
 CREATE TABLE test_blob1(
 id INT,
 img MEDIUMBLOB
 );
 
INSERT INTO test_blob1(id)
VALUES(1001);

CREATE TABLE test_json(
js json
);

INSERT INTO test_json (js) 
VALUES ('{"name":"nanase", "age":18, "address":{"province":"beijing", 
"city":"beijing"}}');

SELECT * FROM test_json;

SELECT * 
FROM information_schema.`TABLE_CONSTRAINTS`
WHERE table_name='test1';

CREATE DATABASE test_constrain;

CREATE TABLE test1(
id INT NOT NULL,
last_name VARCHAR(15) NOT NULL,
email VARCHAR(25),
salary DECIMAL(10,2)
);

DESC test1;

INSERT INTO test1(id)
VALUES(NULL);

INSERT INTO test1(id,email)
VALUES(2,'abc@123.com');

ALTER TABLE test1
MODIFY email VARCHAR(25) NOT NULL;

DROP TABLE test2;

CREATE TABLE test2(
id INT UNIQUE,#列级约束
last_name VARCHAR(15),
email VARCHAR(25) UNIQUE,
salary DECIMAL(10,2),	
#表级约束
UNIQUE(email)
);

DESC test2;

SELECT * 
FROM information_schema.`TABLE_CONSTRAINTS`
WHERE table_name='test2';
