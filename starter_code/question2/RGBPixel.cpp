#include <exception>
#include <stdexcept>
#include "RGBPixel.h"

// Construct an RGBPixel with all channels initialized to 0
RGBPixel::RGBPixel() : r(0), g(0), b(0) {
    // constructor implementation
}

// Construct an RGBPixel with all channels initialized to r, g, b
RGBPixel::RGBPixel(unsigned int r, unsigned int g, unsigned int b)
    : r(r), g(g), b(b) {
    // constructor implementation
}

// Destructor
RGBPixel::~RGBPixel() {
    // destructor implementation
}

// Return the brightness of a pixel
// brightness for RGBPixel = (r + g + b) / 3
unsigned int RGBPixel::getBrightness() const {
    return (r + g + b) / 3;
}

// Should return a reference to the corresponding channel value of the pixel
// 'r' <- red channel
// 'g' <- green channel
// 'b' <- blue channel
unsigned int& RGBPixel::operator[](const char channel) {
    if (channel == 'r') {
        return r;
    } else if (channel == 'g') {
        return g;
    } else if (channel == 'b') {
        return b;
    }
    throw std::invalid_argument("Invalid channel");
}
