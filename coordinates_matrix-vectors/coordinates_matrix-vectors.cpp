#include <iostream>
#include <Windows.h>
#include <vector>
#include <math.h>

using namespace std;


vector< vector<int> > action(vector<vector<int> > A, int N, int K)
{
    int x, y;
    vector< vector<int> > Res(2, vector<int>(K));
    vector< vector<int> > Res2(2, vector<int>(K));
    float cres = INT_MAX;

    for (int zxc = 0; zxc < A[0].size() - 1; zxc++)
    {

        if (zxc != 0)
        {
            int swx, swy;
            swx = A[0][zxc]; A[0][zxc] = A[0][0]; A[0][0] = swx;
            swy = A[1][zxc]; A[1][zxc] = A[1][0]; A[1][0] = swy;
        }
        for (int i = 1; i < A[0].size(); i++)
        {
            Res.resize(2);
            Res[0].resize(K);
            Res[1].resize(K);

            Res[0][0] = A[0][0];
            Res[1][0] = A[1][0];

            Res[0][1] = A[0][i];
            Res[1][1] = A[1][i];

            int count = 1;
            float cx = A[0][0] + A[0][i], cy = A[1][0] + A[1][i], c;

            x = A[1][i] - A[1][0];                      //коэф-ты в уравнении прямой
            y = A[0][i] - A[0][0];

            for (int j = 2; j < A[0].size(); j++)
            {

                if (((A[0][j] - A[0][0]) * x == (A[1][j] - A[1][0]) * y) && i != j)
                {
                    count++;
                    if (count <= K - 1)
                    {
                        Res[0][count] = A[0][j];
                        Res[1][count] = A[1][j];
                        cx += A[0][j]; cy += A[1][j];
                    }
                }

            }
            if (count == K - 1)
            {
                cx = cx / count; cy = cy / count;
                c = sqrt(cx * cx + cy * cy);
                if (c < cres)
                {
                    cres = c;
                    Res2 = Res;
                }
            }
            Res.clear();
        }
    }
    if (cres != INT_MAX) return Res2;
    else cout << "There is no " << K << " dots in one line";
}

vector< vector<int> > enter(int K)
{
    vector< vector<int> > A(2, vector<int>(K));
    for (int j = 0; j < K; j++)
    {
        cin >> A[0][j] >> A[1][j];
    }
    return A;
}


void print(vector<vector<int> > A)
{
    for (unsigned int j = 0; j < A[1].size(); j++)
    {
        int i = 0;
        cout << "(" << A[i][j] << "," << A[i + 1][j] << ") ";
    }
}

int main()
{
    cout << "Enter count of dots (N): ";
    int N, K;
    cin >> N;
    cout << "Enter count of dots in one line (K): ";
    cin >> K;
    print(action(enter(N), N, K));

}

