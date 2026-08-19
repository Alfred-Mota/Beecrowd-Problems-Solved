# beecrowd - SQL 2608 Maior e Menor

## Enunciado (resumo)
Exibir o maior e menor preço da tabela produtos.
## Estratégia
- Identificar quais tabelas: __products__
- Colunas selecionadas: __price__
- Ordenar os resultados utilizando ORDER BY ASC (ascendente) ou ORDER BY DESC (descendente) e limitar a 1 resultado de resposta. Dessa forma deve-se utilizar consultas aninhadas
- Ou utilizar os operadores MAX() e MIN()

## Query

```sql
-- Utilizando operadores MAX() e MIN()
select Max(price) as price, Min(price) as price
from products

-- Forma aninhada:
Select 
(SELECT price
FROM products
ORDER BY price DESC
LIMIT 1),

(SELECT price
FROM products
ORDER BY price ASC
LIMIT 1);
