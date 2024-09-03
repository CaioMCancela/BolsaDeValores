# Sistema de Registro de Operações na Bolsa de Valores
## Descrição do Projeto
Este projeto é um sistema simples para o registro de operações realizadas na bolsa de valores. O sistema permite que os usuários registrem operações de compra e venda de ações, armazenando informações essenciais como o ticker da empresa, a quantidade de ações em carteira e o preço médio por ação. O objetivo é fornecer ao usuário uma interface simples para gerenciar seu portfólio de investimentos.

## Funcionalidades

### Registrar Compra:
Solicita ao usuário o ticker da empresa (uma cadeia de caracteres de até 6 letras, ex: ITSA4, TAEE11, BBAS3), a quantidade comprada e o valor do ativo no momento da compra.
Atualiza o preço médio das ações em carteira após cada compra.
### Registrar Venda:

Solicita ao usuário o ticker da empresa, a quantidade vendida e o valor do ativo no momento da venda.
Permite a venda somente se houver saldo suficiente de ações.
Apenas a quantidade de ações é modificada; o preço médio permanece inalterado.
### Ver o Saldo de um Ativo (Busca por Ticket):

Permite ao usuário consultar o saldo de um ativo específico, exibindo a quantidade em carteira e o preço médio.
Implementa busca binária para otimizar a consulta dos ativos.
### Listar Patrimônio:

Exibe todos os ativos do investidor, incluindo a quantidade em carteira e o preço médio.
### Sair:

Encerra a aplicação.
