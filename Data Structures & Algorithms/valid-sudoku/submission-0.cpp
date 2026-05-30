class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for row - compute a hashmap for each row and check if freq>1
        // for column - same as above
        // since the digits are 1-9 and the size of the board is fixed, we can use a simple count 
        // instead of a hashmap 
        

        for(vector<char>& row : board) {
            int count[10]={0};
            for(char ch:row) {
                if(ch=='.') continue;
                count[ch-'0']++;
                if(count[ch-'0']>1) return false;
            }
            
        }

        int ccount[10][10]={0};
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                char ch=board[i][j];
                if(ch=='.') continue;
                ccount[j][ch-'0']++;
                if(ccount[j][ch-'0']>1) return false;
            }
        }

        for(int boxRow = 0; boxRow < 9; boxRow += 3) {
    for(int boxCol = 0; boxCol < 9; boxCol += 3) {

        int count[10] = {0};

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                char ch = board[boxRow + i][boxCol + j];
                if(ch == '.') continue;

                count[ch - '0']++;

                if(count[ch - '0'] > 1) return false;
            }
        }
    }
}

        return true;

    }
};
