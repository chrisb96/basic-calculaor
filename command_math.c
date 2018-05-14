//
//  command_math.c
//  
//
//  Created by Chris Becker on 4/8/18.
// this program functions like a basic calculator taking an operator and two numbers and performing the operation
//

#include <stdio.h>
#include <stdlib.h>
int getLine(char *str, int n);
double processLine(char *str);

int main(void){
    char data[10];
    //get input from user
    printf("enter a mathematical operator followed by the numbers you wish to use: \n");
    getLine(data, 10);
    printf("\n");
    
    //parse input from user and store in variable answer
    //if you changed this variable to double and the printf to %.3f the program would work with doubles to the 3rd decimal place, however the program speficications mandated integer operations which is lame and lacking in functionality over the other version i described which performed better
    int answer = processLine(data);
    printf("answer is %d \n",answer);
    return 1;
}

//gets line
int getLine(char *str, int n){
    int ch, i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < n){
            *str++= ch;
            i++;
        }
        
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
    
}

double processLine(char *str){
    int xint, yint;
    //pull out the operand
    char symb = *str;

    
    //moves pointer beyond any blank space until next bit of info
    str++;
    while(*str == ' '){
        str++;
    }
    
    //-----------------------------------------------------------------------------------
    //pull out x
    //its a negative number append the negative sign otherwise go as normal
    if(*str == '-'){
        str++;
        //assign a new string containing just the first variable (to be converted with atoi)
        char x[2] = {*str, '\0'};
        //convert x to an int
         xint = atoi(x) * - 1;
    }
    else{
        //assign a new string containing just the first variable (to be converted with atoi)
        char x[2] = {*str, '\0'};
        //convert x to an int
         xint = atoi(x);
    }
    //-----------------------------------------------------------------------------------

    //move poiner so it now points to y, skipping any blank space inbetween
    str++;
    while(*str == ' '){
        str++;
    }
    //-----------------------------------------------------------------------------------
    //pull out y
    if(*str == '-'){
        str++;
        char y[2] = {*str, '\0'};
         yint = atoi(y) * -1;
    }
    else{
    //assign yint to the numerical value the character array y contains
    char y[2] = {*str, '\0'};
    yint = atoi(y);
    }
    
    //-----------------------------------------------------------------------------------
    //switch case to take care of possibilites and return results
    switch(symb) {
        case '+' :
            return xint + yint;
            break;
            
        case '-' :
            return xint - yint;
            break;
            
        case 'x' :
            return xint * yint;
            break;
            
        case '/' :
            return xint / yint;
            break;
    
        default :
            printf("Invalid operand \n" );
    }
    
    return 0;
    
}
