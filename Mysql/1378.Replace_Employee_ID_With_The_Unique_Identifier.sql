-- Write your MySQL query statement below
-- Runtime 2611 ms Beats 55.48%
SELECT B.unique_id, 
       A.name
  FROM Employees AS A
  LEFT JOIN EmployeeUNI AS B
    ON A.id = B.id
