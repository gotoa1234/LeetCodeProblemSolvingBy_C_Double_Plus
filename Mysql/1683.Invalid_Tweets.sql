-- Write your MySQL query statement below
-- 1215 ms Beats 73.26%
SELECT tweet_id
  FROM Tweets
 WHERE Length(content) >15;