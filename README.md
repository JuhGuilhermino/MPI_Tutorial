# Introdução à MPI
Esse repositório contém exemplos intordutórios de programação paralela utilizando MPI (Message Passing
Interface). 
Todos os exemplos e documentação foram baseados na disciplina **DIM0198 - Sistemas Big Data**, ministrada em 2026.2 na Universidade Federal do Rio Grande do Norte.

# Índice 
Comandos - exemplos
- MPI_Init e MPI_Finalize
- MPI_Comm_size e MPI_Comm_rank
- MPI_Send
- MPI_Recive
- MPI_Reduce
- MPI_Allreduce
- MPI_Bcast
- MPI_Scatter
- MPI_Gather
- MPI_Allgather
- MPI_Barrier

# Principais Comandos

## MPI_Init e MPI_Finalize
`MPI_Init` e `MPI_Finalize` são responsaveis respectivamente por inicializar e finalizar o ambiente de execução do MPI. OS comandos MPI devem ser chamados entre essas duas funções
```cpp
int MPI_Comm_size(MPI_Comm comm, int *size);
int MPI_Comm_rank(MPI_Comm comm, int *rank);
```

## MPI_Comm_size
Retorna o número total de processos a executar dentro de um comunicador (ex: MPI_COMM_WORLD).
```cpp
int MPI_Comm_size(MPI_Comm comm, int *size);
```

## MPI_Comm_rank
Retorna o identificador único (rank, variando de $0$ a $N-1$) do processo que chamou a função.
```cpp
int MPI_Comm_rank(MPI_Comm comm, int *rank);
```

## MPI_Send
Envia blocos de dados de um processo de origem para o processo destino. O processo de origem fica bloqueado até receber um retorno.
```cpp
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
```

## MPI_Recive
Recebe uma mensagem de forma bloqueante enviada por outro processo. O processo fica suspenso até que a mensagem seja completamente recebida.
```cpp
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
```

## MPI_Reduce
Coleta os dados de todos os processos do comunicador, aplica uma operação de redução sobre eles (como soma MPI_SUM, máximo MPI_MAX, etc.) e armazena o resultado final apenas no processo raiz (root).
```cpp
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);
```

## MPI_Allreduce
Realiza a mesma operação de redução do MPI_Reduce, porém o resultado final é distribuído e armazenado em todos os processos do comunicador, dispensando o argumento root.
```cpp
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
```

## MPI_Bcast
Transmite uma mensagem do processo raiz (root) para todos os outros processos no comunicador.
```cpp
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
```

## MPI_
Divide um vetor de dados localizado no processo raiz (root) em fatias de tamanho igual e envia cada fatia para um processo diferente no comunicador.
```cpp
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
```

## MPI_Gather
Faz o oposto do MPI_Scatter. Coleta blocos de dados de tamanho igual provenientes de todos os processos e concatena-os num único vetor armazenado apenas no processo raiz (root).
```cpp
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
```

## MPI_Allgether
Coleta blocos de dados de todos os processos (assim como o MPI_Gather), mas armazena o vetor concatenado final em todos os processos do comunicador.
```cpp
int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
```

## MPI_Barrier
Cria um ponto de sincronização coletivo (barreira). Nenhum processo avança a sua execução além da chamada da barreira até que todos os outros processos do comunicador também a tenham alcançado.
```cpp
int MPI_Barrier(MPI_Comm comm);
```

