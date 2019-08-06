/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/
#include "../include/kmeans.hpp"

int main(int argc, const char **argv)
{
    using namespace AMWPHI001;
    Kmean::vecVec table;
    std::vector<int> X = {2, 2, 8, 5, 7, 6, 1, 4};

    std::vector<int> Y = {10, 5, 4, 8, 5, 4, 2, 9};

    for (size_t i = 0; i < 2; i++)
    {
        table.push_back(X);
        table.push_back(Y);
    }

    return 0;
}
