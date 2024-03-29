-- Write your MySQL query statement below
-- Runtime 2240ms Beats 96.04%
-- 注意：題目是title的最小排序(平局時) 與 name的最小排序(平局時)
(   
SELECT A.name AS results
  FROM Users AS A
  INNER JOIN movierating AS B
ON A.user_id = B.user_id
GROUP BY B.user_id
ORDER BY count(1) DESC , A.name ASC
LIMIT 1
)
UNION ALL
(
SELECT A.title AS results
  FROM Movies AS A
  INNER JOIN movierating AS B
  ON A.movie_id = B.movie_id
  AND  B.created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY A.movie_id
ORDER BY avg(rating) DESC , title ASC
LIMIT 1
)
