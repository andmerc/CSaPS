#include <stdlib.h>
#include "stack.h"

#define INIT_SIZE 8
#define MULTIPLIER 2

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

Stack_t* createStack()
{
    Stack_t *out = NULL;
    out = malloc(sizeof(Stack_t));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(int));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}
 
void deleteStack(Stack_t **stack)
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(Stack_t *stack)
{
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}

void push(Stack_t *stack, int value)
{
    if (stack->top >= stack->size) {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

int pop(Stack_t *stack)
{
    if (stack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    return stack->data[stack->top];
}

int peek(const Stack_t *stack)
{
    if (stack->top <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top - 1];
}