# Write your MySQL query statement below
SELECT Customers.Name AS Customers
FROM Customers
WHERE Customers.Id NOT IN(SELECT CustomerId FROM Orders)