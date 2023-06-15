#include <exception>
#include <stdexcept>
#include "Image.h"

template <typename T>
Image<T>::Image(int nRows, int nCols) {
    img.resize(nRows, std::vector<T>(nCols));
}

template <typename T>
Image<T>::~Image() {
    // Destructor implementation
}

template <typename T>
T Image<T>::get(int row, int col) const {
    return img[row][col];
}

template <typename T>
void Image<T>::set(int row, int col, const T& pix) {
    img[row][col] = pix;
}
