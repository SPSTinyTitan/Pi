//Yuke Wang

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <thread>
#include <future>
#include <vector>
#include <mpi.h>

float randf();
int pi_monte_carlo(int iters);


int main(int argc, const char * argv[]) {
//    Setting random seed
    srand(static_cast<unsigned int>(clock()));
//    Starting MPI
    int id;
    int p;
    MPI_Init ( &argc, &argv );
    MPI_Comm_rank ( MPI_COMM_WORLD, &id );
    MPI_Comm_size ( MPI_COMM_WORLD, &p );
    
    if (id == 0)
        std::cout << "Running on " << p << " nodes." << std::endl;
    
    int iters = 1000;
    
//    Main node waits to receive data and prints result
    if (id == 0){
        int results[p-1];
        for(int i = 1; i < p; i++)
            MPI_Recv(results[i-1], i, MPI_INT, i, MPI_ANY_TAG);
        int total = 0;
        for(int i = 0; i < p-1; i++)
            total += results[i];
        std::cout << 4*(float)total/(iters * (p-1)) << std::endl;
    }
    
//    Other nodes run monte carlo simulation
    else{
        int result = pi_monte_carlo(iters);
        MPI_Send(&result, 1, MPI_INT, 0, 0);
    }
    
//    Cleaning up
    MPI_Finalize ( );
    if (id == 0)
        std::cout << "End of simulation" << std::endl;
    return 0;
}

//Monte Carlo Simulation for calculating pi
int pi_monte_carlo(int iter){
    int count = 0;
    for (int i = 0; i < iter; i++)
        if ((pow(randf(),2) + pow(randf(),2)) > 1)
            count++;
    return count;
}

//Random floating point number generator
float randf(){
    return float(rand()) / (float(RAND_MAX) + 1.0);
}
