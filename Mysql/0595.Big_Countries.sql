-- Write your MySQL query statement below
SELECT NAME, population, AREA
  FROM World
  WHERE AREA >= 3000000
     OR population >= 25000000
