//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//size_t findMinCost(vector<vector<size_t>>& cost, size_t m, size_t n, vector<vector<size_t>>& dp, vector<vector<char>>& path)
//{
//    // Заполнение dp массива и path
//    for (size_t i = 1; i <= m; ++i) {
//        for (size_t j = 1; j <= n; ++j) {
//            if (dp[i - 1][j] < dp[i][j - 1]) {
//                dp[i][j] = cost[i - 1][j - 1] + dp[i - 1][j];
//                path[i][j] = 'U'; // U - вверх 
//            } else {
//                dp[i][j] = cost[i - 1][j - 1] + dp[i][j - 1];
//                path[i][j] = 'R'; // R - вправо 
//            }
//        }
//    }
//
//    // Восстановление пути
//    size_t i = m, j = n;
//    stack<char> optimalPath;
//    while (i > 0 && j > 0) {
//        optimalPath.push(path[i][j]);
//        if (path[i][j] == 'U') {
//            --i;
//        } else {
//            --j;
//        }
//    }
//
//    // Вывод оптимального пути
//    cout << "Optimal Path: ";
//    while (!optimalPath.empty()) {
//        cout << optimalPath.top();
//        optimalPath.pop();
//    }
//    cout << endl;
//
//    // Возвращение минимальных затрат для достижения точки B
//    return dp[m][n];
//}
//void fillMatrixFromInput(vector<vector<size_t>>& matrix)
//{
//    size_t rows, cols;
//
//    cout << "Enter the number of rows: ";
//    cin >> rows;
//
//    cout << "Enter the number of columns: ";
//    cin >> cols;
//
//    matrix.resize(rows, vector<size_t>(cols, 0));
//
//    cout << "Enter the elements of the matrix:" << endl;
//    for (size_t i = 0; i < rows; ++i) {
//        for (size_t j = 0; j < cols; ++j) {
//            cout << "Element [" << i << "][" << j << "]: ";
//            cin >> matrix[i][j];
//        }
//    }
//}
//
//int main()
//{
//    vector<vector<size_t>> cost;
//
//    // Заполнение матрицы с клавиатуры
//    fillMatrixFromInput(cost);
//
//    // Вывод содержимого матрицы
//    cout << "Matrix contents:" << endl;
//    for (size_t i = 0; i < cost.size(); ++i) {
//        for (size_t j = 0; j < cost[i].size(); ++j) {
//            cout << cost[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    // Размеры массива
//    size_t m = cost.size();
//    size_t n = cost[0].size();
//
//    // Инициализация dp и path массивов
//    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
//    vector<vector<char>> path(m + 1, vector<char>(n + 1, 0));
//
//    // Нахождение минимальных затрат и оптимального пути
//    size_t minCost = findMinCost(cost, m, n, dp, path);
//
//    // Вывод результата
//    cout << "Minimal cost of the path: " << minCost << endl;
//
//    return 0;
//}
