# Lista 3

## Descrição do projeto
Este projeto traz uma solução em C++ para um sistema de matchmaking para jogadores em busca de uma partida online, os players possuem um nome, um identificador único, um score, e um timestamp que representa a hora de chegada na fila de espera. No sistema, todos os players são armazenados em um único array e visando a formação de grupos foram implementados dois algoritmos de ordenação, o insertion sort e o merge sort, para que seja possível encontrar um determinado grupo de players com scores dentro do limite desejado.

Para que o sistema funcione é considerado que as características de um player sigam as seguintes propriedades:
* Possuir um score válido
* Ter um id único que ainda não esteja no sistema
* Respeitar a ordem de chegada em relação aos outros players.

O sistema é inicializado com o array de players vazio e conforme novos jogadores são adicionados, é possível formar grupos, desde que existam players que atendam às características solicitadas, e extrair informações do sistema como quantos players estão armazenados, além da exibição do estado atual do sistema, imprimindo no terminal a lista de players na fila de espera.
## Instruções de compilação
O código deve ser compilado por meio do seguinte comando em seu terminal. 

```
g++ main.cpp Matchmaking.cpp Player.cpp AuxiliarFunctions.cpp -o matchmaking
```

Instrução para "ComparacoesMedicoes.cpp" (Não é necessário para rodar a main):
```
g++ ComparacoesMedicoes.cpp Matchmaking.cpp Player.cpp AuxiliarFunctions.cpp -o comparacoes
```

## Instruções de execução
Assim que o arquivo for compilado, será criado um arquivo de formato .exe, o qual você poderá executar com o seguinte comando.  

```
.\matchmaking.exe
```

Instrução para "ComparacoesMedicoes.cpp" (Não é necessário para rodar a main):

```
.\comparacoes.exe
```
## Organização dos arquivos
A divisão de arquivos foi pensada da seguinte forma:
* Um arquivo chamado "Matchmaking", que é responsável pela parte principal, já que é onde é feito o armazenamento dos players e onde estão as funções responsáveis pelas operações dentro do sistema
* Um arquivo chamado "Players", responsável pela definição do objeto player dentro do sistema.
* Um arquivo chamado "AuxiliarFunctions", criado para auxiliar na implementação do algoritmo de ordenação Merge Sort
* Um arquivo chamado "main", onde o sistema é efetivamente aplicado, já que é nesse arquivo que os players são criados e inseridos no matchmaking.

Todos esses arquivos, com exceção da main, estão divididos em um .hpp, com as assinaturas das funções e um .cpp, com a implementação. Além disso, existe um arquivo chamado "ComparacoesMedicoes.cpp" que possui o código usado para comparar os algoritmos de ordenação Merge Sort e Insertion Sort com base no número de players dentro do sistema. Caso haja necessidade de rodar essa comparação, basta seguir a instrução de compilação para "ComparacoesMedicoes.cpp" e depois a instrução de execução.

## Execução de testes
Para executar os testes no arquivo main.cpp, basta que sejam seguidas as instruções de compilação e execução presentes neste readme, já que no próprio arquivo o código está estruturado de modo que não é preciso fazer nenhuma alteração, executando de uma vez só todos os casos de operações do sistema.