-- Write your MySQL query statement below
-- Runtime 749 ms Beats 67.36%
SELECT * 
  FROM Patients
 WHERE conditions LIKE '% DIAB1%'
    OR conditions LIKE 'DIAB1%'
