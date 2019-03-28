#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class ImageGenerator {
  int r, c;

public:
  ImageGenerator(int rows, int cols) {
    r = rows;
    c = cols;
  }

  void generate_image(std::string outpath,
		      std::vector<std::vector<double>> image) {

    std::ofstream output;
    output.open(outpath.c_str());

    std::cout << "P2\n";
    std::cout << image.size() << ' ' << image[0].size() << "\n";
    return;

    output << "P2\n";
    output << image.size() << ' ' << image[0].size() << "\n";

  }
};
