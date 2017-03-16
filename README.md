# Projeto de SO 1.1 - Manipulação de Processos

###Descrição
O projeto foi proposto por professores da disciplina Projetos de Sistemas Operacionais ministrada na UFRN no período 2017.1.

A primeira parte do projeto é um programa (chamado aqui de **limit**) que tem o objetivo de proteger o sistema operacional da execução de um [Fork Bomb](https://en.wikipedia.org/wiki/Fork_bomb).

A segunda parte do projeto é um programa que recebe o pid de um processo, envia a árvore de seus descendentes para a saída padrão e a salva em um arquivo JSON (o nome deste arquivo será o pid recebido com a extensão json e ficará armazenado na pasta p2). Ele também monitora a quantidade de processos de cada usuário e do total, imprimindo esses valores na saída padrão. Todos os valores citados são impressos a cada intervalo de x segundos definido pelo usuário.

###Autores
* Artur Muricato Curinga - arturmcuring@gmail.com

* Marciel Manoel Leal - marcielmanoel15@gmail.com

###Compilação

Para arquitetura arm:
* make arm

Para arquitetura x86-64:
* make

###Execução

O executável **limit** corresponde à primeira parte do projeto, para executá-lo são necessários dois parâmetros:
* ./p1/limit *\<new soft limit>*  *\<new hard limit>*

O executável **vl** corresponde à segunda parte do projeto, para executá-lo são necessários dois parâmetros - o PID e o tempo entre cada impressão, como podemos ver abaixo:
* ./p2/vl *\<PID of Process>* *\<Time of Refresh>*

O executável **vr** é uma "versão rápida" de **vl**, ele não imprime a árvore na saída padrão, para executá-lo são necessários dois parâmetros - o PID e o tempo entre cada impressão, como podemos ver abaixo:
* ./p2/vr *\<PID of Process>* *\<Time of Refresh>*

###Disponível em: 
https://github.com/marcielleal/OS-project1.1

