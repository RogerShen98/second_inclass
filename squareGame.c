// Lo Shu Magic Square

#include<stdio.h> // input/output library
#include <stdlib.h> // random no. library
#include <time.h> // get time variable

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

    while(true){
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
        for(int i = 0; i < arraySize; i++) {
            for(int j = 0 ; j < arraySize ; j++) {
                if(magicSquare[i][j])
            }
        }

    }
    // print randomnized array
    printf("\nHere is a randomnized magic square:\n");
    for(int i = 0; i < arraySize; i++) {
      for(int j = 0 ; j < arraySize ; j++) {
          printf("%d ",magicSquare[i][j]);
      }
      printf("\n");
    }
    

}
