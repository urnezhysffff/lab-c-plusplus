#include <iostream>
#include <fstream>

using namespace std;

class matrix {
private:
    int n;
    int m;
    int** array;
    void Create()
    {
        array = new int*[n];
        for (int i = 0; i < n; i++) {
            array[i] = new int[m];
            for (int j = 0; j < m; j++)
                array[i][j] = 0;
        }
    }

public:
    friend ostream& operator<<(ostream& str, const matrix fir);
    friend istream& operator>>(istream& str, const matrix fir);
    matrix(int a, int b)
    {
        this->n = a;
        this->m = b;
        Create();
    };
    ~matrix()
    {

        for (int i = 0; i < n; i++) {
            delete (array[i]);
        }
        delete (array);
    }
    void get()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> array[i][j];
    }
    matrix operator=(matrix fir)
    {
        matrix result(fir.n, fir.m);
        for (int i = 0; i < fir.n; i++)
            for (int j = 0; j < fir.m; j++)
                result.array[i][j] = fir.array[i][j];

        for (int i = 0; i < this->n; i++) {
            delete (this->array[i]);
        }
        delete (this->array);
        this->n = fir.n;
        this->m = fir.m;
        this->array = result.array;
        return *this;
    }
    matrix& operator*=(int a)
    {

        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->array[i][j] = this->array[i][j] * a;
        return *this;
    }
    matrix& operator-=(int a)
    {

        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->array[i][j] = this->array[i][j] - a;
        return *this;
    }
    matrix& operator+=(int a)
    {

        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->array[i][j] = this->array[i][j] + a;
        return *this;
    }
    matrix operator+(matrix fir)
    {
        matrix result(fir.n, fir.m);
        if (this->n == fir.n && this->m == fir.m) {
            for (int i = 0; i < fir.n; i++)
                for (int j = 0; j < fir.m; j++)
                    result.array[i][j] = fir.array[i][j] + this->array[i][j];
        }
        else
            throw;
    }

    matrix operator-(matrix fir)
    {
        matrix result(fir.n, fir.m);
        if (this->n == fir.n && this->m == fir.m) {
            for (int i = 0; i < fir.n; i++)
                for (int j = 0; j < fir.m; j++)
                    result.array[i][j] = fir.array[i][j] - this->array[i][j];
        }
        throw;
    }

    matrix operator+(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.array[i][j] = this->array[i][j] + a;
        return result;
    }

    matrix operator-(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.array[i][j] = this->array[i][j] - a;
        return result;
    }

    matrix operator*(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.array[i][j] = this->array[i][j] * a;
    }

    int operator()(int a, int b)
    {
        if (a <= this->n && b <= this->m)
            return this->array[a][b];
        else
            throw;
    }

    matrix trans()
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.array[i][j] = this->array[j][i];
        return result;
    }

    matrix atod(matrix fir)
    {
        matrix result(this->n, fir.m);
        if (this->m == fir.n) {
            for (int i = 0; i < this->n; i++)
                for (int j = 0; j < fir.m; j++)
                    for (int k = 0; k < fir.n; k++) {
                        result.array[i][j] += this->array[i][k] * fir.array[k][j];
                    }
            return result;
        }
        else
            throw;
    }
};

istream& operator>>(istream& is, matrix fir)
{
    for (int i = 0; i < fir.n; i++)
        for (int j = 0; j < fir.n; j++)
            is >> fir.array[i][j];
}

ostream& operator<<(ostream& str, matrix fir)
{
    for (int i = 0; i < fir.n; i++) {
        for (int j = 0; j < fir.m; j++) {
            str << fir.array[i][j] << " ";
        }
    }
    str << endl;
}
int main()
{
    return 0;
}
