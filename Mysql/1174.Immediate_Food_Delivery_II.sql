-- Write your MySQL query statement below
-- 題目有點複雜，大意 : 找出每個customer_id(顧客)，第一筆訂單(order_date 最小的)，如果那筆
--                      order_date == customer_pref_delivery_date 表示 立即訂單
--                      否則就是排程訂單
--               目標 : 找出立即訂單的比例
-- Delivery 表：
-- +-------------+-------------+------------+-----------------------------+
-- | delivery_id | customer_id | order_date | customer_pref_delivery_date |
-- +-------------+-------------+------------+-----------------------------+
-- | 1           | 1           | 2019-08-01 | 2019-08-02                  |
-- | 2           | 2           | 2019-08-02 | 2019-08-02                  |
-- | 3           | 1           | 2019-08-11 | 2019-08-12                  |
-- | 4           | 3           | 2019-08-24 | 2019-08-24                  |
-- | 5           | 3           | 2019-08-21 | 2019-08-22                  |
-- | 6           | 2           | 2019-08-11 | 2019-08-13                  |
-- | 7           | 4           | 2019-08-09 | 2019-08-09                  |
-- Runtime 1368 ms Beats 55.29%

SELECT ROUND(AVG(CASE WHEN order_date =  customer_pref_delivery_date THEN 1 ELSE 0 END         
          ) * 100, 2 ) AS immediate_percentage
  FROM Delivery AS A
  INNER JOIN 
(
  SELECT customer_id ,
         MIN(order_date) AS customer_date
    FROM Delivery
GROUP BY customer_id
) AS B
  ON A.customer_id = B.customer_id 
 AND  A.order_date = B.customer_date