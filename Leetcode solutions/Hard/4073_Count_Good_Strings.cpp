static int MOD=1e9+7;
template<typename T,size_t N,size_t M>
class Matrix {
    array<array<T,M>,N> matrix{};
    public:
    Matrix() = default;
    Matrix(const array<array<T,M>,N>& matrix):matrix(matrix) {}
    array<T,M>& operator[](const size_t index) {
        return matrix[index];
    }
    const array<T,M>& operator[] (const size_t index) const {
        return matrix[index];
    }
    void makeIdentity() {
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                matrix[i][j]=i==j;
    }
    Matrix& operator*=(const Matrix<T,M,M> &rhs) {
        array<array<T,M>,N> result{};
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<rhs[0].size();j++)
                for(int k=0;k<matrix[0].size();k++)
                    result[i][j]=(result[i][j]+((matrix[i][k]*rhs[k][j])%MOD))%MOD;
        matrix.swap(result);
        return *this;
    }
    Matrix& operator^=(long long d) {
        Matrix<T,N,M> i;
        i.makeIdentity();
        while(d) {
            if(d&1)
                i*=*this;
            d>>=1;
            *this*=*this;
        }
        swap(i,*this);
        return *this;
    }
};
class Solution {
public:
    int countGoodStrings(long long n) {
        Matrix<long long,2,2> b({{{1,1},{1,0}}});
        b^=n-1;
        return (b[0][0]*2LL)%MOD;
    }
};