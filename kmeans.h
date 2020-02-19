#ifndef __KMEANS_H__
#define __KMEANS_H__

template <typename S, typename T>
void keamns(const Matrix<S> &pts, Vec<u8> &labels, u8 &nclusters, Matrix<T> &clusters) {
  // check nclusters
  if (nclusters <= 0)
    throw Exception("kmeans must have nclusters > 0");

  // assign each pts to a random label  
  labels.init(pts.rows());
  for(u32 i = 0; i < labels.len(); i++) labels[i] = i % nclusters;

  bool change = false;
  u32 dim = pts.cols();
  clusters.init(nclusters, dim);
  do {
    // compute means of each cluster
    // re-assign each pt to nearest cluster, flag if any change
  } while (change);
}

#endif // __KMEANS_H__
