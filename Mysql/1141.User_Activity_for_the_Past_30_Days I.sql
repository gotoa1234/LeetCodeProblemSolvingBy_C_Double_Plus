-- Write your MySQL query statement below
-- Runtime 1100 ms Beats 66.80%
SELECT customer_id
  FROM(
     SELECT B.customer_id
       FROM Product  AS A 
 INNER JOIN Customer AS B
         ON A.product_key = B.product_key
   GROUP BY B.customer_id, B.product_key
 ) AS Result 
GROUP BY Result.customer_id
  HAVING COUNT(Result.customer_id) = (SELECT COUNT(product_key) from Product)