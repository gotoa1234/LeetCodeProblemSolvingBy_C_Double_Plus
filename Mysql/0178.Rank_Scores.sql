-- Write your MySQL query statement below
-- Runtime 343 ms Beats 63.2%
SELECT Scores.score,
       RankT.rank
  FROM Scores
  LEFT JOIN (
SELECT row_number() over(ORDER BY score DESC) AS 'rank',
       score
  FROM Scores
  GROUP BY score
 ORDER BY score DESC 
) AS RankT 
  ON Scores.score = RankT.score
  ORDER BY RankT.rank ASC