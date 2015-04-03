#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define EXPRESSION_SIZE 50
#define INITIAL_STACK_SIZE 5

struct stack_t {
    int size,top;
    int *data;
};

char *string_input(char string[EXPRESSION_SIZE]);
void stack_init(struct stack_t *);
void stack_destroy(struct stack_t *);
int stack_get_size(struct stack_t *);
void stack_resize(struct stack_t *);
void stack_push_back(struct stack_t *,int value);
int stack_pop_back(struct stack_t *);
void stack_copy(struct stack_t *from, struct stack_t *to);

int calculation(struct stack_t *,char exp_string[EXPRESSION_SIZE]);

int main()
{
    struct stack_t operand_stack;
    char math_expression[EXPRESSION_SIZE];
    int result;
    //fgets(math_expression, EXPRESSION_SIZE, stdin);
    string_input(math_expression);
    stack_init(&operand_stack);
    result = calculation(&operand_stack,math_expression);
    if(result == INT_MIN)
    {
        printf("Insufficient values entered!\n");
    }
    else if(result == INT_MAX)
    {
        printf("Too many values entered!\n");
    }
    else
    {
        printf("%d\n",result);
    }
    stack_destroy(&operand_stack);
    return 0;
}

char *string_input(char string[EXPRESSION_SIZE])
{
    printf("Please input a mathematical expression:\n");
    scanf("%s",string);
    return string;
}

void stack_init(struct stack_t *stack)
{
    stack->size = INITIAL_STACK_SIZE;
    stack->top = 0;
    stack->data = (int*) malloc(stack->size * sizeof(int));
}

void stack_destroy(struct stack_t *stack)
{
    free(stack->data);
    stack->size = 0;
    stack->top = 0;
}

int stack_get_size(struct stack_t *stack)
{
    return stack->top;
}

void stack_push_back(struct stack_t *stack,int value) 
{
    if(stack->top < stack->size) 
    {
        stack->data[stack->top++] = value;
    }
    else 
    {
        stack_resize(stack);
        stack->data[stack->top++] = value;
    }
}

int stack_pop_back(struct stack_t *stack) 
{
    if(stack->top != 0) 
    {
        --stack->top;
        if(stack->size > INITIAL_STACK_SIZE)
        {
            stack_resize(stack);
        }
        return stack->data[stack->top];
    }
    else 
    {
        printf("Stack is empty!\n");
        return INT_MIN; //returns the smallest value of int for empty stack
    }
}

void stack_resize(struct stack_t *stackk) 
{
    int *new_data,new_size,counter;
    if(stackk->top == stackk->size)
    {
        new_size = stackk->size * 2;
        new_data = (int*) malloc(new_size * sizeof(int));
        for(counter = 0; counter < stackk->size; counter++)
        {   
            new_data[counter] = stackk->data[counter];
        }
        free(stackk->data);
        stackk->data = new_data;
        stackk->size = new_size;
    }
    else if(stackk->top < (stackk->size)/2)
    {
        stackk->size /= 2;
        new_data = (int*) malloc(stackk->size * sizeof(int));
        for(counter = 0; counter < stackk->size; counter++)
        {
            new_data[counter] = stackk->data[counter];
        }
        free(stackk->data);
        stackk->data = new_data;
    }
}

void stack_copy(struct stack_t *from, struct stack_t *to)
{
    to->size = from->size; // initializes the duplicate stack
    to->top = 0; // same
    to->data = (int*) malloc(to->size * sizeof(int)); // same
    for(from->top = 0; from->top < from->size; from->top++, to->top++)
    {
        to->data[to->top] = from->data[from->top]; // transferring values from original to duplicate stack
    }
}

int calculation(struct stack_t *stack,char exp_string[EXPRESSION_SIZE])
{
    int counter, value, result, first_value, second_value;
    for(counter = 0; exp_string[counter] != '\0'; counter++)
    {
        if(exp_string[counter] >= '0' && exp_string[counter] <= '9') //checks if the string element is a value
        {
            value = exp_string[counter] - '0';
            stack_push_back(stack,value);
        }
        else if(exp_string[counter] == '*' || exp_string[counter] == '/' || exp_string[counter] == '+' || exp_string[counter] == '-')
        {
            if(stack_get_size(stack) < 2)
            {
                return INT_MIN;
            }
            else
            {
                second_value = stack_pop_back(stack);
                first_value = stack_pop_back(stack);
                switch(exp_string[counter])
                {
                    case '*' :
                        result = first_value * second_value;
                        break;
                        
                    case '/' :
                        result = first_value / second_value;
                        break;
                        
                    case '+' :
                        result = first_value + second_value;
                        break;
                        
                    case '-' :
                        result = first_value - second_value;
                        break;   
                }
                stack_push_back(stack,result);
            }
        }
    }
    if(stack_get_size(stack) == 1)
    {
        return result;
    }
    else
    {
        return INT_MAX;
    }
}
