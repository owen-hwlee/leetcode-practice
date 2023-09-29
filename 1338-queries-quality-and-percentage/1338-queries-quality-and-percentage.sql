# Write your MySQL query statement below
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(SUM(CASE WHEN rating < 3 then 1 else 0 END) / COUNT(*) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;
