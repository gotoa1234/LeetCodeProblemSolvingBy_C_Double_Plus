-- Write your MySQL query statement below
-- Runtime 898 ms Beats 52.94%
SELECT author_id AS id
  FROM Views 
 WHERE author_id = viewer_id
 GROUP BY author_id
 ORDER BY author_id