#pragma once
#include "extern/fastnoise/FastNoise.h"

namespace util {

void noise_image(Image<float> &image, FastNoise *fastnoise, const glm::vec2 &sample_freq, float amplitude, uint8_t channel);

};
