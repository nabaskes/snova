/*
@author: nabaskes

prints out solution to 2D wave equation at a given time

 */

#include <vector>
#include <string>
#include <tuple>
#include <math.h>
#include "../../image_gen/image_generator.cpp"

template <class T> const T& max (const T& a, const T& b) {
  return (a<b) ? b : a;
}


std::vector<std::vector<double>> calc_wave(int rows,
					   int cols,
					   int duration,
					   std::string outpath,
					   std::vector<int> print_times,
					   std::vector<std::tuple<int, int, double>> boundary_conds,
					   std::vector<std::vector<double>> init_conds) {
  std::vector<std::vector<double>> even_u;
  std::vector<std::vector<double>> odd_u;
  even_u.reserve(rows);
  odd_u.reserve(rows);
  for(int i=0; i<rows; i++) {
    std::vector<double>row;
    row.reserve(cols);
    for(int j=0; j<cols; j++) {
      row.push_back(init_conds[i][j]);
    }
    even_u.push_back(row);
    odd_u.push_back(row);
  }

  ImageGenerator i_gen (rows, cols);
  std::vector<int>::iterator time_it = print_times.begin();
  double uu = 0.0;
  double hx = 0.01; // assume that discretization is same size in x and y
  double ht = 0.001;
  double c = 1.0;
  double lambda = c * c * ht * ht / (hx * hx);

  // do the primary iteration
  for (int t=0; t<duration; t++) {

    // fix boundary conds
    for(auto tup: boundary_conds) {
      even_u[std::get<0>(tup)][std::get<1>(tup)] = std::get<2>(tup);
      odd_u[std::get<0>(tup)][std::get<1>(tup)] = std::get<2>(tup);
    }

    // print if necessary
    if (t == *time_it) {
      std::string path = outpath + "_" + std::to_string(*time_it);
      if ( (t & 1) == 0) {
	i_gen.generate_image(path, even_u);
      } else {
	i_gen.generate_image(path, odd_u);
      }
      time_it++;
    }

    // iterate the universe

    for (int i=1; i<rows-1; i++) {
      for (int j=1; j<cols-1; j++) {

	/*
	   this whole even - odd thing allows us to store previous data,
	   which is needed for the backwards time steps in the finite difference

	   This method allows us to avoid copying the entire universe every step
	   Unfortunately it makes the code a little bit confusing
	*/
	if ( (duration & 1) == 0){
	  uu = lambda * (even_u[i-1][j] + even_u[i][j-1] + odd_u[i+1][j] + odd_u[i][j+1] - 4 * odd_u[i][j]);
	  even_u[i][j] =  2 * odd_u[i][j] + uu - even_u[i][j];
	} else {
	  uu = lambda * (odd_u[i-1][j] + odd_u[i][j-1] + even_u[i+1][j] + even_u[i][j+1] - 4 * even_u[i][j]);
	  odd_u[i][j] = 2 * even_u[i][j] + uu - odd_u[i][j];
	}


      }
    }
  }

  // return the proper universe
  if ( (duration & 1) == 0) {
    return even_u;
  } else {
    return odd_u;
  }

}
