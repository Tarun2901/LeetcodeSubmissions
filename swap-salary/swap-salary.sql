# Write your MySQL query statement below
UPDATE SALARY
SET sex = CHAR(ASCII('f')+ASCII('m')-ASCII(sex))