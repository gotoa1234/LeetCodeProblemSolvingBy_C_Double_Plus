-- Write your MySQL query statement below
-- Runtime ms Beats %
SELECT Result.teacher_id,
       MAX(total) AS cnt
FROM( SELECT teacher_id,
             dept_id,
             COUNT(*) AS total
        FROM Teacher
     GROUP BY teacher_id, dept_id
 ) AS Result
 GROUP BY Result.teacher_id
 