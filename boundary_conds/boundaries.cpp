/*

@author: nabaskes

simple definition process for boundary conditions

*/

#include <vector>
#include <tuple>
#include <map>


class Boundary {
public:
  int r, c;
  std::map<std::tuple<int, int>, double> conditions;

  Boundary(int rows, int cols) {
    r = rows;
    c = cols;
  }

  void add_condition(int row, int col, double value) {
    conditions[std::make_tuple(row, col)] = value;
  }

  std::vector<std::tuple<int, int, double>> get_conditions() {
    std::vector<std::tuple<int, int, double>> results;
    results.reserve(conditions.size());
    for (auto it = conditions.begin(); it != conditions.end(); it++) {
      std::tuple<int, int> pair = it->first;
      double v = it->second;
      results.push_back(std::make_tuple(std::get<0>(pair),
					std::get<1>(pair),
					v));
    }
    return results;
  }

  void add_boundary(Boundary second) {
    for (auto it = second.conditions.begin(); it != second.conditions.end(); it++) {
      conditions[it->first] = it->second;
    }
  }


};

class BoundaryRow: public Boundary {
public:
  BoundaryRow(int rows, int cols, double value, double rownum): Boundary(rows, cols){

    for(int i=0; i < c; i++) {
      conditions[std::make_tuple(rownum, i)] = value;
    }
  }
};

class BoundaryColumn: public Boundary {
public:
  BoundaryColumn(int rows, int cols, double value, double colnum) : Boundary(rows, cols){

    for(int i=0; i<r; i++) {
      conditions[std::make_tuple(i, colnum)] = value;
    }
  }
};
