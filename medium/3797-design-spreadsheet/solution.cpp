#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Spreadsheet {
private:
    vector<int> grid;
    int evaluate(const string& s, int start, int end) {
        if (s[start] >= 'A' && s[start] <= 'Z') {
            int col = s[start] - 'A';
            int row = 0;
            for (int i = start + 1; i < end; ++i) {
                row = row * 10 + (s[i] - '0');
            }
            return grid[row * 26 + col];
        } 
        else {
            int val = 0;
            for (int i = start; i < end; ++i) {
                val = val * 10 + (s[i] - '0');
            }
            return val;
        }
    }

public:
    Spreadsheet(int rows) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        grid.assign((rows + 1) * 26, 0);
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        for (size_t i = 1; i < cell.length(); ++i) {
            row = row * 10 + (cell[i] - '0');
        }
        grid[row * 26 + col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = 0;
        for (size_t i = 1; i < cell.length(); ++i) {
            row = row * 10 + (cell[i] - '0');
        }
        grid[row * 26 + col] = 0;
    }
    
    int getValue(string formula) {
        int plusPos = formula.find('+');
        int x = evaluate(formula, 1, plusPos);
        int y = evaluate(formula, plusPos + 1, formula.length());
        
        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */