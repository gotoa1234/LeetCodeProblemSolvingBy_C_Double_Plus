-- Write your MySQL query statement below
-- Runtime 3074 ms Beats 47.69% 
SELECT Result.customer_id,
       COUNT(Result.visit_id) AS count_no_trans
  FROM (
    SELECT A.customer_id, A.visit_id
      FROM Visits AS A
 LEFT JOIN Transactions AS B
        ON A.visit_id = B.visit_id
     WHERE B.visit_id IS NULL
 ) AS Result
 GROUP BY Result.customer_id
 ORDER BY count_no_trans DESC;