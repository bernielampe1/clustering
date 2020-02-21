#!/bin/bash -x

for i in kmeans
do
    ../src/cluster --i cluster0.pts --algo $i --nclusters 3 --o cluster0_${i}.ppm
    ../src/cluster --i cluster1.pts --algo $i --nclusters 7 --o cluster1_${i}.ppm
    ../src/cluster --i cluster2.pts --algo $i --nclusters 2 --o cluster2_${i}.ppm
    ../src/cluster --i cluster3.pts --algo $i --nclusters 2 --o cluster3_${i}.ppm
    ../src/cluster --i cluster4.pts --algo $i --nclusters 3 --o cluster4_${i}.ppm
    ../src/cluster --i cluster5.pts --algo $i --nclusters 3 --o cluster5_${i}.ppm
    ../src/cluster --i cluster6.pts --algo $i --nclusters 2 --o cluster6_${i}.ppm
#    ../src/cluster --i us.ppm --algo $i --nclusters 10 --o us_out.pgm
done

