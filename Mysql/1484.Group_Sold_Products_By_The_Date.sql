-- Write your MySQL query statement below
-- Runtime 838 ms Beats 83.81%

SELECT sell_date,
       COUNT(1) AS num_sold,
       GROUP_CONCAT(DISTINCT product ORDER BY product) AS products 
  FROM (
SELECT sell_date,
       product
  FROM Activities
GROUP BY sell_date, product
) AS Result
GROUP BY sell_date
ORDER BY sell_date ASC