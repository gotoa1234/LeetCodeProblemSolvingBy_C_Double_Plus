-- Write your MySQL query statement below
-- Runtime 1510 ms Beats 59.77%
SELECT A.user_id,
       IFNULL(ROUND(C.confirmed / B.total , 2), 0) AS confirmation_rate
  FROM Signups AS A
 LEFT JOIN (
       SELECT user_id, 
              COUNT(user_id) AS total
         FROM Confirmations          
     GROUP BY user_id
 ) AS B
 ON A.user_id = B.user_id
 LEFT JOIN (
    SELECT user_id, 
           COUNT(user_id) AS confirmed
      FROM Confirmations     
      WHERE Confirmations.action = 'confirmed'
     GROUP BY user_id
 ) AS C
 ON A.user_id = C.user_id
 