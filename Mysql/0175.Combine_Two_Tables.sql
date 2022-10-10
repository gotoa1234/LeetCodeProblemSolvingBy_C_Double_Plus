-- Write your MySQL query statement below
-- Runtime 381 ms Beats 85.61%
SELECT P.firstName,
       P.lastName,
       A.city,
       A.state      
  FROM Person AS P
  LEFT JOIN Address AS A
    ON P.personId = A.personId;