/*
@author: nabaskes

solves laplace equation in 2d

 */

#include <vector>
#include <string>
#include <tuple>
#include "../simulator.cpp"

class LaplaceSimulator : public Simulator {
public:
  LaplaceSimulator(int rows,
		   int cols,
		   std::vector<std::tuple<int, int, double>> boundary_conds,
		   std::vector<std::vector<double>> init_conds) :
    Simulator(rows, cols, boundary_conds, init_conds) {
    return;
  }

  double iterate_forward_fin_diff(std::vector<std::vector<double>> universe,
				  int i,
				  int j) {
    return universe[i][j] = .5 * (universe[i-1][j] + universe[i][j-1]);
  }
};
