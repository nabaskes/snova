#include <vector>
#include <string>
#include <tuple>
#include <math.h>
#include "../simulator.cpp"

class HeatSimulator : public Simulator {
  double alpha;
  int N;
public:
  HeatSimulator(int rows,
		int cols,
		std::vector<std::tuple<int,int, double>> boundary_conds,
		std::vector<std::vector<double>> init_conds) :
    Simulator(rows, cols, boundary_conds, init_conds) {
    N = max(rows, cols);
    alpha = (4/(2 + sqrt(4 - (2*cos(M_PI/N))))) - 1;
    return;
  }

  double iterate_forward_fin_diff(std::vector<std::vector<double>>* universe,
				  int i,
				  int j) {
    double uu = .25 * ((*universe)[i+1][j] + (*universe)[i-1][j]+(*universe)[i][j+1]+(*universe)[i][j-1]);
    return (*universe)[i][j] = uu + alpha * (uu - (*universe)[i][j]);
  }
};
