#include <iostream>
#include <iomanip>

using namespace std;

void printMatrix_3col(int airQualityIndex[][3], int N_ROWS, int N_COLUMNS);
int countUnhealthySensitive(int airQualityIndex[][3], int N_ROWS, int city_col);
int meanAirQualityIndex(int airQualityIndex[][3], int N_ROWS, int city_col);

int main() {
  const int N_ROWS = 10;
  const int N_COLS = 3;
  int city_col;
  
  int airQualityIndex[N_ROWS][N_COLS] = { {50, 68, 58},
                              {58, 115, 78},
                              {62, 110, 81},
                              {66, 124, 110},
                              {64, 152, 121},
                              {46, 143, 90},
                              {46, 143, 90},
                              {25, 91, 91},
                              {27, 19, 59},
                              {17, 13, 27} };

  string place[] = {"Grnd Jct", "Ft Col", "Den"};
  
  cout << endl << "Air Quality Index" << endl << endl;
  for (int col = 0; col < N_COLS; col++){
    cout << setw(8) << place[col] << " ";
  }
  cout << endl;
    
  printMatrix_3col(airQualityIndex, N_ROWS, N_COLS);  


  cout << "From 10/04/2020 to 10/13/2020, air quality was unhealthy for sensitive groups in: "<< endl;

  for (int col = 0; col < N_COLS; col++ ){
    if (col == 0)
      cout << "Grand Junction";
    if (col == 1)
      cout << "Fort Collins";
    if (col == 2)
      cout << "Denver";
   cout << " for "<< countUnhealthySensitive(airQualityIndex, N_ROWS, col) << " days, with an average value of " << meanAirQualityIndex(airQualityIndex, N_ROWS, col) << "." << endl;
  }

    
  /* // fort collins
  cout << countUnhealthySensitive(airQualityIndex, N_ROWS, 1) << days << endl;

  // denver
  cout << countUnhealthySensitive(airQualityIndex, N_ROWS, 2) << endl;
  */
}

void printMatrix_3col(int airQualityIndex[][3], int N_ROWS, int N_COLUMNS){
    int row, col;
    for (row = 0; row < N_ROWS; row++)
    {
        for(col = 0; col < N_COLUMNS; col++)
            cout << setw(8) << airQualityIndex[row][col] << " ";
        
        cout << endl;    
    }
}

int countUnhealthySensitive(int airQualityIndex[][3], int N_ROWS, int city_col){
  int count = 0;
  int unhealthyLevel = 101;
  int row;

  for (row = 0; row < N_ROWS; row++){
    if (airQualityIndex[row][city_col] >= unhealthyLevel)
      count++;
    }
  return count;
}

int meanAirQualityIndex(int airQualityIndex[][3], int N_ROWS, int city_col){
  int sum = 0;
  int row, avg;

  for (row = 0; row < N_ROWS; row++)
    sum = sum + airQualityIndex[row][city_col];

  avg = sum / N_ROWS;

  return avg;
}