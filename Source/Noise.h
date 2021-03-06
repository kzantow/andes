/*
    Andes - synthesiser plugin based on Perlin noise
    Copyright (C) 2017  Artem Popov <art@artfwo.net>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <random>

class Noise
{
public:
    Noise();
    ~Noise();

    float gen (float x, float y, float z, int octaves, float persistence);

    uint32_t getSeed();
    void setSeed (uint32_t seed);

private:
    float gradients_00[65536];
    float gradients_01[65536];
    float gradients_10[65536];
    float gradients_11[65536];

    std::mt19937 random;
    uint32_t seed_;

    float gen1 (float x, float y, float z);
};
