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