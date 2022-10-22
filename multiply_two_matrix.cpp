#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, o, p;
    cout << "Enter the number of rows of matrix A: ";
    cin >> n;
    cout << "Enter the number of columns of metrix A: ";
    cin >> m;
    cout << "Enter the number of rows of matrix B: ";
    cin >> o;
    cout << "Enter the number of columns of matrix B: ";
    cin >> p;
    int a[n][m];
    int b[o][p];
    if (m == o)
    {
        cout << "Enter the elements of matrix A" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "Enter the elements of matrix B" << endl;
        for (int i = 0; i < o; i++)
        {
            for (int j = 0; j < p; j++)
            {
                cin >> b[i][j];
            }
        }
        int ab[n][p];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                int sum = 0;
                for (int k = 0; k < m; k++)
                {
                    sum = sum + a[i][k] * b[k][j];
                }
                ab[i][j] = sum;
            }
        }
        cout << "Multiplication of matrix A and B i.e. AB " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ab[i][j] << " ";
            }
            cout << endl;
        }
    }

    else
    {
        cout << "Matrix multiplication not valid here " << endl;
    }
    return 0;
}
