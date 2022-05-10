#include <iostream>
using namespace std;

int matrix[9] = {
    1,2,3,
    4,5,6,
    7,8,9
};

void turnFaceClockwise(int *matrix) {

    int matrix2[9];

    matrix2[0] = matrix[6];
    matrix2[1]=  matrix[3];
    matrix2[2] = matrix[0];
    matrix2[3] = matrix[7];
    matrix2[4] = matrix[4];
    matrix2[5] = matrix[1];
    matrix2[6] = matrix[8];
    matrix2[7] = matrix[5];
    matrix2[8] = matrix[2];

    //Change the original values of matrix to the rotated ones
    for(int i=0; i<9; i++){
        matrix[i] = matrix2[i];
    }

}

void turnFaceCounterClockwise(int *matrix) {


    int matrix2[9];

    matrix2[0] = matrix[2];
    matrix2[1]=  matrix[5];
    matrix2[2] = matrix[8];
    matrix2[3] = matrix[1];
    matrix2[4] = matrix[4];
    matrix2[5] = matrix[7];
    matrix2[6] = matrix[0];
    matrix2[7] = matrix[3];
    matrix2[8] = matrix[6];

    //Change the original values of matrix to the rotated ones
    for(int i=0; i<9; i++){
        matrix[i] = matrix2[i];
    }

}
// END TURNFACECOUNTERCLOCKWISE FUNCTION--------------------


int main() {


    cout << "Starting matrix:\n";
    for (int i=0; i<9; i++) {

      cout << matrix[i];
      cout << "\n";

  }


  cout << "Ending matrix:\n";
  //turnFaceClockwise(matrix);

  for (int i=0; i<9; i++) {

      cout << matrix[i];
      cout << "\n";

  }

  char myvariable = 1;

  if (myvariable == 1) {
      cout << "it worked";
  }

  cout << matrix[myvariable];
  
  return 0;
}