#ifndef COSC1076_A3_IMAGE_H
#define COSC1076_A3_IMAGE_H

#include <vector>

#include "Pixel.h"
#include "RGBPixel.h"
#include "GreyscalePixel.h"

template <typename T>
class Image {
public:
    Image(int nRows, int nCols);
    ~Image();
    T get(int row, int col) const;
    void set(int row, int col, const T& pix);

private:
    std::vector<std::vector<T>> img;
};

#include "Image.cpp"  // Include the implementation file

#endif //COSC1076_A3_IMAGE_H