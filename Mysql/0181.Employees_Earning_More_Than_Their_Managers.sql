-- Write your MySQL query statement below
SELECT A.name AS 'Employee'
     FROM Employee AS A
INNER JOIN Employee AS B
    ON A.managerId = B.id AND A.managerId >0
     WHERE  A.salary > B.salary;