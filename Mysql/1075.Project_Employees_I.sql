-- Write your MySQL query statement below
-- Runtime 1582 ms Beats 71.8%
      SELECT A.project_id,
             ROUND(SUM(B.experience_years) / COUNT(A.project_id), 2) AS average_years
        FROM Project AS A
  INNER JOIN Employee AS B
          ON A.employee_id = B.employee_id
    GROUP BY A.project_id