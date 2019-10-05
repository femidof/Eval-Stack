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



