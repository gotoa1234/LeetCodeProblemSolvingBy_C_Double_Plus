-- Write your MySQL query statement below
-- Runtime 1266 ms Beats 77.29%
SELECT A.employee_id,
       A.name,
       B.reports_count,
       B.average_age
  FROM employees AS A
 INNER JOIN(
SELECT reports_to, 
       COUNT(reports_to) AS reports_count, 
	    ROUND(SUM(age) / COUNT(reports_to),0) AS average_age
  FROM employees 
  GROUP BY reports_to 
  )AS B
  ON A.employee_id = B.reports_to
  ORDER BY A.employee_id ASC