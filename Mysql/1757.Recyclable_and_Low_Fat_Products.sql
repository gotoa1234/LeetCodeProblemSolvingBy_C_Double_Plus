-- Write your MySQL query statement below
-- Runtime 1318 ms Beats 34.59% 
SELECT product_id
  FROM Products
 WHERE low_fats = 1 
   AND recyclable= 1;