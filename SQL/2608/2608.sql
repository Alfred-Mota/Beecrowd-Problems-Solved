Select 
(SELECT price
FROM products
ORDER BY price DESC
LIMIT 1),

(SELECT price
FROM products
ORDER BY price ASC
LIMIT 1);