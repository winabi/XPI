#include <iostream>
#include <tuple>
using namespace std;

const int rows = 8;
const int cols = 7;

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



int main()
{
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

    return 0;
}