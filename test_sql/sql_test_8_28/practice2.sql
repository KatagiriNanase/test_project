 CREATE TABLE pet(
    `name` VARCHAR(20),
    `owner` VARCHAR(20),
    species VARCHAR(20),
    sex CHAR(1),
    birth YEAR,
    death YEAR
 );
INSERT INTO pet VALUES('Fluffy','harold','Cat','f','2013','2010');              

INSERT INTO pet(`name`,`owner`,species,sex,Birth) 
VALUES('Claws','gwen','Cat','m','2014'); 

INSERT INTO pet(`name`,species,sex,Birth) VALUES('Buffy','Dog','f','2009');
 
 INSERT INTO pet(`name`,`owner`,species,sex,Birth) 
VALUES('Fang','benny','Dog','m','2000');
 
 INSERT INTO pet VALUES('bowser','diane','Dog','m','2003','2009');
 
 INSERT INTO pet(`name`,species,sex,birth) VALUES('Chirpy','Bird','f','2008');
 
# 4. 添加字段:主人的生日owner_birth DATE类型。
ALTER TABLE pet
ADD owner_birth DATE;

# 5. 将名称为Claws的猫的主人改为kevin
UPDATE pet
SET OWNER ='kevin'
WHERE NAME='Claws';
# 6. 将没有死的狗的主人改为duck
UPDATE pet
SET OWNER ='duck'
WHERE death IS NULL;
# 7. 查询没有主人的宠物的名字；
DESC pet;
SELECT NAME
FROM pet
WHERE OWNER IS NULL;
# 8. 查询已经死了的cat的姓名，主人，以及去世时间；
SELECT * FROM pet;

SELECT NAME,OWNER,death
FROM pet
WHERE death IS NOT NULL
AND species ='Cat';
# 9. 删除已经死亡的狗
DELETE FROM
pet
WHERE death IS NOT NULL
AND species ='Dog';
# 10. 查询所有宠物信息
SELECT * FROM pet;