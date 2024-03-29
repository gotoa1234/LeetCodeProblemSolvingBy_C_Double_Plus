-- Write your MySQL query statement below
-- Runtime 1201 ms Beats 89.66%
SELECT query_name,
       ROUND( AVG((Queries.rating / Queries.position )), 2) AS quality,
       ROUND( SUM(rating < 3) / COUNT(query_name) * 100 , 2) AS poor_query_percentage
  FROM Queries
 GROUP BY query_name
 