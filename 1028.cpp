#include<iostream>
#include<vector>
#define max(a,b) a>b ? a : b
#define min(a,b) a>b ? b : a
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    int maxv = 0;
    vector<vector<char>> board(r + 2, vector<char>(c + 2));
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> incDir(r + 2, vector<int>(c + 2));
    vector<vector<int>> decDir(r + 2, vector<int>(c + 2));
    vector<vector<int>> available(r + 1, vector<int>(c + 1));
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            if (board[i][j] == '1') {
                incDir[i][j] = incDir[i - 1][j + 1]  + 1;
                decDir[i][j] = decDir[i - 1][j - 1]  + 1;
                int minv = min(incDir[i][j], decDir[i][j]);
                while (minv > maxv && !(incDir[i + 1 - minv][j + 1 - minv] >= minv && decDir[i + 1 - minv][j - 1 + minv] >= minv))
                    minv--;
                maxv = max(maxv, minv);
            }

        }
    }
    cout << maxv;
}