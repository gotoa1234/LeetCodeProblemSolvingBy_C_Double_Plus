-- Write your MySQL query statement below
-- Runtime 231 ms Beats 83.23%
  SELECT CASE WHEN Count(Result.salary) > 0 THEN Result.salary
              ELSE NULL
          END AS 'SecondHighestSalary'      
         FROM (     
   SELECT salary
     FROM Employee
    WHERE salary < (SELECT MAX(salary)
                      FROM Employee
                   )
ORDER BY salary DESC
 LIMIT 1
) AS Result
