#include "cluster.h"

int main(int argc, char **argv) {

  u8 nclusters;
  Image<RGB_t> imRGB;
  Image<u8> imGray;
  Vec<u8> labels;
  Matrix<float> pts;
  Matrix<float> clusters;
  string fname, algo, ext;

  fname = argv[1];
  algo = argv[2];

  ext = fname.substr(fname.find_last_of(".") + 1);
  if (ext == "ppm") {
    imRGB.readFromFile(argv[1]);
  }
  else if (ext == "pgm") {
    imGray.readFromFile(argv[1]);
  }
  else {
    throw Exception("unknown file type, only accepts pgm and ppm");
  }

  // create pts from image

  // cluster vectors creating Matrix and labels using algorithms name from args
  if (cluster("kmeans", pts, labels, nclusters, clusters)) {
    throw Exception("kmeans cluster failed");
  }

  // render vectors into new image
  // write output color image with clusters

  return 0;
}
