#include<fstream>

using namespace std;

#include "cmap.h"
#include "cluster.h"

void readPts(const string fname, u32 &rows, u32 &cols, Matrix<float> &pts) {
  std::ifstream ifile;
  u32 r, c, count = 0;

  ifile.open(fname.c_str());
  if (!ifile)
    throw Exception("could not read from file");

  // count file size
  ifile >> rows >> cols;
  while(!ifile.eof()) {
    ifile >> r >> c;
    count++;
  }
  ifile.close();

  // init and read pts
  pts.init(count, 2);
  ifile.open(fname.c_str());

  count = 0;
  if (!ifile)
    throw Exception("could not read from file");
  ifile >> rows >> cols;
  while(!ifile.eof()) {
    ifile >> r >> c;
    pts.set(count, 0, (float)r);
    pts.set(count, 1, (float)c);
    count++;
  }
  ifile.close();
}

int main(int argc, char **argv) {

  u8 nclusters;
  Image<RGB_t> imRGB;
  Image<u8> imGray;
  Vec<u8> labels;
  Matrix<float> pts;
  Matrix<float> clusters;
  string fname, algo, ext;
  u32 rows, cols;

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
    rows = imRGB.height();
    cols = imRGB.width();
    pts = imRGB.createpts();
  } else if (ext == "pgm") {
    imGray.readFromFile(argv[1]);
    rows = imGray.height();
    cols = imGray.width();
    pts = imGray.createpts();
  } else if (ext == "pts") {
    readPts(fname, rows, cols, pts);
  }
  else{
    throw Exception("unknown file type, only accepts pgm and ppm");
  }

  // cluster vectors creating Matrix and labels using algorithms name from args
  if (algo == "kmeans") {
    cluster("kmeans", pts, labels, nclusters, clusters);
  } else {
    throw Exception("unknown clustering algo");
  }

  // write out colorized label image
  Image<RGB_t> labelImage(rows, cols);
  if (ext == "pts") {
    for(u32 i = 0; i < labels.len(); i++) {
      u32 r = pts.get(i, 0);
      u32 c = pts.get(i, 1);
      u32 l = labels[i];
      labelImage.set(r, c, jetMap[l * int(255/nclusters)]);
    }
  } else {
    for(u32 i = 0; i < labels.len(); i++) {
      u32 l = labels[i];
      labelImage.set(i, jetMap[l * int(255/nclusters)]);
    }
  }
  labelImage.writeToFile(fname + "_out.ppm");

  return 0;
}
