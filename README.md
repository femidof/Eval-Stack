# Eval-Stack



Problem

We as humans write math expression in infix notation, e.g. 5 + 2 (the operators are written in-between the operands). In computer’s language, however, it is preferred to have the operators on the right side of the operands, i.e. 5 2 +. For more complex expressions that include parenthesis and multiple operators, a compiler has to convert the expression into postfix first and then evaluate the resulting postfix.
Write a program that takes an “infix” expression as input, uses stacks to convert it into postfix expression, and finally evaluates it.
Input:
- Input will be an infix expression as a string with maximum length of 50.
- The expression will contain only positive integer numbers (no negative or floating point number)
- The numbers can be single or multiple digits
The expression will contain only the following operators and parenthesis: +, - , / , * , ^ , % , (, )
- The expression might contain imbalance parenthesis (so you have to check it before starting the conversion. If it is not balanced, you should print a message and stop)
- The expression can have whitespace between symbols, but not within a multiple digit number. For example 56 + 7, or, 56+7, both are valid input., But 5 6+7 will not be used in input

Requirements:
1. You must have to use Stack during the conversion and evaluation process.
2. The main function of the code should look like this. You can add maximum 10 more lines of codes in the main function as need for your logic, free any allocated memory, etc.:

int main(void)
{
while(strcmp(str = menu(), "exit")!=0)
{
if (isBalancedParenthesis(str))
{
postFix = convertToPostfix(str);
evaluate(postFix);
}
else
printf("Parenthesis imbalanced");
}
return 0;
}

In addition to the other functions for multiple stacks, you have to write and utilize the following functions in your solution:
a) char* menu(): This function display a menu. e for entering an infix, x for exiting the program.
-If the user chooses e, it takes an infix as input, copy it into a dynamically allocated string and return it to the main function. If the user chooses x, it will copy ‘exit’ to a dynamically allocated string and return it.

b) int isBalancedParenthesis(char *): This function takes an infix expression and check the balance of the parenthesis. It returns 1, if it is balanced and 0 otherwise.

c) int isOperator(char c): this function takes a char and returns 1 if the char is an operator. Otherwise, it returns 0;

d) int getOperatorPriority(char c): this function takes an operator and returns its priority

e) int convetToInt(char c): this function converts a char digit into int digit

f) int calculate(int a, int b, char op): this function takes to operand and one operator and returns the result of the operation based on op; Example: calculate( 5, 6, ‘+’) will return 11
