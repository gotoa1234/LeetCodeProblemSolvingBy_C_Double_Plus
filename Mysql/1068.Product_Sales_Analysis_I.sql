-- Write your MySQL query statement below
-- Runtime 2400 ms Beats 29.58%
SELECT B.product_name,
       A.year,
       A.price 
  FROM Sales AS A
  LEFT JOIN Product AS B
    ON A.product_id = B.product_id  