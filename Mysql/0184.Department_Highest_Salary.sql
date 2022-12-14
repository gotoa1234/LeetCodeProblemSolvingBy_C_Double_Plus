-- Write your MySQL query statement below
-- Runtime 562 ms Beats 90.52%
     SELECT MyTemp.name AS `Department`,
            E.name AS `Employee`,
            E.salary AS `Salary`
       FROM Employee AS E
 INNER JOIN (
     SELECT MAX(Employee.salary) AS MaxSalary,
            Department.id,
            Department.name
       FROM Employee
 INNER JOIN Department 
         ON Employee.departmentId = Department.id
   GROUP BY Employee.departmentId
 )AS MyTemp 
         ON E.departmentId = MyTemp.id
      WHERE E.salary = MyTemp.MaxSalary;