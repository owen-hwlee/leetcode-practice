# Write your MySQL query statement below
SELECT product_name, unit
FROM Products
INNER JOIN (
    SELECT product_id, SUM(unit) AS unit
    FROM Orders
    WHERE YEAR(order_date) = 2020 AND MONTH(order_date) = 2
    GROUP BY product_id
) t
ON Products.product_id = t.product_id
WHERE unit >= 100;
