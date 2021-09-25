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

void fftshift(array2d_t &array) {
    /*
     * Shifts the zero-frequency component to the center
     * of the spectrum.
     */

    int Nx = int(array[0].size());
    int Ny = int(array.size());
    auto array_copy = array;

    // Reverse each row:
    for (int i = 0; i < Ny; ++i) {
        for (int j = 0; j < Nx; ++j) {
            if (j < Nx / 2) {
                array[i][j] = array_copy[i][Nx / 2 + j];
            } else if (j >= Nx / 2) {
                array[i][j] = array_copy[i][j - Nx / 2];
            }
        }
    }

    array_copy = array;

    // Reverse each column:
    for (int i = 0; i < Ny; ++i) {
        for (int j = 0; j < Nx; ++j) {
            if (j < Nx / 2) {
                array[j][i] = array_copy[Nx / 2 + j][i];
            } else if (j >= Nx / 2) {
                array[j][i] = array_copy[j - Nx / 2][i];
            }
        }
    }
}