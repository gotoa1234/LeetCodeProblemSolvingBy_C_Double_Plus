# Write your MySQL query statement below
SELECT NAME 
  FROM SalesPerson
  WHERE SalesPerson.sales_id NOT IN (
SELECT DISTINCT(S.sales_id)
  FROM SalesPerson AS S
  LEFT JOIN Orders AS O
  ON O.sales_id = S.sales_id
  WHERE com_id = (SELECT com_id FROM Company WHERE NAME ='RED')
  );