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

CREATE TABLE test_char1(
c1 CHAR,
c2 CHAR(5)
);

DESC test_char1;

INSERT INTO test_char1(c1)
VALUES('a');

INSERT INTO test_char1(c2)
VALUES('乐');

INSERT INTO test_char1(c2)
VALUES('吸');

INSERT INTO test_char1(c2)
VALUES('我是五个字');

SELECT CONCAT(c2,'***')
FROM test_char1;

SELECT * FROM test_char1;

INSERT INTO test_char1(c2)
VALUES('ab   ');

SELECT c2,CHAR_LENGTH(c2)
FROM test_char1;