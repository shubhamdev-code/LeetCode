# Write your MySQL query statement below
SELECT name as Customers FROM Customers where Customers.id NOT IN (SELECT customerid FROM Orders); 