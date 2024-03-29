-- Write your MySQL query statement below
-- Runtime 1794 ms Beats 83.39%
SELECT product_id,
       year AS first_year,
       quantity,
       price
  FROM sales AS A
 WHERE (product_id, YEAR) IN(
   SELECT product_id, MIN(year) AS year
    FROM sales 
   GROUP BY product_id
 );