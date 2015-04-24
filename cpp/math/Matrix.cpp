//TODO test it
/**
*** Matrix implementation with multiplication and exponentiation
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
typedef T int;
struct Matrix {
    int r, c;
    vector <vector <T> > m;

    Matrix() {
        r = 0;
        c = 0;
        fill();
    }

    Matrix(int r, int c) : r(r), c(c) {
        fill();
    }

    void fill() {
        vector<T> ret(c, 0);
        m = vector< vector<T> > (r, ret);
    }

    vector<T>& operator [](int i) {
        return m[i];
    }

    Matrix operator *(Matrix &mat) {
        Metrix ret = Matrix(r, mat.c);
        for (int j = 0; j < mat.c; j++) {
            for (int z = 0; z < c; z++) {
                if (mat.m[z][j] == 0) continue;
                for (int i = 0; i < r; i++) {
                    ret.m[i][j] = (ret.m[i][j] + m[i][z]*mat.m[z][j]);
                }
            }
        }
        return ret;
    }

    static Matrix identity(int rows, int cols) {
        Matrix iden(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                iden[i][j] = (i == j);
        return iden;
    }
};

Matrix exp_m(Matrix mat, int e) {
    if (e == 0) return Matrix::identity(mat.r, mat.c);
    if (e&1) return mat * exp_m(mat, e-1);
    Matrix half = exp_m(mat, e/2);
    return half*half;
}
