-- Write your MySQL query statement below
-- Runtime 1184 ms Beats 47.66%

SELECT ROUND(  COUNT(player_id) / 
               ( SELECT COUNT(DISTINCT player_id) 
                   FROM Activity
               ) 
          ,2) AS fraction
  FROM Activity
 WHERE (player_id, event_date) 
    IN(SELECT player_id, 
              DATE_ADD(Min(event_date),INTERVAL 1 DAY) AS event_date
         FROM Activity 
     GROUP BY 1
);