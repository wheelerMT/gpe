#include <iostream>
#include "constants.h"
#include "grid.h"
#include "fftw3.h"

int main() {
    // -------------- Controlled variables -------------- //
    // Grid parameters //
    const int Nx = 256, Ny = 256;
    const int Mx = Nx / 2, My = Ny / 2;
    const double dx = 1., dy = 1.;  // Grid spacing
    const double dkx = PI / (Mx * dx), dky = PI / (My * dy);  // k-space spacing
    std::vector<double> x(Nx), y(Ny);  // 1D spatial grids
    std::vector<double> kx(Nx), ky(Ny);  // 1D k-space grids

    // Generate 1D spatial arrays:
    for (int i = 0; i < Nx; ++i) { x[i] = (i - Mx) * dx; }
    for (int i = 0; i < Ny; ++i) { y[i] = (i - My) * dy; }
    for (int i = 0; i < Nx; ++i) { kx[i] = (i - Mx) * dkx; }
    for (int i = 0; i < Ny; ++i) { ky[i] = (i - My) * dky; }

    // Generate 2D meshgrids
    auto [X, Y] = meshgrid(x, y);
    auto [Kx, Ky] = meshgrid(kx, ky);

    // Shift k-space meshgrids
    fftshift(Kx);
    fftshift(Ky);

    // Generate wavefunction and FFT plans
    // * Need to generate the wavefunction arrays on the heap
    fftw_complex *psi;
    fftw_complex *psi_k;

    return 0;
}
