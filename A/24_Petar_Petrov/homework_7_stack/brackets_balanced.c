#include<stdio.h>
#include<stdlib.h>

struct stack_t
{
    int top,size;
    char *data;
};

void stack_init(struct stack_t *);
void stack_destroy(struct stack_t *);
char *brackets_input(char input[20]);
int stack_get_size(struct stack_t);
void stack_resize(struct stack_t *);
void stack_push_back(struct stack_t *,char bracket_string[20],int counter);
int stack_pop_back(struct stack_t *,char bracket_string[20],int counter);
void stack_copy(struct stack_t *from, struct stack_t *to);
int check_brackets_balance(char brackets_string[20],struct stack_t *);

int main()
{
    struct stack_t brackets_stack;
    char brackets_string[20];
    stack_init(&brackets_stack);
    brackets_input(brackets_string);
    printf("%d\n",check_brackets_balance(brackets_string,&brackets_stack));
    stack_destroy(&brackets_stack);
    return 0;
}

void stack_init(struct stack_t *br_stack)
{
    br_stack->size = 5;
    br_stack->top = 0;
    br_stack->data = (char*) malloc(br_stack->size * sizeof(char));
}

void stack_destroy(struct stack_t *br_stack)
{
    if(br_stack->size != 0)
    {        
        free(br_stack->data);
        br_stack->size = 0;
        br_stack->top = 0;
        return;
    }
    else
    {
        printf("Stack is already freed!\n");
        return;
    }
}

char *brackets_input(char input[20])
{
    printf("Please input a string of brackets:\n");
    scanf("%s",input);
    return input;
}

int stack_get_size(struct stack_t br_stack) 
{
    return br_stack.top;
}

void stack_push_back(struct stack_t *br_stack,char brackets_string[20],int counter) 
{
    if(br_stack->top < br_stack->size) 
    {
        br_stack->data[br_stack->top++] = brackets_string[counter];
    }
    else 
    {
        stack_resize(br_stack);
        br_stack->data[br_stack->top++] = brackets_string[counter];
    }
}

int stack_pop_back(struct stack_t *br_stack,char bracket_string[20],int counter) {
    if(br_stack->top != 0) 
    {
        if((bracket_string[counter] == ')' && br_stack->data[br_stack->top-1] == '(') || (bracket_string[counter] == '}' && br_stack->data[br_stack->top-1] == '{') || (bracket_string[counter] == ']' && br_stack->data[br_stack->top-1] == '['))
        {
            --br_stack->top;
            stack_resize(br_stack);
            return br_stack->data[br_stack->top];
        }
        else
        {
            return -1; //same
        }
    }
    else 
    {
        return -1; //return -1 for invalid bracket expression
    }
}

void stack_resize(struct stack_t *br_stack) 
{
    char *new_data;
    int new_size,counter;
    if(br_stack->top == br_stack->size)
    {
        new_size = br_stack->size * 2;
        new_data = (char*) malloc(new_size * sizeof(char));
        for(counter = 0; counter < br_stack->size; counter++)
        {
            new_data[counter] = br_stack->data[counter];
        }
        free(br_stack->data);
        br_stack->data = new_data;
        br_stack->size = new_size;
    }
    else if(br_stack->top < (br_stack->size)/2)
    {
        br_stack->size /= 2;
        new_data = (char*) malloc(br_stack->size * sizeof(char));
        for(counter = 0; counter < br_stack->size; counter++)
        {
            new_data[counter] = br_stack->data[counter];
        }
        free(br_stack->data);
        br_stack->data = new_data;
    }
}

void stack_copy(struct stack_t *from, struct stack_t *to)
{
    int counter;
    to->size = from->size; // initializes the duplicate stack
    to->top = 0; // same
    to->data = (char*) malloc(to->size * sizeof(char)); // same
    for(counter = 0; counter < from->size; counter++)
    {
        to->data[counter] = from->data[counter]; // transferring values  from original to duplicate stack
    }
}

int check_brackets_balance(char bracket_string[20],struct stack_t *br_stack)
{
    int counter;
    for(counter = 0; bracket_string[counter] != '\0'; counter++)
    {
        if(bracket_string[counter] == '(' 
         || bracket_string[counter] == '{' 
         || bracket_string[counter] == '[')
        {    
           stack_push_back(br_stack,bracket_string,counter); 
        }
        else if(bracket_string[counter] == ')' 
         || bracket_string[counter] == '}' 
         || bracket_string[counter] == ']')
        {
            if(stack_pop_back(br_stack,bracket_string,counter) == -1)
            {
                return -1;
            }
        }
    }
    if(br_stack->top == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
