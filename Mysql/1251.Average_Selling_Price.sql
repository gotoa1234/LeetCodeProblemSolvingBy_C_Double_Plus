-- Write your MySQL query statement below
-- Runtime 1684 ms Beats 57.14%
     SELECT A.product_id,
            ROUND(SUM(A.Price * B.units) / SUM(B.units), 2) AS average_price 
       FROM Prices AS A
  LEFT JOIN UnitsSold AS B
         ON A.Product_id = B.Product_id
      WHERE B.purchase_date Between A.start_date AND A.end_date   
   GROUP BY A.product_id