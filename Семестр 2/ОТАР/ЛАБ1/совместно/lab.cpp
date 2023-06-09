#include <iostream>
#include <tuple>
#include <climits>
#include <iomanip>
using namespace std;

const int rows = 8;
const int cols = 7;
const int ROWS = 8;
const int COLS = 7;


//KATE FUNCS

void funcmatrix(double matrix[rows][cols], const int rows, const int cols, int k)
{
    for (int indexCols = 0; indexCols < cols; indexCols++)
    {
        for (int indexRows = 0; indexRows < rows; indexRows++)
        {
            matrix[indexRows][indexCols] = k * matrix[indexRows][indexCols];
        }
    }
}

double funcRA(double matrix[rows][cols], const int rows, const int cols) 
{
    double Amax = matrix[0][0];
    double max = matrix[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        if (max > Amax)
        {
            Amax = max;
        }
    }


    double Amin = matrix[0][0];
    double min = matrix[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        if (min < Amin)
        {
            Amin = min;
        }
    }

    return Amax - Amin;
}

void RAmin_AND_RAmax(double matrix[rows][cols], double *RAmax, double *RAmin, const int rows, const int cols)
{
    double RAJ = 0;

    for (int j = 0; j < cols; j++)
    {
        double maxAJ = matrix[0][j];
        double minAJ = matrix[0][j];

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] < minAJ)
            {
                minAJ = matrix[i][j];
            }
            if (matrix[i][j] > maxAJ)
            {
                maxAJ = matrix[i][j];
            }
        }

        if (RAJ == 0)
        {
            RAJ = maxAJ - minAJ;
            *RAmax = RAJ;
            *RAmin = RAJ;
        }
        else
        {
            RAJ = maxAJ - minAJ;
            if (*RAmin > RAJ)
            {
                *RAmin = RAJ;
            }
            else if (*RAmax < RAJ)
            {
                *RAmax = RAJ;
            }
        }
    }

}

void Rmin_AND_Rmax(double matrix[rows][cols], double *Rmax, double *Rmin, const int rows, const int cols)
{
    double RAI = 0;

    for (int i = 0; i < rows; i++)
    { 
        double maxAI = matrix[i][0];
        double minAI = matrix[i][0];

        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < minAI)
            {
                minAI = matrix[i][j];
            }
            if (matrix[i][j] > maxAI)
            {
                maxAI = matrix[i][j];
            }
        }

        if (RAI == 0)
        {
            RAI = maxAI - minAI;
            *Rmax = RAI;
            *Rmin = RAI;
        }
        else
        {
            RAI = maxAI - minAI;
            if (*Rmin > RAI)
            {
                *Rmin = RAI;
            }
            else if (*Rmax < RAI)
            {
                *Rmax = RAI;
            }
        }
    }
}

void Kate() {


    int j = 8;
    int r = 3;

    cout << "Enter your number behind the group list: " << endl;
    cin >> j;

    cout << "Enter your group number(A - 1, B - 2, C - 3, D - 4): " << endl;
    cin >> r;



    int k = j + r;

    double matrix[rows][cols] = {{20.3, 15.4, 17.2, 19.2, 23.3, 18.1, 21.3},
                                 {15.3, 16.8, 13.2, 20.4, 16.5, 19.7, 20.5},
                                 {14.3, 20.1, 16.8, 14.7, 20.8, 19.5, 15.3},
                                 {19.3, 17.8, 16.2, 15.7, 22.8, 21.9, 12.5},
                                 {10.1, 21.1, 18.3, 14.7, 14.5, 18.1, 18.4},
                                 {13.9, 19.1, 18.5, 20.2, 23.8, 16.7, 20.4},
                                 {19.5, 17.2, 19.6, 17.8, 21.3, 17.5, 19.4},
                                 {17.8, 13.5, 17.8, 11.8, 18.6, 19.1, 19.5}};

    // Matrix
    funcmatrix(matrix, rows, cols, k);
    
    // RA
    double RA = funcRA(matrix, rows, cols);

    // RAmax, RAmin
    double RAmax = 0;
    double RAmin = 0;
    RAmin_AND_RAmax(matrix, &RAmax, &RAmin, rows, cols);

    // Rmax, Rmin
    double Rmax = 0;
    double Rmin = 0;
    Rmin_AND_Rmax(matrix, &Rmax, &Rmin, rows, cols);

    auto progRes = make_tuple(RA,RAmax,RAmin,Rmax,Rmin);

    cout << "The values of tuple are: ";
    cout << "\nRA is: " << get<0>(progRes) << "\nRAmax is: " << get<1>(progRes) << "\nRAmin is: " << get<2>(progRes) << "\nRmax is: " << get<3>(progRes) << "\nRmin is: " << get<4>(progRes)<< endl;
}

void Dima() {
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
    
}

int main()
{
    int check;
    cout << "Enter the number that characterizes which student you would like to run the program for. 1 - Hryhorieva, 2 - Ivaniv" << endl;
    cin >> check;

    if (check == 1){
        Kate();
    }
    else if (check == 2) {
        Dima();
    }
    
    return 0;
}