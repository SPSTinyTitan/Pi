#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

int main() {
	//Start timing the program
	auto start = chrono::steady_clock::now();

	int hits = 0;
	int iter;
	double x, y, pi;

	//Set seed
	srand(time(NULL));

	iter = 10000000;
	for (int j = 0; j < iter; j++) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;

		//Restricting the region of interest
		if ((y>(-x+1))&&(y<(-x+1.4142136))) {
			if ((x * x + y * y) <= 1) {
				hits += 1;
			}
		}
	}

	// hits/iter = target area/total area
	// hits/iter = pi/4 - 1/2, for the region b/w the quartercircle and y=-x+1
	pi = 4 * (double)hits / iter + 2;

	//Stop timing to find elapsed time for the program (in ms)
	auto end = chrono::steady_clock::now();
	cout << "Pi is approximated to: " << pi << endl;
	cout << "Elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisec" << endl;

	system("pause");
	return 0;

	//Note: I've found that the elapsed time is very nearly the same with/without restricting the region
}