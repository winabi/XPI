#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    const int ROWS = 8;
    const int COLS = 7;

    int k = 15;

    double matrix[ROWS][COLS] = { {20.3, 15.4, 17.2, 19.2, 23.3, 18.1, 21.9},
                                {15.3, 16.8, 13.2, 20.4, 16.5, 19.7, 20.5},
                                {14.3, 20.1, 16.8, 14.7, 20.8, 19.5, 15.3},
                                {19.3, 17.8, 16.2, 15.7, 22.8, 21.9, 12.5},
                              {10.1, 21.1, 18.3, 14.7, 14.5, 18.1, 18.4},
                              {13.9, 19.1, 18.5, 20.2, 23.8, 16.7, 20.4},
                              {19.5, 17.2, 19.6, 17.8, 21.3, 17.5, 19.4},
                              {17.8, 13.5, 17.8, 11.8, 18.6, 19.1, 19.5} };

    double row_scope_Max[ROWS] = {0};
    double row_scope_Min[ROWS] = {0};
    double col_scope_Max[COLS] = {0};
    double col_scope_Min[COLS] = {0};

    // Множення матриці на число k для отримання матриці A
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            matrix[i][j] *= k;
        }
    }

    // Вивід матриці А
    cout << "Результат множення матрицi на число k:" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            cout << matrix[i][j] << "\t ";
        }
        cout << endl;
    }

    // Розмах матриці
    double min_matrix = INT_MAX;
    double max_matrix = INT_MIN;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < min_matrix) {
                min_matrix = matrix[i][j];
            }
            if (matrix[i][j] > max_matrix) {
                max_matrix = matrix[i][j];
            }
        }
    }

    cout << "Розмах матрицi A: " << max_matrix - min_matrix << endl;

    // Розмах кожного стовпця
    double cols_scope[COLS];
    for (int j = 0; j < COLS; j++) {
        double min_col = INT_MAX;
        double max_col = INT_MIN;
        for (int i = 0; i < ROWS; i++) {
            if (matrix[i][j] < min_col) {
                min_col = matrix[i][j];
            }
            if (matrix[i][j] > max_col) {
                max_col = matrix[i][j];
            }
        }
        cols_scope[j] = max_col - min_col;
        cout << "Розмах стовпця " << j << ": " << max_col - min_col << endl;
    }

    // Розмах кожного рядка
    double rows_scope[ROWS];
    for (int i = 0; i < ROWS; i++) {
        double min_row = INT_MAX;
        double max_row = INT_MIN;
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < min_row) {
                min_row = matrix[i][j];
            }
            if (matrix[i][j] > max_row) {
                max_row = matrix[i][j];
            }
        }
        rows_scope[i] = max_row - min_row;
        cout << "Розмах рядка " << i << ": " << max_row - min_row << endl;
    }

    // Знаходимо мінімальний та максимальний розмах стовпців
    double min_scope_col = INT_MAX;
    double max_scope_col = INT_MIN;
    for (int j = 0; j < COLS; j++) {
        if (cols_scope[j] < min_scope_col) {
            min_scope_col = cols_scope[j];
        }
        if (cols_scope[j] > max_scope_col) {
            max_scope_col = cols_scope[j];
        }
    }
    
    cout << "Мiнiмальний розмах стовпцiв: " << min_scope_col << endl;
    cout << "Максимальний розмах стовпцiв: " << max_scope_col << endl;

    // Знаходимо мінімальний та максимальний розмах рядків
    double min_scope_row = INT_MAX;
    double max_scope_row = INT_MIN;
    for (int i = 0; i < ROWS; i++) {
        if (rows_scope[i] < min_scope_row) {
            min_scope_row = rows_scope[i];
        }
        if (rows_scope[i] > max_scope_row) {
            max_scope_row = rows_scope[i];
        }
    }

    cout << "Мiнiмальний розмах рядкiв: " << min_scope_row << endl;
    cout << "Максимальний розмах рядкiв: " << max_scope_row << endl;

    return 0;
}
