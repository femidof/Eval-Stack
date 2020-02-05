    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    #include <math.h>

    #define EMPTY -1
    #define SIZE 100

    struct stack {
        char items[100];
        int top;
    };

    struct stack_int {
        int items_int[100];
        int top_int;
    };

    void initialize(struct stack* stackPtr);
    int full(struct stack* stackPtr);
    int push(struct stack* stackPtr, char value);
    int empty(struct stack* stackPtr);
    char pop(struct stack* stackPtr);
    char peek(struct stack* stackPtr);
    int top(struct stack* stackPtr);
    void initialize_int(struct stack_int* stackPtr_int);
    int full_int(struct stack_int* stackPtr_int);
    int push_int(struct stack_int* stackPtr_int, int value);
    int empty_int(struct stack_int* stackPtr_int);
    int pop_int(struct stack_int* stackPtr_int);
    int top_int(struct stack_int* stackPtr_int);
    int peek_int(struct stack_int* stackPtr_int);
    int isBalancedParenthesis(char *);
    int isOperator(char c);
    int isOperand(char c);
    char* convertToPostfix(char *infix);
    char* menu();
    int getOperatorPriority(char c);
    int convetToInt(char c);
    int pwr(int x,int y);
    int calculate(int a, int b, char op);
    int elvaluate(char *exp);




    char* menu()
    {
        char selection,infix[100];
        char *ptr, c;
        int infixLenght;

         printf("\nThis is the menu. Please make a selection. choose:\n\n");
         printf("'e' for entering an infix \n\nor\n\n'x' for exiting the program.\n");
         printf("\nEnter your selection: ");
         scanf("%c", &selection);

            while((c = getchar()) != '\n'&& c != EOF); // so scanf can take another input

         if (selection == 'e') {
                 printf("\n Enter your what you will like to be converted to an infix.\n It must be less than 51 characters: ");
                 scanf("%[^\n]s",infix);
                 infixLenght= strlen(infix) + 1;
                 ptr = (char*)malloc(infixLenght*sizeof(int));
                 strcpy(ptr, infix);
                 return (ptr);

         }

         else if( selection == 'x')
            {
            int* close = (int*)malloc(5*sizeof(int));
            strcpy(ptr,"exit");
            printf("You chose to exit. Good Bye..\n");

            return ptr;
         }


          return ptr;
        }

    int isBalancedParenthesis (char* str)
    {

        struct stack *stackPtr = malloc(strlen(str));
        initialize(stackPtr);

      for (int i = 0; i < strlen(str); i++) {

            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                push(stackPtr, str[i]);
            }

            if (str[i] == ')') {
                    if (peek(stackPtr) == '(')
            {
                pop(stackPtr);
                }
                else
                return 0;
            }

            if (str[i] == ']') {
                    if (peek(stackPtr) == '[')
            {
                pop(stackPtr);
                }
                else
                {
                    return 0;
                }
            }
            if (str[i] == '}') {
                    if (peek(stackPtr) == '{')
            {
                pop(stackPtr);
                }
                else
                {
                    return 0;
                }
            }
      }
              return empty(stackPtr);
    }

    int isOperator(char c)
    {
       if (c == '%' || c ==  '-' || c == '*' ||c ==  '+' || c ==  '/' || c == '^' )
        {
            return 1;
        } else
        {
            return 0;
        }

    }

    int getOperatorPriority(char c)
    {
            switch (c) {
                case '(':
                return 1;

                case '+':
                case '-':
                return 2;

                case '*':
                case '/':
                case '%':
                return 3;

                case '^':
                return 4;

                default:
                return 0;
            }
    }

    int isOperand(char c)
    {
        return (c >= '0' && c <= '9');
    }

    int convetToInt(char c)
    {
        return (c >= '0' && c <= '9' ) ? c-'0' : c;
    }

    int calculate(int a, int b, char op)
    {
        switch (op) {
            case '+':
            return a + b;
            case '-':
            return a - b;
            case '^':
            return pwr(a, b);
            case '%':
            return a % b;
            case '*':
            return a * b;
            case '/':
            return a / b;
            default:
            return 0;
        }
    }

    int pwr(int x,int y)
    {
            int i,p=1;

            for (i=1;i<=y;i++)
                {
            p=p*x;
        }
        return p;
    }

    char* convertToPostfix(char *infix){

        int i,j;
        char* postfix = malloc(strlen(infix));
        struct stack *stackPtr = malloc(strlen(infix));
        initialize(stackPtr);
        if (!stackPtr)
            {
                return 0;
            }

        for (i = 0, j = -1; i <= strlen(infix); ++i)
        {
            if (infix[i] == ' ' || infix[i] == '\t')
                {
                i++;
            }

            if (isdigit(infix[i]))
                {
                postfix[++j] = infix[i];
            }

            else if (infix[i] == '(')
                {
                    push(stackPtr, infix[i]);
                }

            else if (infix[i] == ')')
            {
                while (!empty(stackPtr) && peek(stackPtr) != '(')
                    {
                        postfix[++j] = pop(stackPtr);
                    }
                if (!empty(stackPtr) && peek(stackPtr) != '(')
                {
                    return 0;
                }
                else
                    {
                        pop(stackPtr);
                    }
            }
            else
            {
                while (!empty(stackPtr) && getOperatorPriority(infix[i]) <= getOperatorPriority(peek(stackPtr)))
                {
                    postfix[++j] = pop(stackPtr);

                }
                push(stackPtr, infix[i]);
            }
        }

        while (!empty(stackPtr)) {
            postfix[++j] = pop(stackPtr);
        }
        return postfix;
    }

    int elvaluate(char *infix) {

        int* postFix = (int*)malloc(sizeof(infix));
        struct stack_int *stackPtr = malloc(strlen(infix));
        initialize_int(stackPtr);
        if (!stackPtr)
            {
                return 0;
            }

        int d, k, result = 0;

        for (int i = 0; i < strlen(exp); i++)
            {
                printf("%c, ", infix[i]);
            }

        for (int i = 0 ; i < strlen(infix); i++) {
            if (infix[i] != 0) {
                k = -1;

                if (isdigit(infix[i])) {
                    push_int(stackPtr, convetToInt(infix[i]) );
                }

                if (isOperator(infix[i])) {
                    int b = pop_int(stackPtr);
                    int a = pop_int(stackPtr);

                    result = calculate(a, b, infix[i]);
                    push_int(stackPtr, result);
                }
            }
        }
        return result;
    }

    int main()
    {
            int c;
            char *str;

            while (strcmp(str = menu(), "exit") != 0) {

                if (isBalancedParenthesis(str)) {
                    char *postFix = malloc(sizeof(str));
                    postFix = convertToPostfix(str);
                    printf("The postfix of %s is:\n", str);

                    for (int i = 0; i <= strlen(postFix); i++) {
                        printf(" %c \n\n ", postFix[i]);
                    }
                    printf("Evaluation: %d \n", elvaluate(postFix));
                }
                else
                    printf("Imbalanced Parentheses\n");

            }

            free(str);
    }




    ///////////////////////////////////////////////////////////
    void initialize(struct stack* stackPtr) {
        stackPtr->top = -1;
    }
    char peek(struct stack* stackPtr) {
            char retval;
            if (empty(stackPtr)) {
                return EMPTY;
            }
            retval = stackPtr->items[stackPtr->top];

            return retval;
    }
    int push(struct stack* stackPtr, char value) {
            if (full(stackPtr)) {
                return 0;
            }
            stackPtr->items[stackPtr->top + 1] = value;
            (stackPtr->top)++;
        return 1;
    }
    char pop(struct stack* stackPtr) {
        char retval;
        if (empty(stackPtr))
            return EMPTY;
            retval = stackPtr->items[stackPtr->top];
            (stackPtr->top)--;

        return retval;
    }
    int top(struct stack* stackPtr) {

        if (empty(stackPtr))
            return EMPTY;

        return stackPtr->items[stackPtr->top];
    }

    int full(struct stack* stackPtr) {
        return (stackPtr->top == SIZE - 1);
    }

    int empty(struct stack* stackPtr) {
        return (stackPtr->top == -1);
    }
    void initialize_int(struct stack_int* stackPtr_int) {
        stackPtr_int->top_int = -1;
        }
    int full_int(struct stack_int* stackPtr_int) {
            return (stackPtr_int->top_int == SIZE - 1);
        }
        int empty_int(struct stack_int* stackPtr_int) {
            return (stackPtr_int->top_int == -1);
        }
        int top_int(struct stack_int* stackPtr_int) {
            if (empty_int(stackPtr_int))
                return EMPTY;

            return stackPtr_int->items_int[stackPtr_int->top_int];
        }
    int push_int(struct stack_int* stackPtr_int, int value) {

            if (full_int(stackPtr_int))
            {
                return 0;
            }
            stackPtr_int->items_int[stackPtr_int->top_int + 1] = value;
            (stackPtr_int->top_int)++;
            return 1;
        }
        int pop_int(struct stack_int* stackPtr_int) {
            int retval;
            if (empty_int(stackPtr_int)) return EMPTY;
            retval = stackPtr_int->items_int[stackPtr_int->top_int];
            (stackPtr_int->top_int)--;
            return retval;
        }
        int peek_int(struct stack_int* stackPtr_int) {
            int retval;
            if (empty_int(stackPtr_int)) {
                return EMPTY;
            }
            retval = stackPtr_int->items_int[stackPtr_int->top_int];

            return retval;
    }
