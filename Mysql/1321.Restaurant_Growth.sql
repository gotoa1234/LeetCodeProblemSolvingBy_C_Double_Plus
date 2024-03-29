-- Write your MySQL query statement below
-- Runtime 721 ms Beats 87.43%

SELECT A.visited_on,
       SUM(B.amount) AS amount,
       ROUND(SUM(B.amount)/7, 2) AS average_amount
  FROM (
    SELECT visited_on,
           SUM(amount) AS amount  
      FROM Customer
  GROUP BY visited_on
  )AS A
  ,
  (
    SELECT visited_on, 
           SUM(amount) AS amount  
      FROM Customer
  GROUP BY visited_on
  )AS B
 WHERE DATEDIFF(A.visited_on, B.visited_on) BETWEEN 0 AND 6
 GROUP BY A.visited_on  
  HAVING DATEDIFF(visited_on,(SELECT MIN(visited_on) FROM Customer)) >= 6
 ORDER BY visited_on ASC;