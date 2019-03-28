#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

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
    std::string path = outpath + ".pgm";
    output.open(outpath.c_str());
    output << "P2\n";
    output << image.size() << ' ' << image[0].size() << "\n";
    output << "255 \n";

    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
	if (j != 0) {
	  output << " ";
	}
	output << std::to_string((int)std::round(image[i][j]));
      }
      output << "\n";
    }
    output.close();
  }
};
