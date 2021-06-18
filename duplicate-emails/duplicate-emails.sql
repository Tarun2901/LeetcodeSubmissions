# Write your MySQL query statement below
SELECT DISTINCT Person.Email
FROM Person
WHERE Email in (SELECT Email FROM Person GROUP BY Email Having count(Email)>1)