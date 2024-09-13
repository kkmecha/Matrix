#ifndef __INCLUDED_MATRIX_H__
#define __INCLUDED_MATRIX_H__

#include "mbed.h"
#include <vector>
#include <stdexcept>

class Matrix{
    public :
        Matrix();
        void matrixAdd(const vector<vector<float>>& A, const vector<vector<float>>& B, vector<vector<float>>& result);
        void matrixSub(const vector<vector<float>>& A, const vector<vector<float>>& B, vector<vector<float>>& result);
        void matrixMult(const vector<vector<float>>& A, const vector<vector<float>>& B, vector<vector<float>>& result);
        void scalarMult(const vector<vector<float>>& A, float scalar, vector<vector<float>>& result);
        void transpose(const vector<vector<float>>& A, vector<vector<float>>& result);
        void inverse(const vector<vector<float>>& A, vector<vector<float>>& result);
};
#endif 
