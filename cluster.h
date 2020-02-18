#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include <string>
#include <vector>

#include "Image.h"
#include "Matrix.h"
#include "Vec.h"
#include "types.h"

/*
    - Clustering interface supporting multiple algorithms and up to 255
   clusters.
    - Inputs:
        string algo   = "kmeans", "dbscan", "em", "fuzzycmeans", "meanshift",
                        "spectral", "normalizedcuts"
        Matrix<S> pts = the vectors to cluster together, sparse or dense matrix
                        one point per row

    - Outputs:
        u8 labels    = labels 0 to 255, size is number of rows of pts
        u8 nclusters = number of clusters 0 to 255
        Matrix<T>    = vectors representing clusters, one per row same dimension
   as input vectors
*/
template <typename S, typename T>
bool cluster(const std::string &algo, const Matrix<S> &pts, u8 &labels,
             u8 &nclusters, Matrix<T> &clusters);

/* algorithms implemented one per file
#include "dbscan.h"
#include "em.h"
#include "fuzzy.h"
#include "kmeans.h"
#include "meanshift.h"
#include "ncuts.h"
#include "spectral.h" */

// one point per row of Matrix pts, supports up to 255 clusters
template <typename S = float, typename T = float>
bool cluster(const std::string &algo, const Matrix<S> &pts, u8 &labels,
             u8 &nclusters, Matrix<T> &clusters) {
  if (algo == "kmeans") {
    return keamns(pts, labels, nclusters, clusters);
  }

  return false;
}

#endif // __CLUSTER_H__
