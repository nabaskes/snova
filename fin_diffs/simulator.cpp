/*

@author: nabaskes

class to handle finite differences simulation

 */
#include <vector>
#include <tuple>
#include <string>
#include <math.h>
#include "../image_gen/image_generator.cpp"

template <class T> const T& max (const T& a, const T& b) {
  return (a<b) ? b : a;
}



class Simulator {
  int r, c;
  std::vector<std::tuple<int, int, double>> boundaries;
  std::vector<std::vector<double>> initials;
public:
  Simulator(int rows,
	    int cols,
	    std::vector<std::tuple<int, int, double>> boundary_conds,
	    std::vector<std::vector<double>> init_conds) {
    r = rows;
    c = cols;
    boundaries = boundary_conds;
    initials = init_conds;
  }

  double iterate_forward_fin_diff(std::vector<std::vector<double>> universe,
				  int i,
				  int j) {
    return universe[i][j];
  }

  std::vector<std::vector<double>> calculate(int duration,
					     std::string outpath,
					     std::vector<int> print_times) {
    std::vector<std::vector<double>> u;
    u.reserve(r);

    for (int i=0; i<r; i++) {
      std::vector<double> row;
      row.reserve(c);
      for (int j=0; j<c; j++) {
	row.push_back(initials[i][j]);
      }
      u.push_back(row);
    }

    ImageGenerator i_gen (r, c);
    std::vector<int>::iterator time_it = print_times.begin();

    for (int t=0; t<duration; t++) {

      // set boundary conditions
      for (auto tup: boundaries) {
	u[std::get<0>(tup)][std::get<1>(tup)] = std::get<2>(tup);
      }

      if (t == *time_it) {
	std::string path = outpath + "_" + std::to_string(*time_it);
	i_gen.generate_image(path, u);
	time_it++;
      }

      for (int i=1; i<r-1; i++) {
	for (int j=1; j<c-1; j++) {
	  u[i][j] = iterate_forward_fin_diff(u, i, j);
	}
      }
    }
    return u;
  }

};
