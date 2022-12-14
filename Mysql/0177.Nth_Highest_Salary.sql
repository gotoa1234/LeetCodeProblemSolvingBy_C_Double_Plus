-- 此為 Mysql 的 function 語法，body 在 BEGIN 到 END 之間
-- Runtime 325 ms Beats 90.16%
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N=N-1;
  RETURN (
      SELECT Distinct(salary)
        FROM employee
       ORDER By salary DESC LIMIT 1 OFFSET N
  );
END