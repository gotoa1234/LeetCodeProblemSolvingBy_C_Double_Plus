-- Write your MySQL query statement below
-- Runtime 924 ms Beats 33.22%
 SELECT 
        CASE WHEN id % 2 = 1 THEN 
                             IF( (id + 1) <= (SELECT COUNT(1) FROM Seat ),  id + 1 , id)
                             ELSE id - 1
        END AS id, 
        student
   FROM Seat
  ORDER BY id ASC
  
  
  