# beecrowd - SQL 2607 Cidades em Ordem Alfabética

## Enunciado (resumo)
Listar as cidades (city) dos fornecedores cadastrados na tabela providers, ordenadas em ordem alfabética.
## Estratégia
- Identificar quais tabelas: __providers__
- Colunas selecionadas city
- Ordenar os resultados utilizando ORDER BY ASC (ascendente) ou ORDER BY DESC (descendente)

## Query

```sql
select city 
from providers
order by city asc 
