-- Write your MySQL query statement below
-- Runtime 987ms Beats 45.62% 
SELECT CASE WHEN COUNT(num) = 0 THEN NULL 
       ELSE Result.num
       END AS num
FROM(
SELECT num
  FROM MyNumbers
  GROUP BY num
  HAVING COUNT(num) = 1
  ORDER BY num DESC 
  LIMIT 1
  ) AS Result