#include "GreyscalePixel.h"
#include <exception>
#include <stdexcept>

// Construct a GreyscalePixel with intensity channels initialized to 0
GreyscalePixel::GreyscalePixel() : intensity(0) {
    // constructor implementation
}

// Construct a GreyscalePixel with intensity channels initialized to intensity
GreyscalePixel::GreyscalePixel(unsigned int intensity) : intensity(intensity) {
    // constructor implementation
}

// Destructor
GreyscalePixel::~GreyscalePixel() {
    // destructor implementation
}

// Return the brightness of a pixel
// brightness for GreyscalePixel = intensity
unsigned int GreyscalePixel::getBrightness() const {
    return intensity;
}

// Should return a reference to the corresponding channel value of the pixel
// 'i' <- intensity
unsigned int& GreyscalePixel::operator[](const char channel) {
    if (channel == 'i') {
        return intensity;
    }
    throw std::invalid_argument("Invalid channel");
}
