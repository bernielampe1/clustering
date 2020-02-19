#include "cluster.h"

using namespace std;

int main(int argc, char **argv) {

  u8 nclusters;
  Image<RGB_t> imRGB;
  Image<u8> imGray;
  Vec<u8> labels;
  Matrix<float> pts;
  Matrix<float> clusters;
  string fname, algo, ext;

  // process args
  if (argc == 3) {
    fname = argv[1];
    algo = argv[2];
  } else if (argc == 4) {
    fname = argv[1];
    algo = argv[2];
    nclusters = atoi(argv[3]);
  } else {
    cerr << argv[0] << " <fname> <algo> [nclusters]>" << endl;
    return -1;
  }

  // read image and create points
  ext = fname.substr(fname.find_last_of(".") + 1);
  if (ext == "ppm") {
    imRGB.readFromFile(argv[1]);
    pts = imRGB.createPts();
  } else if (ext == "pgm") {
    imGray.readFromFile(argv[1]);
    pts = imGray.createPts();
  } else {
    throw Exception("unknown file type, only accepts pgm and ppm");
  }

  // cluster vectors creating Matrix and labels using algorithms name from args
  if (algo == "kmeans") {
    if (cluster("kmeans", pts, labels, nclusters, clusters)) {
      throw Exception("kmeans cluster failed");
    }
  } else {
    throw Exception("unknown clustering algo");
  }

  // render vectors into new image

  // write output color image with clusters

  return 0;
}
