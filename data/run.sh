#!/bin/bash -x

for i in kmeans
do
    ../cluster cluster0.pts $i 3
    ../cluster cluster1.pts $i 7
    ../cluster cluster2.pts $i 2
    ../cluster cluster3.pts $i 2
    ../cluster cluster4.pts $i 3
    ../cluster cluster5.pts $i 3
    ../cluster ./us.ppm $i 10
done

