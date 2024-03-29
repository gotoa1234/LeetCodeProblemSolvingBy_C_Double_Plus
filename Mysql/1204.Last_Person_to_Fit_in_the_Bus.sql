-- Write your MySQL query statement below

-- Mysql 8.0.2 Before
-- Runtime 4069  ms Beats 5.99 %
  SELECT person_name		
    FROM queue AS A
   WHERE (
          SELECT SUM(weight)
            FROM queue AS B
           WHERE A.turn >= B.turn
          )<= 1000
ORDER BY turn DESC
   LIMIT 1;

-- Mysql 8.0.2 After
-- Runtime 2583 ms Beats 39.35%
SELECT person_name
  FROM (
  SELECT person_name,
         turn,
         SUM(weight) over (order by turn) as Total
    FROM queue
  ) AS A
WHERE Total <= 1000
ORDER BY turn DESC 
 LIMIT 1;