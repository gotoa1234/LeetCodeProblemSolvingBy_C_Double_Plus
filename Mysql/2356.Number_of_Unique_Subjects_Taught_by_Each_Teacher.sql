-- Write your MySQL query statement below
-- Runtime 1076 ms Beats 60.63% 
SELECT Result.teacher_id,
       COUNT(Result.teacher_id) AS cnt
FROM (
       SELECT teacher_id, subject_id
         FROM teacher 
     GROUP BY teacher_id,subject_id
    ) AS Result
GROUP BY Result.teacher_id