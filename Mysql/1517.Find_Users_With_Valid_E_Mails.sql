-- Write your MySQL query statement below
-- Runtime 1149ms Beats 98.35%
SELECT * 
  FROM Users 
 WHERE mail REGEXP '^[a-zA-Z][0-9a-zA-Z_.-]*@leetcode[.]com$'