/*
* File: payment_calc.c
* Programmer: Zander Møysal
* Date: 14.10.2015
*
* This program calculates the pay for multiple people given input from the user
* This includes overtime, if more than 40 hours worked, you get 50% per hour
* 
*/

#include <stdlib.h>
#include <stdio.h>

#define REG_LIMIT 40.0
#define OT_FACTOR 1.5

int get_int();

float get_float();

int main(int argc, char **argv)
{    
    // Declaring variables
    int id_number,
        num_people;
    float hours,
        rate,
        pay;
    printf("How many people: ");
    scanf("%d", &num_people);
    do
    {
        printf("\nInput ID number: ");
        id_number = get_int();
        
        printf("Input rate of pay: ");
        rate = get_float();
        
        printf("Input hours: ");
        hours = get_float();
        
        if (hours > REG_LIMIT)
        {
            pay = (REG_LIMIT * rate) + ((hours - REG_LIMIT) * (rate * OT_FACTOR));
        }
        else
        {
            pay = hours * rate;
        }
        printf("\nID Number: %d\n", id_number);
        printf("You've worked %.2f hours, with a rate of $%.2f per hour "
              "which equals to a pay of: $%.2f.\n\n", hours, rate, pay);
        num_people--;
    }
    while (num_people > 0);
}


int get_int()
{
    int input;
    char ch;    
    
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
    printf(" is not valid\nPlease enter an integer value such as 3: ");
    } 
    return input;
}


float get_float()
{
    float input;
    char ch;    
    
    while (scanf("%f", &input) != 1.0)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
    printf(" is not valid\n"
        "Please enter a float or int value such as 5.5, 2.0 or 1: ");
    }
    return input;
}
