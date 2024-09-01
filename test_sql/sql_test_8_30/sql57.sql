SHOW VARIABLES LIKE 'character_%';

CREATE DATABASE test_8_30;

SHOW CREATE DATABASE test_8_30;

USE test_8_30;

CREATE TABLE test1(
id INT,
NAME VARCHAR(25) CHARACTER SET 'gbk'
);

SHOW CREATE TABLE test1;

CREATE TABLE test_int1(
f1 TINYINT,
f2 SMALLINT,
f3 MEDIUMINT,
f4 INTEGER,
f5 BIGINT
);

DESC test_int1;

INSERT INTO test_int1(f1)
VALUES(-128),(127);

SELECT * FROM test_int1;

#Out of range value for column 'f1' at row 1
INSERT INTO test_int1(f1)
VALUES(128);

CREATE TABLE test_int2(
f1 INT,
f2 INT(5),
f3 INT(5) ZEROFILL
);

INSERT INTO test_int2(f3)
VALUES(123),(123456);

SELECT * FROM test_int2;

CREATE TABLE test_double1(
 f1 FLOAT,
 f2 FLOAT(5,2),
 f3 DOUBLE,
 f4 DOUBLE(5,2)
);
 
INSERT INTO test_double1(f1,f2)
VALUES(123.45,123.45);

SELECT * FROM test_double1;

INSERT INTO test_double1(f3,f4)
VALUES(123.45,123.456);

INSERT INTO test_double1(f3,f4)
VALUES(123.45,999.995);

CREATE TABLE test_bit1(
f1 BIT,
f2 BIT(5),
f3 BIT(64)
);

INSERT INTO test_bit1(f1)
VALUES(0),(1);

SELECT * FROM test_bit1;

SELECT VERSION();