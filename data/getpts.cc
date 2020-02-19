#include<iostream>

using namespace std;

#include "Image.h"

int main(int argc, char **argv)
{
    if (argc != 4) {
        cerr << argv[0] << " <image.pgm> <thresh> <out.pts>" << endl;
        return -1;
    }

    Image<u8> im;
    ofstream ofile;

    im.readFromFile(argv[1]);
    u32 thresh = atoi(argv[2]);
    ofile.open(argv[3]);

    ofile << im.height() << " " << im.width() << endl;
    for(int i = 0; i < im.height(); i++) {
        for(int j = 0; j < im.width(); j++) {
            if (im.get(i * im.width() + j) < thresh) ofile << i << " " << j << endl;
        }
    }
    ofile.close();

    return 0;
}
