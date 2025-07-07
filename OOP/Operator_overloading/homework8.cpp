#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
class ChessBoard
{
    size_t rows_;
    size_t cols_;
    vector<vector<int>> data_;

    void check_bounds(size_t r, size_t c) const
    {
        if (r >= rows_ || c >= cols_)
            throw out_of_range("ChessBoard index out of range");
    }

public:
    ChessBoard(size_t rows, size_t cols)
        : rows_(rows), cols_(cols), data_(rows, vector<int>(cols, 0)) {}

    /* element‑wise access */
    int& operator()(size_t r, size_t c)
    {
        check_bounds(r, c);
        return data_[r][c];
    }
    const int& operator()(size_t r, size_t c) const
    {
        check_bounds(r, c);
        return data_[r][c];
    }

    /* row “slice” */
    vector<int>& operator[](size_t r)
    {
        if (r >= rows_) throw out_of_range("Row index out of range");
        return data_[r];
    }
    const vector<int>& operator[](size_t r) const
    {
        if (r >= rows_) throw out_of_range("Row index out of range");
        return data_[r];
    }

    /* handy size helpers (optional) */
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
};

int main()
{
    ChessBoard board(2, 3);   // 2×3 grid

    board(0, 0)  = 10;        // element access
    board[0][1]  = 20;        // row slice then element
    board[1][2]  = 30;

    cout << board[0][0] << ' ' << board(0, 1) << ' ' << board(1, 2) << '\n';

    return 0;
}
