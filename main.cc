#include "cluster.h"

int main(int argc, char **argv) {
  Vec<float> v;
  Matrix<float> m;
  Image<u8> im;

  // proc args
  // input image
  // create vectors as Matrix
  // cluster vectors creating Matrix and labels using algorithms name from args
  // render vectors into new image
  // write output color image with clusters

  u8 nclusters;
  Vec<u8> labels;
  Matrix<float> pts;
  Matrix<float> clusters;

  if (cluster("kmeans", pts, labels, nclusters, clusters)) {
    throw Exception("kmeans cluster failed");
  }

  return 0;
}
