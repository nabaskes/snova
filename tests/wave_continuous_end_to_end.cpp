#include <vector>
#include <tuple>
#include "../fin_diffs/wave_eq/wave_eq.cpp"
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
  boundary_conds.reserve(1);
  boundary_conds.push_back(std::make_tuple(49, 49, 255.0));

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

  calc_wave(rows, cols, 10000, "endtoend", print_times, boundary_conds, init_conds);

}
