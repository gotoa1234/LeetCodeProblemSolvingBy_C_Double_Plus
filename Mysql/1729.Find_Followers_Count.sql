-- Write your MySQL query statement below
-- Runtime 1297 ms 50.02 Beats %
  SELECT user_id,
         COUNT(user_id) AS followers_count 
    FROM Followers
GROUP BY user_id
ORDER BY user_id ASC