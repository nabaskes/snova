/*
@author: nabaskes


prints out solution to 2D heat equation at a given time

*/

#include <vector>
#include <string>
#include <tuple>
#include <math.h>
#include "../image_gen/image_generator.cpp"

template <class T> const T& max (const T& a, const T& b) {
  return (a<b)?b:a;
}



std::vector<std::vector<double>> calc_heat(int rows,
					   int cols,
					   int duration,
					   std::string outpath,
					   std::vector<int> print_times,
					   std::vector<std::tuple<int, int, double>> boundary_conds,
					   std::vector<std::vector<double>> init_conds
					   ) {

  // create output vector initialized to init_conds
  std::vector<std::vector<double>> universe;
  universe.reserve(rows);
  for (int i=0; i<rows; i++) {
    std::vector<double> row;
    row.reserve(cols);
    for (int j=0; j<cols; j++) {
      row.push_back(init_conds[i][j]);
    }
    universe.push_back(row);
  }


  int N = max(rows, cols);
  ImageGenerator i_gen (rows, cols);
  double alpha = (4/(2 + sqrt(4 - (2*cos(M_PI/N))))) - 1;
  std::vector<int>::iterator time_it = print_times.begin();

  // now, do the primary iteration
  for(int t=0; t<duration; t++) {
    // fix boundary conds
    for(auto tup : boundary_conds) {
      universe[std::get<0>(tup)][std::get<1>(tup)] = std::get<2>(tup);
    }

    // print out if necessary
    if (t == *time_it) {
      std::string path = outpath + "_" + std::to_string(*time_it);
      i_gen.generate_image(path, universe);
      time_it++;
    }


  }

  return universe;
}
