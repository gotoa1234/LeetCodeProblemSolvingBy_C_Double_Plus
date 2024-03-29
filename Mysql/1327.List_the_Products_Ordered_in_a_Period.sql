-- Write your MySQL query statement below
-- Runtime 1318ms Beats 94.57%
 SELECT P.product_name,
        Result.unit
   FROM products AS P
  INNER JOIN (
 SELECT O.product_id,
        SUM(O.unit) AS unit
   FROM Orders AS O
  WHERE O.order_date BETWEEN '2020-02-01' AND '2020-02-29'
 GROUP BY O.product_id
 HAVING unit >= 100
 )AS Result
 ON P.product_id = Result.product_id