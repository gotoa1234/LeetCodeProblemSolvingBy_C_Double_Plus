-- Please write a DELETE statement and DO NOT write a SELECT statement.
-- Write your MySQL query statement below
 
-- Mysql 5.7 Solution
-- DELETE Person
--  FROM Person,
--       Person AS pTemp
-- WHERE pTemp.email = Person.email
--   AND pTemp.id < Person.id


-- Mysql 8.0 Solution
WITH subQuery AS (
   SELECT MIN(id) AS ContainId
     FROM Person
     GROUP BY email
)
DELETE FROM Person
 WHERE id NOT IN(SELECT ContainId FROM subQuery)