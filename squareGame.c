// Lo Shu Magic Square

#include<stdio.h> // input/output library
#include <stdlib.h> // random no. library
#include <time.h> // get time variable
#include <stdbool.h> // boolean library

// declaration of global constant
const int arraySize = 3; // size for 2-d array

int main()
{
    // 2-D array declaration 
    int magicSquare[arraySize][arraySize];

    // time declaration
    time_t t;

    // declare integer array to be shuffled
    int num[9] = {1,2,3,4,5,6,7,8,9};

    // random number generator 
    srand((unsigned) time(&t));

    // welcome message
    printf("Welcome to the Lo Shu Magic Square!\n");

    // loop until the magic square is valid
    int valid = 0;
    int squaresGenerated = 1;

    while(valid != 1){
        // shuffle the array with number 1-9
        for(int i = 0; i < 9; i++){
            int index = rand() % 9;

            // swap
            int temp = num[i];
            num[i] = num[index];
            num[index] = temp;
        }

        // fill randomnized array
        int counter = 0;
        for(int i = 0; i < arraySize; i++) {
            for(int j = 0 ; j < arraySize ; j++) {
                magicSquare[i][j] = num[counter];
                counter++;
            }
        }

        // check if it is a Lo Shu Magic Square
        int sum = 15; // sum for each row, column or diagonally
       
        if(
            // check the sum of each row
           magicSquare[0][0]+magicSquare[0][1]+magicSquare[0][2] == 15 &&
           magicSquare[1][0]+magicSquare[1][1]+magicSquare[1][2] == 15 &&
           magicSquare[2][0]+magicSquare[2][1]+magicSquare[2][2] == 15 &&

            // check the sum of each column
           magicSquare[0][0]+magicSquare[1][0]+magicSquare[2][0] == 15 &&
           magicSquare[0][1]+magicSquare[1][1]+magicSquare[2][1] == 15 &&
           magicSquare[0][2]+magicSquare[1][2]+magicSquare[2][2] == 15 &&

            // check the diagonal sum
           magicSquare[0][0]+magicSquare[1][1]+magicSquare[2][2] == 15 &&
           magicSquare[0][2]+magicSquare[1][1]+magicSquare[2][0] ==15 )
                valid = 1;
            
        else
            squaresGenerated++;

         
    }

    // The total number of squares generated and tested before success, the count.
    printf("The total number of squares generated and tested before success: %d",squaresGenerated);

    // print randomnized array
    printf("\nHere is a valid randomnized Lo Shu Magic Square:\n");
    for(int i = 0; i < arraySize; i++) {
      for(int j = 0 ; j < arraySize ; j++) {
          printf("%d ",magicSquare[i][j]);
      }
      printf("\n");
    }
    

}
