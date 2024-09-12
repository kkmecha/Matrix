#ifndef __INCLUDED_MATRIX_H__
#define __INCLUDED_MATRIX_H__

#include "mbed.h"
#include <vector>
#include <stdexcept>

class Matrix{
    public :
        vector<vector<float>> matrixAdd(const vector<vector<float>>& A, const vector<vector<float>>& B);
        vector<vector<float>> matrixSub(const vector<vector<float>>& A, const vector<vector<float>>& B);
        vector<vector<float>> matrixMult(const vector<vector<float>>& A, const vector<vector<float>>& B);
        vector<vector<float>> scalarMult(const vector<vector<float>>& A, float scalar);
        vector<vector<float>> transpose(const vector<vector<float>>& A);
        vector<vector<float>> inverse(const vector<vector<float>>& A);
};
#endif 
