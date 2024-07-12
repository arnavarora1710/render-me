#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255);

void swap(int& x, int& y) {
    x ^= y;
    // x = x ^ y
    y ^= x;
    // y = x ^ y ^ y = x
    x ^= y;
    // x = x ^ y ^ x = y
}

void line(TGAImage& img, int x1, int y1, int x2, int y2, TGAColor col) {
    // Slope form: y = mx + c
    // Standard form: Ax + By + C = 0
    // Remember that you have to color in pixels
    // Not like drawing on paper
    // (can't color fractional coordinates)
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    float m = (y2 - y1) / (float) (x2 - x1);
    for (int x = x1; x <= x2; ++x) {
        int c = y1 - m * x1;
        int y = m * x + c; 
        img.set(x, y, col);
    }
}

int main() {
    TGAImage image(100, 100, TGAImage::RGB);
    line(image, 25, 25, 50, 50, white);
    image.flip_vertically();
    image.write_tga_file("output.tga");
    return 0;
}