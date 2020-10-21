typedef struct {
    int *data;
    size_t size;
    size_t top;
} Stack_t;

Stack_t* createStack();
void deleteStack(Stack_t **stack);

void push(Stack_t *stack, int value);
int pop(Stack_t *stack);
int peek(const Stack_t *stack);