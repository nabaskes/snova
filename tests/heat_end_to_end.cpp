#include <vector>
#include <tuple>
#include "../heat_eq/heat_eq.cpp"
#include "../boundary_conds/boundaries.cpp"


int main() {

  int rows = 100;
  int cols = 100;

  std::vector<int> print_times;
  print_times.reserve(21);
  print_times.push_back(10);
  print_times.push_back(100);
  print_times.push_back(200);
  print_times.push_back(300);
  print_times.push_back(400);
  print_times.push_back(500);
  print_times.push_back(600);
  print_times.push_back(700);
  print_times.push_back(800);
  print_times.push_back(900);
  print_times.push_back(1000);
  print_times.push_back(2000);
  print_times.push_back(3000);
  print_times.push_back(4000);
  print_times.push_back(5000);
  print_times.push_back(6000);
  print_times.push_back(7000);
  print_times.push_back(8000);
  print_times.push_back(9000);
  print_times.push_back(9999);

  std::vector<std::tuple<int, int, double>> boundary_conds;
  BoundaryRow top_row (rows, cols, 255, 0);
  BoundaryRow bot_row (rows, cols, 0, rows-1);
  BoundaryColumn left_col (rows, cols, 255, 0);
  BoundaryColumn right_col (rows, cols, 0, cols-1);
  top_row.add_boundary(bot_row);
  top_row.add_boundary(left_col);
  top_row.add_boundary(right_col);

  boundary_conds = top_row.get_conditions();

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

  calc_heat(rows, cols, 10000, "endtoend", print_times, boundary_conds, init_conds);
}
