 -- Write your MySQL query statement below
     SELECT D.name AS Department,
            E.name AS Employee,
            E.salary AS Salary
       FROM Employee AS E
 INNER JOIN Department AS D
   ON E.`departmentId` = D.`id`
      WHERE 3 > (
      SELECT COUNT(DISTINCT(salary))
        FROM Employee InnerE
       WHERE InnerE.`salary` > E.`salary`
         AND InnerE.`departmentId` = E.`departmentId`
      );