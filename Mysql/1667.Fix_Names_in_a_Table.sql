-- Write your MySQL query statement below
-- Runtime 1034 ms Beats 98.32%
  SELECT user_id,
         CONCAT(UPPER(SUBSTR(U.name, 1, 1)) , LOWER(SUBSTR(U.name, 2, LENGTH(U.name) -1))) AS NAME
    FROM Users AS U
ORDER BY user_id ASC