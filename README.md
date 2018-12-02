# _Projeto de ITP_  -  Sistema gerenciador de Banco De Dados (_SGBD_)

## _Contribuidores:_

>*João Marcos*

>*Guilherme Lira*


## *_AVISO_*

O sistema ainda não pronto para uso, pois as funções de editar dados ainda não estão prontas

Isto é, as funções mais importantes de um sistema de banco de dados

### :D

Muito Muito brevemente o sistema estará funcional, observe no final desta página o progresso.


## *_Funcionalidade_*

O SGBD ITP permitirá ao usuário criar, manipular e deletar tabelas com todos os tipos de dados básicos nativos de C.

O programa tem foco em economizar RAM, pois as tabelas do banco de dados não são carregadas inteiramente na memória para uso, como acontece muito comumente em bancos de dados atuais, as operações são sempre realizadas diretamente nos arquivos.

O SGBD é um programa atualmente focado para usuários de linux, o seu uso no Windows pode não ser totalmente suportado, e precisar de alterações no código fonte, como o acesso dos diretórios, por exemplo.


## *_Instalação_*

Para compilar o programa, você precisa ter o Gnu Compiler Collection (*GCC*) instalado,
Em derivados de debian:

> sudo apt install build-essential

Depois disso, você pode clonar este repositório localmente no seu computador

> sudo apt install git

Agora vá até o diretório onde deseja colocar a pasta desse repositório, e o clone

> cd diretorio # O diretório em que deseja intalar o sistema
> git clone git@github.com:marcospb19/projeto-itp.git
> cd projeto-itp # Para entrar na pasta criada

Para compilar, use o make.sh

> ./make.sh

Para rodar, execute o executável *SGBD*

> ./sgbd

Pronto, você está usando o sgbd, escreva *help* ou leia o tópico *_Lista de Comandos_* da página para comandos do sistema.


## Lista de Comandos:

>*_"help"_*          Mostra essa mensagem, \
>*_"exit or q"_*     Sai do programa, \
>*_"credits"_*       Mostra os creditos, \
>*_"license"_*       Mostra a licença.

>*_"list"_*          Lista todas as tabelas, \
>*_"search"_*        Procura por dados dentro de uma tabela,
>*_"printtable"_*    List all data inside of a table. \

>*_"create"_*        Cria uma tabela, \
>*_"line"_*          Cria uma linha dentro de uma tabela, \
>*_"column"_*        Cria uma coluna em uma tabela, \
>*_"remove"_*        Deleta uma tabela do sistema.

Ao digitar *_help_*, os comandos estarão coloridos para demonstrar sua disponibilidade


## *_Valgrind_*

A ferramenta valgrind pode ser usada nesse projeto para verificar o vazamento de memória (*memory leak*), para isso, vocế só precisa ter o valgrind instalado e rodar o shell script que está dentro da pasta

O shell script usará o executável *_sgbd_* que precisa ser compilado pelo usuário, como foi mostrado na seção *_Instalação_*, então antes de checar por vazamento de memórias, instale corretamente o programa

Em derivados de debian

> sudo apt install valgrind
> ./valgrind.sh

Então você pode testar o sistema, e quando encerrar, verificar o relatório de uso de memória gerado pelo valgrind, que estará em projeto-itp/log/valgrindLog.txt

Você deve encontrar no log alguns vazamentos que ainda não foram consertados

# :D


## *_Progresso:_*
- [x] 1) Criar um tabela
- [x] 2) Listar todas as tabelas
- [ ] 3) Criar uma nova linha na tabela
- [ ] 4) Editar os valores de uma tabela
- [x] 5) Criar uma nova coluna na tabela
- [x] 6) Listar todos os dados de uma tabela
- [x] 7) Pesquisar valor em uma coluna
- [ ] 8) Apagar valor de uma tabela
- [x] 9) Apagar uma tabela


## *_Extras:_*
- [x] Uso de repositório online para armazenamento
- [x] Uso de repositório online para documentação do código
- [ ] Uso de sistema de build automático (CMake ou Makefile)
- [ ] Demonstração gráfica reponsiva da estrutura das tabelas
- [ ] Chave secundária relacional
