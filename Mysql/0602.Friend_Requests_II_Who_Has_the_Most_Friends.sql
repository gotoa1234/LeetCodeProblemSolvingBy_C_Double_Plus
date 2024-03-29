-- Write your MySQL query statement below
-- Runtime 467 ms Beats 99.20%
SELECT result.id,
       SUM(result.total) AS num
  FROM (
SELECT requester_id AS id, COUNT(requester_id) AS Total  FROM RequestAccepted
GROUP BY requester_id

UNION ALL

SELECT accepter_id AS id, COUNT(accepter_id) AS Total FROM RequestAccepted    
GROUP BY accepter_id 
) AS result
GROUP BY  result.id
ORDER BY num DESC 
LIMIT 1 ;