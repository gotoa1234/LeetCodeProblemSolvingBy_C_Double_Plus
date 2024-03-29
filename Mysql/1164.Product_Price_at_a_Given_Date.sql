-- Write your MySQL query statement below
-- Runtime  862 ms Beats 90.90%
SELECT A.product_id,       
       IF(B.new_price IS NULL, 10, B.new_price) AS price
  FROM products AS A
  LEFT JOIN (      
   SELECT product_id,
          new_price,
          change_date
     FROM (
	   SELECT product_id, change_date, new_price
	     FROM products
    	   WHERE change_date <= '2019-08-16'  
	 GROUP BY product_id, change_date
    ORDER BY change_date DESC
	  ) AS Result
 GROUP BY Result.product_id

 )AS B 
  ON A.product_id = B.product_id
GROUP BY A.product_id