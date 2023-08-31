-- Write your MySQL query statement below
-- Runtime 2011 ms Beats 69.31%
SELECT A.name, 
       B.bonus
  FROM Employee AS A
  LEFT JOIN Bonus AS B
    ON A.empId = B.empId
 WHERE B.bonus < 1000 || B.bonus IS NULL;