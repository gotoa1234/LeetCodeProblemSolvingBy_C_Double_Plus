-- Write your MySQL query statement below
-- Runtime 636 ms Beats 40.35%
SELECT x, 
       y, 
	   z,
	   IF( (X+Y) > Z AND (X+Z) > Y AND (Z+Y) >X , 'Yes', 'No') AS triangle 
  FROM triangle