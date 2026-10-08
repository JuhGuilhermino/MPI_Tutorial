#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    // Inicializa o ambiente MPI
    MPI_Init(&argc, &argv);

    // Obtém o número total de processos em execução
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtém o rank (identificador) do processo atual
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Imprime a mensagem de cada processo
    std::cout << "Olá do processo " << world_rank 
              << " de um total de " << world_size << " processos." << std::endl;

    // Finaliza o ambiente MPI
    MPI_Finalize();
    return 0;
}