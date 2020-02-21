#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include<string>
#include<vector>

#include"Image.h"
#include"Matrix.h"
#include"Vec.h"
#include"types.h"

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
void cluster(const Params_t &params, const Matrix<S> &pts, Vec<u8> &labels, Matrix<T> &clusters);

/* algorithms implemented one per file
#include "em.h"
#include "fuzzy.h"
#include "meanshift.h"
#include "ncuts.h"
#include "spectral.h" */
#include "dbscan.h"
#include "kmeans.h"

// one point per row of Matrix pts, supports up to 255 clusters
template <typename S = float, typename T = float>
void cluster(Params_t &params, const Matrix<S> &pts, Vec<u8> &labels, Matrix<T> &clusters) {
  // outer switch for algorithm type
  if (params["algo"] == "kmeans") {

    // check params for kmeans algo
    if (params.find("nclusters") == params.end())
      throw(Exception("kmeans requires --nclusters <int [2 - 255]>"));

    kmeans(pts, std::stoi(params["nclusters"]), labels, clusters);
  }
  else if (params["algo"] == "dbscan") {

    // check params for dbscan algo
    if (params.find("radius") == params.end())
      throw(Exception("dbscan requires --radius <float>"));

    dbscan(pts, std::stof(params["radius"]), labels, clusters);
  }
  else {
    throw(Exception("unknown clustering algorithm"));
  }
}

#endif // __CLUSTER_H__
