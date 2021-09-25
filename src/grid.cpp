//
// Created by mattw on 25/09/2021.
//

#include "grid.h"

std::tuple<array2d_t, array2d_t> meshgrid(std::vector<double> &x, std::vector<double> &y) {
    // Returns meshgrid X & Y from 1D vectors x & y

    array2d_t X(x.size(), std::vector<double>(y.size()));
    array2d_t Y(x.size(), std::vector<double>(y.size()));

    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < x.size(); ++j) {
            X[i][j] = x[j];
            Y[i][j] = y[i];
        }
    }

    return {X, Y};
}
