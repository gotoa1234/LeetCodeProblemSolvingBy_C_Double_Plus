-- Write your MySQL query statement below
-- Runtime 2432 ms Beats 75.88%
SELECT 'Low Salary' AS 'category', 
       COUNT(*) AS accounts_count
  FROM Accounts 
 WHERE income < 20000 
      UNION 
SELECT 'Average Salary' AS 'category', 
        COUNT(*) AS accounts_count
  FROM Accounts 
 WHERE income >= 20000 AND income <= 50000
       UNION 
SELECT 'High Salary' AS 'category', 
        COUNT(*) AS accounts_count
  FROM Accounts 
 WHERE income > 50000