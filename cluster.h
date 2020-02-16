#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include<string>
#include<vector>

using namespace std;

#include "Matrix.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      u64;

/*
    - Clustering interface supporting multiple algorithms and up to 255 clusters.
    - Inputs:
        string algo   = "kmeans", "dbscan", "em", "fuzzycmeans", "meanshift",
                        "spectral", "normalizedcuts"
        Matrix<S> pts = the vectors to cluster together, sparse or dense matrix
                        one point per row

    - Outputs:
        u8 labels    = labels 0 to 255, size is number of rows of pts
        u8 nclusters = number of clusters 0 to 255
        Matrix<T>    = vectors representing clusters, one per row same dimension as
                       input vectors
*/
template< typename S, typename T >
bool cluster(
    const string &algo,
    const Matrix<S> &pts,
    u8 &labels,
    u8 &nclusters,
    Matrix<T> &clusters
);

/* - algorithm vector for used in cluster.cc invocation */
typedef bool (*invoke)(const string&, const Matrix<S>&, u8&, Matrix<T>&) InvokePrototype;

struct CAlgorithm {
    CAlgorithm(string &n, InvokePrototype f): name(n), invoke(f);

    string name;
    InvokePrototype invoke;
};

/* algorithms implemented one per file */
#include "ncuts.h"
#include "dbscan.h"
#include "em.h"
#include "fuzzy.h"
#include "kmeans.h"
#include "meanshift.h"
#include "spectral.h"

static const vector<struct ClusteringAlgo> clusterAlgoritms({
    CAlgorithm("kmenas", kmeans);
    CAlgorithm("dbscan", dbscane);
    CAlgorithm("em", expectationmaximize);
    CAlgorithm("fuzzzycmeans", fuzzzycmeans);
    CAlgorithm("meanshift", meanshift);
    CAlgorithm("spectral", spectral);
});

// one point per row of Matrix pts, supports up to 255 clusters
template< typename S = float, typename T = float >
bool cluster(const string &algo, const Matrix<S> &pts, u8 &labels, u8 &nclusters, Matrix<T> &clusters)
{
    for(auto it = clusterAlgorithms; it != clusterAlgorithms.end; it++) {
        if (it->name == algo) {
            return it->invoke(pts, labels, nclusters, clusters);
        }
    }

    return false;
}

#endif // __CLUSTER_H__
