class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //do a 4 loop by 3 to check boxes and keep two vars for chaging start point
        //for vert and horiz use two for loops of box size (9)
        for(int i = 0; i < 9; i++) {
            vector<int> rows(9,0);
            vector<int> cols(9,0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int R = (int) board[i][j] - '0'; R--;
                    if (rows[R] != 0) {
                        return false;
                    }
                    rows[R] = 1;
                }
                if (board[j][i] != '.') {
                    int C = (int) board[j][i] - '0';
                    C--;
                
                    if (cols[C] != 0) {
                        return false;
                    }
                    cols[C] = 1;
                }
            }
        }
        int j1 = 0;
        for (int i = 0; i < 3; i++) {
            int j2 = 0;
            for (int j = 0; j < 3; j++) {
                vector<int> v(9,0);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[j1+k][j2+l] == '.') {
                            continue;
                        }
                        int cur = (int) board[j1+k][j2+l] - '0';
                        cur--;
                        if (v[cur] != 0) {
                            return false;
                        }
                        v[cur] = 1;
                    }
                }
                j2+=3;
            }
            j1+=3;
        }
        return true;
    }
};

// 0,0
// 0,1
// 0,2
// 1,0
// 1,1
// 1,2
// 2,0
// 2,1
// 2,2