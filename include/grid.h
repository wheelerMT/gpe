//
// Created by mattw on 25/09/2021.
//

#ifndef INC_2D_GPESOLVER_GRID_H
#define INC_2D_GPESOLVER_GRID_H

#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>

using array2d_t = std::vector<std::vector<double>>;

std::tuple<array2d_t, array2d_t> meshgrid(std::vector<double> &x, std::vector<double> &y);

void fftshift(array2d_t &array);

#endif //INC_2D_GPESOLVER_GRID_H
