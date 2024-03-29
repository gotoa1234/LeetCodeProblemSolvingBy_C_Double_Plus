-- Write your MySQL query statement below
-- Runtime 1036 ms Beats 55.18%
SELECT Result.activity_date AS DAY,
       COUNT(user_id) AS active_users
  FROM(
   SELECT user_id, activity_date
     FROM activity
    WHERE activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
 GROUP BY user_id, activity_date
      )AS Result
GROUP by Result.activity_date
ORDER BY DAY ASC