/* A lotto game program that compares user inputs to winning numbers and displays the prize won
Author : Nicolas Ruth
Date: 18/03/2022
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define SIZEA 43

//functions
void userNumbers(int *numbersEntered, int *lottoArray);
void displayInput(int *displayNum);
void sort(int[]);
void compareResult(int *numArray, int *winningNumbers);
void numberFreq(int *lottoArray);

//main function
int main()
{

    int numArray[6];
    int winArray[SIZE] = {1, 3, 5, 7, 9, 11};
    int *numbers;
    int *displaying, k, i;
    int *frequency;
    int lottoArray[43] = {0};
    int choice, counter = 0;
    int freqSum = 0;
    char errorcheck;

    do
    {
        //The Menu presented to the user
        printf("\n1. Enter your lotto numbers\n");
        printf("\n2. Display my numbers\n");
        printf("\n3. Arrange my numbers\n");
        printf("\n4. Compare with winning numbers\n");
        printf("\n5. Display frequency of numbers entered\n");
        printf("\n6. Exit program\n");
        scanf("%d", &choice);
        errorcheck = getchar();

        if (choice == 1) //Option to enter lotto numbers
        {
            //User's numbers
            userNumbers(numArray, lottoArray);

            counter++; //used to check options are chosen in correct order

        }// end if
        else if (choice == 2) //Option to display chosen numbers
        {
            if (counter > 0)
            {
                //Displaying the numbers the user input
                displayInput(numArray);
            }
            else
            {
                printf("Please choose option 1 first.\n");
            }

        }//end else if
        else if (choice == 3) //Option to sort all numbers in ascending order
        {
            if (counter > 0)
            {
                //Sorting the numbers in ascending order
                sort(numArray);
            }
            else
            {
                printf("Please choose option 1 first.\n");
            }

        }//end else if
        else if (choice == 4) //Option to compare inputs with winning numbers
        {
            if (counter > 0)
            {
                //comapring the winning numbers and numbers chosen by user
                compareResult(numArray, winArray);
            }
            else
            {
                printf("Please choose option 1 first.\n");
            }

        }//end else if
        else if (choice == 5) //Option to see frequency of each number inputted
        {
            if (counter > 0)
            {
                //checking and counting frequency of the numbers inputted by user
                numberFreq(lottoArray);
            } //end if
            else
            {
                printf("Please choose option 1 first.\n");
            } //end else

        } //end else if
        

    } while (choice != 6 && errorcheck != (choice >= 'a' && choice <= 'z'));
    printf("Thank you for playing\n");

    return 0;

} //end main

void userNumbers(int *numbersEntered, int *lottoArray)
{
    int i, y, temp;
    char errorcheck;

    printf("Enter %d numbers from 1 to %d : ", SIZE, SIZEA);
    for (int i = 0; i < 6; i++)
    {

        scanf("%d", & *(numbersEntered + i));
        errorcheck = getchar(); //error check for character input

        if (*(numbersEntered + i) > 0 && *(numbersEntered + i) < 43)
        {
            for (int y = 0; y < i; y++)
            {
                //checks to see if number is input twice
                if (*(numbersEntered + i) == *(numbersEntered + y))
                {
                    printf("You can only choose each number once.\n");
                    *(numbersEntered + i) = 0;
                    break;

                } //end if

            } //end loop for same number
            if (*(numbersEntered + i) == 0)
            {
                printf("");
                scanf("%d", & *(numbersEntered + i));
            } //end if
        }
        else
        {
            printf("You may only enter a number from 1 to 43 inclusive.\n");
            *(numbersEntered + i) = 0;
        } //end else
        if (*(numbersEntered + i) == 0) //allows user to enter another number after error
        {
            printf("");
            scanf("%d", & *(numbersEntered + i));
        } //end if

        temp = *(numbersEntered + i); //used to place last rounds numbers into temporary variable
        *(lottoArray + temp) = *(lottoArray + temp) + 1; //stores temp variable in a array for all past elements input
    }//end for
} //end function

void displayInput(int *displayNum)
{
    int i;
    
    printf("The numbers you have entered are: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(displayNum + i));
    } //end for
    printf("\n");
} //end function

void sort(int sArray[])
{
    int i, j, temp;
    //Bubble Sort Algorithm
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (*(sArray + i) > *(sArray + j))
            {
                //temp variable is used to store the element which is being swapped
                temp = *(sArray + i);
                *(sArray + i) = *(sArray + j);
                *(sArray + j) = temp;
            }//end if
        } //end for
    } //end for

    printf("Your sorted numbers are: ");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(sArray + i));
    } //end for
    printf("\n");
} //end function


void compareResult(int *numArray, int *winArray)
{

    int sameNum = 0;
    int i,k;

    //loop throught arrays to compare numbers
    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < 6; k++)
        {
            if (*(winArray + k) == *(numArray + i))
            {
                sameNum++;

            } //end if

        } //end for

    } //end out for

    if (sameNum == 6)
    {
        printf("JACKPOT!!!\n");
    } //end if
    else if (sameNum == 5)
    {
        printf("Brand new car!!!\n");
    } //end else if
    else if (sameNum == 4)
    {
        printf("Weekend away in Dubai!!!\n");
    } //end else if
    else if (sameNum == 3)
    {
        printf("Cinema pass to every IMC complex!!!\n");
    } //end else if
    else
    {
        printf("\nNo luck today, maybe next time!\n\n");
    }//end else
    
} //end function

void numberFreq(int *lottoArray)
{
    int i;

    for (int i = 0; i < 43; i++) //Displaying frequency of all numbers entered
    {
        if (*(lottoArray + i) != 0)
        {
            printf("\nYou chose number %d,  %d times\n", i, *(lottoArray + i));
        } //end if

    } //end for

} //end function