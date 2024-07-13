#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0);
const TGAColor green = TGAColor(0, 255, 0);
const TGAColor blue = TGAColor(0, 0, 255);
int W, H;

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
    bool swapped = 0;
    int distX = std::abs(x2 - x1);
    int distY = std::abs(y2 - y1);
    // if line is too steep, we might miss portions of y
    // so just transpose the image and de-transpose it afterwards
    if (distX < distY) {
        swapped = 1;
        swap(x1, y1);
        swap(x2, y2);
    }
    // make sure that we can iterate from smaller x to bigger x
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    for (int x = x1; x <= std::min(W - 1, x2); ++x) {
        float t = (x - x1) / (float) (x2 - x1);
        // can think of t as % of x covered
        int y = y1 * (1. - t) + y2 * t; 
        if (y >= H) continue;
        // now have to cover similar % for y
        int X = (swapped ? y : x);
        int Y = (swapped ? x : y);
        img.set(X, Y, col);
    }
}

int main() {
    W = 100, H = 100;
    TGAImage image(W, H, TGAImage::RGB);
    line(image, 13, 20, 80, 40, red);
    line(image, 20, 13, 40, 80, green);
    // line(image, 80, 40, 13, 20, blue);
    image.flip_vertically();
    image.write_tga_file("output.tga");
    return 0;
}