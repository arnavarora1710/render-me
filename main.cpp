#include "tgaimage.h"

int main() {
    TGAImage image(100, 100, TGAImage::RGB);
    image.flip_vertically();
    image.write_tga_file("output.tga");
    return 0;
}