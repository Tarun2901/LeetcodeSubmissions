# Write your MySQL query statement below
SELECT W1.id 
FROM Weather as W1,Weather as W2
WHERE TO_DAYS(W1.recordDate)-TO_DAYS(W2.recordDate) = 1 AND W1.temperature>W2.temperature