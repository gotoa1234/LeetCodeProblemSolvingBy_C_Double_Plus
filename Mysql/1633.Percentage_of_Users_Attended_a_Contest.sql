-- Write your MySQL query statement below
-- Runtime 2407 ms Beats 24.08%
SELECT A.contest_id,
       ROUND((COUNT(A.user_id) / B.total) * 100 ,2) AS percentage
  FROM Register AS A
  JOIN (
    SELECT COUNT(*) AS total
    FROM Users 
  ) AS B
GROUP BY A.contest_id
ORDER BY percentage DESC , A.contest_id ASC