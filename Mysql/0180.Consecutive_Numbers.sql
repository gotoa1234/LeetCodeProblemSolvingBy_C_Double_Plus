-- Write your MySQL query statement below
-- Runtime 450 ms Beats 91.90%
     SELECT Distinct(T1.num) AS ConsecutiveNums  
       FROM Logs AS T1
  LEFT JOIN Logs AS T2 ON T1.id = (T2.id + 1)
  LEFT JOIN Logs AS T3 ON T1.id = (T3.id + 2)
      WHERE T1.num = T2.num 
        AND T2.num = T3.num;