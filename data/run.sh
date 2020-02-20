#!/bin/bash -x

for i in kmeans
do
    ../src/cluster cluster0.pts $i 3
    ../src/cluster cluster1.pts $i 7
    ../src/cluster cluster2.pts $i 2
    ../src/cluster cluster3.pts $i 2
    ../src/cluster cluster4.pts $i 3
    ../src/cluster cluster5.pts $i 3
    ../src/cluster cluster6.pts $i 2
    ../src/cluster ./us.ppm $i 10
done

