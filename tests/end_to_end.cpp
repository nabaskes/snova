#include <vector>
#include <tuple>
#include "../heat_eq/heat_eq.cpp"



int main() {

  int rows = 100;
  int cols = 100;

  std::vector<int> print_times;
  print_times.reserve(10);
  print_times.push_back(10);
  print_times.push_back(100);
  print_times.push_back(200);
  print_times.push_back(300);
  print_times.push_back(400);
  print_times.push_back(500);
  print_times.push_back(600);
  print_times.push_back(700);
  print_times.push_back(999);

  std::vector<std::tuple<int, int, double>> boundary_conds;
  boundary_conds.reserve(3);
  boundary_conds.push_back(std::make_tuple(0,0, 255.0));
  boundary_conds.push_back(std::make_tuple(99,99, 0.0));
  boundary_conds.push_back(std::make_tuple(0,99, 255.0));

  std::vector<std::vector<double>> init_conds;
  init_conds.reserve(rows);
  for (int i=0; i<rows; i++) {
    std::vector<double> row;
    row.reserve(cols);
    for (int j=0; j<cols; j++) {
      row.push_back(0.0);
    }
    init_conds.push_back(row);
  }

  calc_heat(rows, cols, 1000, "endtoend", print_times, boundary_conds, init_conds);
}
