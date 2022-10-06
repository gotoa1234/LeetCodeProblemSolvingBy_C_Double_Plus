-- Write your MySQL query statement below
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