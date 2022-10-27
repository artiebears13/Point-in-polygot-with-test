#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool is_inside_poly(double &x, double &y, std::vector<double> &xarr, std::vector<double> &yarr) {
    int count = 0;
    int size = xarr.size();
    for (int i = 0; i <= size - 1; ++i) {
        if (i == size - 1) {
            yarr.push_back(yarr[0]);
            xarr.push_back(xarr[0]);
        }

        if (y < yarr[i] != y < yarr[i + 1] &&
            x == (xarr[i + 1] - xarr[i]) * (y - yarr[i]) / (yarr[i + 1] - yarr[i]) + xarr[i]) {
            std::cout << "The point (x, y) is on the edge of the poly 2" << std::endl;
            exit(0);
        }

        if (y == yarr[i] || y == yarr[i + 1])
        {
            if (x <= xarr[i + 1] && x >= xarr[i] || x >= xarr[i + 1] && x <= xarr[i]) {
                std::cout << "The point (x, y) is on the edge of the poly 2" << std::endl;
                exit(0);
            }
        }

        if (y < yarr[i] != y < yarr[i + 1] &&
            x < (xarr[i + 1] - xarr[i]) * (y - yarr[i]) / (yarr[i + 1] - yarr[i]) + xarr[i]) {
            count += 1;
        }

    }
    return count % 2 != 0;
}


int main(int argc, char **argv) {
    std::ifstream f(argv[1]);

    double x0 = std::atof(argv[2]);
    double y0 = std::atof(argv[3]);
    double x, y;
    std::vector<double> xarr, yarr;

    while (!f.eof()) {
        if (f.good()) {
            f >> x >> y;
            xarr.push_back(x);
            yarr.push_back(y);
        }
        else{
            std::cout << "Error" << std::endl;
        }
    }

    if (is_inside_poly(x0, y0, xarr, yarr))
        std::cout << "The point(x, y) is inside of the polygon" << std::endl;
    else std::cout << "The point(x, y) is outside of the polygon" << std::endl;
}

