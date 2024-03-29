-- Write your MySQL query statement below
-- Runtime 990ms Beats 89.26%
SELECT DATE_FORMAT(trans_date, "%Y-%m") AS MONTH,
       country,
       SUM(1) AS trans_count,
       SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
       SUM(amount) AS trans_total_amount ,
       SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
  FROM Transactions
 GROUP BY MONTH, country
