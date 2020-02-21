#include<fstream>

using namespace std;

#include "cluster.h"
#include "types.h"
#include "utils.h"

int main(int argc, char **argv)
{
  Image<u8> imGray;
  Image<RGB_t> imRGB;

  Matrix<float> pts;
  Matrix<float> clusters;

  Vec<u8> labels;
  Params_t params;

  string ifname, ofname, ext;
  u32 rows, cols;

  // process the cmdline arguments
  params = parse_args(argc, argv);

  // get input and output fname and ext
  if (params.find("i") == params.end())
    throw Exception("must specify --i <in fname [.pgm,.ppm,.pts]>");

  if (params.find("o") == params.end())
    throw Exception("must specify --o <out fname [.ppm]>");

  ifname = params["i"];
  ofname = params["o"];
  ext = ifname.substr(ifname.find_last_of(".") + 1);

  // read image and create points
  if (ext == "ppm") {
    imRGB.readFromFile(ifname);
    rows = imRGB.height();
    cols = imRGB.width();
    pts = imRGB.createpts();

  } else if (ext == "pgm") {
    imGray.readFromFile(ifname);
    rows = imGray.height();
    cols = imGray.width();
    pts = imGray.createpts();

  } else if (ext == "pts") {
    readPts(ifname, rows, cols, pts);
  }
  else{
    throw Exception("unknown file type, only accepts pgm and ppm");
  }

  // cluster vectors creating Matrix and labels using algorithms name from args
  cluster(params, pts, labels, clusters);

  // write out colorized label image
  writeLabelImage(ofname, ext, rows, cols, clusters.rows(), labels, pts);

  return 0;
}
