-- Write your MySQL query statement below
SELECT A.id
  FROM Weather AS A
  INNER JOIN Weather AS B
  WHERE DATEDIFF(A.recordDate, B.recordDate) = 1
    AND A.temperature > B.temperature;