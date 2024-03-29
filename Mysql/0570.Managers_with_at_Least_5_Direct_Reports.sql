-- Write your MySQL query statement below
-- Runtime 698 ms Beats 36.5%

SELECT Employee.name
  FROM Employee
 WHERE id IN ( 
              SELECT managerId
                FROM  Employee   
               GROUP BY managerId
               HAVING COUNT(*) >= 5
);

