# beecrowd - SQL 2604 Menores que 10 ou Maiores que 100

## Enunciado (resumo)
Filtrar codigo e nome de produtos cujo preço são menores que 10 ou maiores que 100
## Estratégia
- Identificar quais tabelas: __products__
- Colunas selecionadas id e name
- Filtro pela cidade: WHERE price < 10 or price > 100, filtra os produtos utilizando qualquer uma das condições
- Outra forma seria utilizar UNION ALL, filtra separadamente as condições e depois concatena as tabelas

## Query

```sql
-- Utilizando OR
select id, name
from products
where price < 10 or price > 100

-- Utilizando UNION ALL

SELECT id, name
FROM products
WHERE price < 10

UNION ALL

SELECT id, name
FROM products
WHERE price > 100;
