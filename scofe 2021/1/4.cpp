#include <bits/stdc++.h>
using namespace std;

struct content {
    char type;
    double fav;
    char view;
    int row;
    int col;

    string to_string() {
        stringstream rst;
        rst << type << " ";
        rst << fixed << setprecision(1) << fav << " ";
        rst << row << " " << col;
        return rst.str();
    }
};

int main() {
    vector<double> fav(5); for (double& db : fav) cin >> db;
    
    int n, m; cin >> n >> m;
    vector<content> input(n*m);
    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        for (int j = 0; j < m; j++) {
            input[i*m+j].view = row[j];
            input[i*m+j].row = i;
            input[i*m+j].col = j;
        }
    }
    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        for (int j = 0; j < m; j++) {
            input[i*m+j].type = row[j];
            input[i*m+j].fav = fav[row[j]-'A'];
        }
    }

    //for (int i = 0; i < n*m; i++) cout << input[i].to_string() << "\n";

    sort(input.begin(), input.end(), [](content& a, content& b) -> bool {
        if (a.view != b.view) {
            map<char, int> view;
            view['Y'] = 0;
            view['O'] = 1;
            view['W'] = 2;
            return view[a.view] < view[b.view];
        }
        if (a.fav != b.fav) return a.fav > b.fav;
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    for (int i = 0; i < n*m; i++) {
        if (input[i].view == 'W') break;
        cout << input[i].to_string() << "\n";
    }
}