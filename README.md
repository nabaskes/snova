Generate visuals of 2D dynamic systems in motion

To visualize your own PDE, create a class which extends fin_diffs/simulator.cpp

```
#include "../simulator.cpp"

class HeatSimulator : public Simulator {

```

```
HeatSimulator(int rows,
              int cols,
	      std::vector<std::tuple<int,int,double>> boundary_conds,
	      std::vector<std::vector<double>> init_conds) {

```

Then, you must define the method iterate_forward_fin_diff()

```
  double iterate_forward_fin_diff(std::vector<std::vector<double>>* universe,
				  int i,
				  int j) {
    double uu = .25 * ((*universe)[i+1][j] + (*universe)[i-1][j]+(*universe)[i][j+1]+(*universe)[i][j-1]);
    return uu + alpha * (uu - (*universe)[i][j]);
  }
```

This function should return a single value of u[i][j], calculated by using a finite differences approximation to discretize the PDE.

Then, generating visualizations are simple.  Instantiate your class with the number of rows and columns, with a 2d vector containing initial conditions, and with a vector of tri-tuples containing Dirichlet boundary conditions.

```
HeatSimulator sim (100, 100, boundary_conds, init_conds);
```

then, run the .calculate() method with the duration of measure, desired path to output, and a vector of times to print out at

```
sim.calculate(10000, "path_to_my_output_", print_times);
```