#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

size_t findMinCost(vector<vector<size_t>>& cost, size_t m, size_t n, vector<vector<size_t>>& dp, vector<vector<char>>& path)
{
    // Инициализация базовых значений
    dp[0][0] = cost[0][0];
    path[0][0] = '-';
    // Заполнение первой строки и первого столбца
    for (size_t i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
        path[i][0] = 'U'; // Движение вверх
    }
    for (size_t j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
        path[0][j] = 'R'; // Движение направо
    }

    // Заполнение dp массива и path
    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = cost[i][j] + dp[i - 1][j];
                path[i][j] = 'U'; // Движение вверх
            } else {
                dp[i][j] = cost[i][j] + dp[i][j - 1];
                path[i][j] = 'R'; // Движение направо
            }
        }
    }
    // Восстановление оптимального пути
    size_t i = m - 1, j = n - 1;
    cout << "Optimal Path: ";
    while (i > 0 || j > 0) {
        cout << path[i][j] << " ";
        if (path[i][j] == 'U') {
            --i;
        } else {
            --j;
        }
    }
    cout << endl;
    // Вывод минимальных затрат для достижения точки B
    return dp[m - 1][n - 1];
}

// Остальной код остается без изменений
void fillMatrixFromInput(vector<vector<size_t>>& matrix)
{
    size_t rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    matrix.resize(rows, vector<size_t>(cols, 0));

    cout << "Enter the elements of the matrix:" << endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main()
{
    vector<vector<size_t>> cost;

    // Заполнение матрицы с клавиатуры
    fillMatrixFromInput(cost);

    // Вывод содержимого матрицы
    cout << "Matrix contents:" << endl;
    for (size_t i = 0; i < cost.size(); ++i) {
        for (size_t j = 0; j < cost[i].size(); ++j) {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }

    // Размеры массива
    size_t m = cost.size();
    size_t n = cost[0].size();

    // Инициализация dp и direction массивов
    vector<vector<size_t>> dp(m, vector<size_t>(n, 0));
    vector<vector<char>> direction(m, vector<char>(n, '-'));

    // Нахождение минимальных затрат и оптимального пути
    size_t minCost = findMinCost(cost, m, n, dp, direction);

    // Вывод результата
    cout << "Minimal cost of the path: " << minCost << endl;

    return 0;
}