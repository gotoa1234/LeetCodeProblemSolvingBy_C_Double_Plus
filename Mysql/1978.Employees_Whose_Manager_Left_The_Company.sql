-- Write your MySQL query statement below
-- Runtime 808ms Beats 45.95% 
SELECT employee_id
  FROM Employees 
 WHERE salary < 30000
   AND manager_id  NOT IN (
       SELECT DIStinct(employee_id)
         FROM Employees
   )
ORDER BY employee_id ASC