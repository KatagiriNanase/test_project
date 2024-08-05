# . 
SELECT 'sorakado' REGEXP 's..a'
FROM DUAL;

# []
SELECT 'nanase' REGEXP '[nr]'
FROM DUAL;

# ! NOT && || XOR
SELECT last_name,salary,department_id
FROM employees
WHERE department_id =10 OR department_id =20;

SELECT last_name,salary,department_id
FROM employees
# WHERE department_id =10 and department_id =20;
WHERE department_id =50 AND salary > 6000;

# NOT !
SELECT last_name,salary,department_id
FROM employees
-- WHERE department_id =10 and department_id =20;
WHERE salary NOT BETWEEN 6000 AND 8000;

SELECT last_name,salary,commission_pct
FROM employees
WHERE NOT commission_pct IS NULL;

# XOR 逻辑异或
