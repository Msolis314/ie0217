#include <iostream>

int main(){
    //condition is true 
    int number = 5;

    if (number > 0){
        //code
    }

    //code after it 

    //condition is false
    if (number < 0){
        //code
    }

    //code after it

    //condition is true
    if (number > 0){
        //code
    } else {
        //code
    }

    //code after if...else

    //condition is false
    if (number < 0){
        //code
    } else {
        //code
    }

    //code after if...else

    //1st condition is true 

    number = 2;
    if (number > 0){
        //code
    } else if (number == 0){
        //code
    } else {
        //code
    }

    //code after if

    //2nd condition is true
    number = 0;
    if (number > 0){
        //code
    } else if (number == 0){
        //code
    } else {
        //code
    }   

    //code after if
    
    //All conditions are false
    number = -2;
    if (number > 0){
        //code
    } else if (number == 0){
        //code
    } else {
        //code
    }

    //code after if

    //switch statement
    char oper;
    float num1, num2;
    std::cout << "Enter an operator (+, -, *, /):\n ";
    std::cin >> oper;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> num1 >> num2;

    switch (oper){
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            std::cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            std::cout << "Error! The operator is not correct";
            break;

    }

    //Anidaciones de if 

    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // outer if condition
    if (num !=0){

        // inner if condition
        if (num > 0){
            std::cout << "The number is positive. "  << std::endl;
        }
        // inner else condition 
        else {
            std::cout << " The number is negative."  << std::endl;
        }
    }
    // outer else condition 
    else {
        std::cout << "The number is 0 it is neither positive nor negative" << std::endl;

    }

    std::cout << "This is always printed. \n";

    //Loops 
    using namespace std;

    for (int i = 0 ; i <=5; ++i) {
        cout << i << " ";
    }

    int num_array[] = {1,2,3,4,5,6,7,8,9,10};

    for (int n : num_array){
        cout << n << " ";
    }

    int i = 1;

    //while loop from 1 to 5
    while (i <= 5){
        cout << i << " ";
        ++i;
    }

    i = 1;
    //do...while loop from 1 to 5
    do {
        cout << i << " ";
        ++i;
    } while (i <= 5);
    return 0;
}