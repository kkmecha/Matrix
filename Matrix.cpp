#include "mbed.h"
#include <vector>
#include <stdexcept>

using namespace std;

Matrix::Matrix();
// 行列の加算
Matrix::vector<vector<float>> matrixAdd(const vector<vector<float>>& A, const vector<vector<float>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    
    if (rows != B.size() || cols != B[0].size()) {
        printf("行列のサイズが一致しません。");
    }
    
    vector<vector<float>> result(rows, vector<float>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// 行列の減算
Matrix::vector<vector<float>> matrixSub(const vector<vector<float>>& A, const vector<vector<float>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    
    if (rows != B.size() || cols != B[0].size()) {
        printf("行列のサイズが一致しません。");
    }
    
    vector<vector<float>> result(rows, vector<float>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// 行列の乗算
Matrix::vector<vector<float>> matrixMult(const vector<vector<float>>& A, const vector<vector<float>>& B) {
    int rowA = A.size();
    int colA = A[0].size();
    int rowB = B.size();
    int colB = B[0].size();
    
    if (colA != rowB) {
        printf("行列のサイズが一致しません。");
    }
    
    vector<vector<float>> result(rowA, vector<float>(colB, 0.0));
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colB; ++j) {
            for (int k = 0; k < colA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// 行列とスカラーの乗算
Matrix::vector<vector<float>> scalarMult(const vector<vector<float>>& A, float scalar) {
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<float>> result(rows, vector<float>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] * scalar;
        }
    }
    return result;
}

// 行列の転置
Matrix::vector<vector<float>> transpose(const vector<vector<float>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<float>> transposed(cols, vector<float>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = A[i][j];
        }
    }
    return transposed;
}

// 行列の逆行列を計算する関数 (ガウス・ジョルダン法)
Matrix::vector<vector<float>> inverse(const vector<vector<float>>& A) {
    int n = A.size();
    vector<vector<float>> augmented(n, vector<float>(2 * n));

    // 拡張行列を作成
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = A[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    // ガウス・ジョルダン法
    for (int i = 0; i < n; ++i) {
        // 主対角線上の要素を1にするためのスケーリング
        float diag = augmented[i][i];
        if (diag == 0) {
            printf("行列は逆行列を持ちません（ゼロの主対角線要素）。");
        }
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= diag;
        }

        // 他の行の主対角線要素をゼロにする
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                float factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // 右半分が逆行列
    vector<vector<float>> inv(n, vector<float>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = augmented[i][j + n];
        }
    }

    return inv;
}
