#ifndef __INCLUDED_MATRIX_H__
#define __INCLUDED_MATRIX_H__

#include "mbed.h"
#include <vector>
#include <stdexcept>

class Matrix{
    public :
        vector<vector<double>> matrixAdd(const vector<vector<double>>& A, const vector<vector<double>>& B);
        vector<vector<double>> matrixSub(const vector<vector<double>>& A, const vector<vector<double>>& B);
        vector<vector<double>> matrixMult(const vector<vector<double>>& A, const vector<vector<double>>& B);
        vector<vector<double>> scalarMult(const vector<vector<double>>& A, double scalar);
        vector<vector<double>> transpose(const vector<vector<double>>& A);
        vector<vector<double>> inverse(const vector<vector<double>>& A);
};
#endif 
