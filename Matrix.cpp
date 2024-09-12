#include "mbed.h"
#include <vector>
#include <stdexcept>

using namespace std;

// 行列の加算
vector<vector<double>> matrixAdd(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    
    if (rows != B.size() || cols != B[0].size()) {
        throw invalid_argument("行列のサイズが一致しません。");
    }
    
    vector<vector<double>> result(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// 行列の減算
vector<vector<double>> matrixSubtract(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    
    if (rows != B.size() || cols != B[0].size()) {
        throw invalid_argument("行列のサイズが一致しません。");
    }
    
    vector<vector<double>> result(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// 行列の乗算
vector<vector<double>> matrixMultiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rowA = A.size();
    int colA = A[0].size();
    int rowB = B.size();
    int colB = B[0].size();
    
    if (colA != rowB) {
        throw invalid_argument("行列のサイズが一致しません。");
    }
    
    vector<vector<double>> result(rowA, vector<double>(colB, 0.0));
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
vector<vector<double>> scalarMultiply(const vector<vector<double>>& A, double scalar) {
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<double>> result(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] * scalar;
        }
    }
    return result;
}

// 行列の転置
vector<vector<double>> transpose(const vector<vector<double>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<double>> transposed(cols, vector<double>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = A[i][j];
        }
    }
    return transposed;
}

// 行列の逆行列を計算する関数 (ガウス・ジョルダン法)
vector<vector<double>> inverse(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n));

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
        double diag = augmented[i][i];
        if (diag == 0) {
            throw runtime_error("行列は逆行列を持ちません（ゼロの主対角線要素）。");
        }
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= diag;
        }

        // 他の行の主対角線要素をゼロにする
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // 右半分が逆行列
    vector<vector<double>> inv(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = augmented[i][j + n];
        }
    }

    return inv;
}

// // メイン関数の例
// int main() {
//     // 例として使用する行列
//     vector<vector<double>> A = {
//         {1, 2},
//         {3, 4}
//     };
//     vector<vector<double>> B = {
//         {5, 6},
//         {7, 8}
//     };
//     double scalar = 2.0;

//     try {
//         // 行列加算
//         vector<vector<double>> sum = matrixAdd(A, B);
//         cout << "行列A + B:\n";
//         for (const auto& row : sum) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//         // 行列減算
//         vector<vector<double>> diff = matrixSubtract(A, B);
//         cout << "行列A - B:\n";
//         for (const auto& row : diff) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//         // 行列乗算
//         vector<vector<double>> product = matrixMultiply(A, B);
//         cout << "行列A * B:\n";
//         for (const auto& row : product) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//         // 行列とスカラーの乗算
//         vector<vector<double>> scalarProd = scalarMultiply(A, scalar);
//         cout << "行列A * スカラー:\n";
//         for (const auto& row : scalarProd) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//         // 行列転置
//         vector<vector<double>> transposed = transpose(A);
//         cout << "行列Aの転置:\n";
//         for (const auto& row : transposed) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//         // 行列の逆行列
//         vector<vector<double>> inv = inverse(A);
//         cout << "行列Aの逆行列:\n";
//         for (const auto& row : inv) {
//             for (double val : row) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//     } catch (const exception& e) {
//         cerr << e.what() << endl;
//     }

//     return 0;
// }
