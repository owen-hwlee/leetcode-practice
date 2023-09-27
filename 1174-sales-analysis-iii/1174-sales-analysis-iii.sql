# Write your MySQL query statement below
SELECT Product.product_id, product_name
FROM Product
WHERE Product.product_id NOT IN (
    SELECT DISTINCT(product_id)
    FROM Sales
    WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
) AND Product.product_id IN (
    SELECT DISTINCT(product_id)
    FROM Sales
);
