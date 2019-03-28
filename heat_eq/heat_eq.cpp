/*
@author: nabaskes


prints out solution to 2D heat equation at a given time

*/

#include <vector>
#include <string>
#include <tuple>
#include <math.h>

template <class T> const T& max (const T& a, const T& b) {
  return (a<b)?b:a;
}



std::vector<std::vector<double>> calc_heat(int rows,
					   int cols,
					   int duration,
					   std::string outpath,
					   std::vector<int> print_times,
					   std::vector<std::tuple<int, int, int>> init_conds
					   ) {

  // create output vector initialized to zeros
  std::vector<std::vector<double>> universe;
  universe.reserve(rows);
  for (int i=0; i<rows; i++) {
    std::vector<double> column;
    column.reserve(cols);
    for (int j=0; j<cols; j++) {
      column.push_back(0);
    }
    universe.push_back(column);
  }

  // set initial conditions
  for(auto tup : init_conds) {
    universe[std::get<0>(tup)][std::get<1>(tup)] = std::get<2>(tup);
  }

  int t = 0;
  int N = max(rows, cols);
  double alpha = (4/(2 + sqrt(4 - (2*cos(M_PI/N))))) - 1;

  // now, do the primary iteration
}
