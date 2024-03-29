-- Write your MySQL query statement below
-- Runtime 1000 ms Beats 95.13%
         SELECT employee_id, 
                department_id
           FROM Employee
       GROUP BY employee_id
      HAVING COUNT(employee_id) = 1
      UNION
         SELECT employee_id, department_id
           FROM Employee
          WHERE primary_flag = 'Y'
