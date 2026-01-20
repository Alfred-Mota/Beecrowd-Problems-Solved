# beecrowd - SQL 2603 Endereço dos Clientes

## Enunciado (resumo)
Filtrar nome e rua dos clientes na tabela __customers__ que moram na cidade de Porto Alegre
## Estratégia
- Identificar quais tabelas: __customers__
- Colunas selecionadas name e street
- Filtro pela cidade: WHERE city = 'Porto Alegre'

## Cuidados
- Strings de texto devem ser comparadas utilizando aspas simples 'Porto Alegre'

- Em SQL, aspas duplas costumam ser usadas para identificadores (nomes de colunas/tabelas) em alguns bancos, então evite usá-las para texto.

- O filtro acima é uma comparação exata. Se existirem variações como espaços extras ('Porto Alegre '), acentos diferentes, ou diferenças de maiúsculas/minúsculas (dependendo do banco), pode ser necessário tratar — mas para o beecrowd esse formato geralmente é suficiente.
## Query

```sql
select name, street
from customers
where city = 'Porto Alegre'
