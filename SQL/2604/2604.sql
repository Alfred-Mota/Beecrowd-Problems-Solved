select id, name
from products
where price < 10 or price > 100

SELECT id, name
FROM products
WHERE price < 10

UNION ALL

SELECT id, name
FROM products
WHERE price > 100;