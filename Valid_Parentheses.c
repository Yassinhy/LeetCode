// I used the Stack data structure and functions I made before
typedef struct
{
    int capacity; // max number of items that can be stored
    char* collection; // array of the chars that are currently stacked
    int size; // number of items stored
} Stack;

// Prototypes:
Stack* create_stack(int capacity);
bool destroy_stack(Stack* stack);
bool stack_is_full(Stack* stack);
bool stack_is_empty(Stack* stack);
bool pop(Stack* stack, char* value);
bool push(Stack* stack, char item);
bool peek(Stack* stack, char* value);


bool isValid(char* s) {
    int length = strlen(s);

    Stack* stack = create_stack(length);
    for (int i = 0; i < length; i++)
    {
        char current = s[i];
        if (current == '(' || current == '[' || current == '{' )
        {
            push(stack, s[i]);
        }
        else
        {
            char top;
            if (pop(stack, &top))
            {
                destroy_stack(stack);
                return false;
            }
                if ((top == '(' && current != ')') || 
                (top == '[' && current != ']') ||
                (top == '{' && current != '}'))
                {
                    destroy_stack (stack);
                    return false;
                }
        }
    }
    return stack_is_empty(stack);

}

//create a stack
Stack* create_stack(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;
    stack->collection = malloc(capacity * sizeof(char));
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

// Correctly free a stack
bool destroy_stack(Stack* stack)
{
    if (stack == NULL) {
        return false;
    }
    free(stack->collection);
    free(stack);
    return true;
}

// Check if a stack is full
bool stack_is_full(Stack* stack)
{
    return stack->size == stack->capacity;
}

// Check if a stack is empty
bool stack_is_empty(Stack* stack)
{
    return stack->size == 0;
}

// Remove an item from the stack and store it in the "value" pointer
// Returns true if failed to pop
bool pop(Stack* stack, char* value)
{
    if (stack_is_empty(stack)) return true;
    stack->size--;
    *value = stack->collection[stack->size];
    return false;
}

// Add an item to a stack
bool push(Stack* stack, char item)
{
    if (stack_is_full(stack)) return true;
    stack->collection[stack->size] = item;
    stack->size++;
    return false;
}

// See what is on the top of the stack
bool peek(Stack* stack, char* value)
{
    if (stack_is_empty(stack)) return true;
    *value = stack->collection[stack->size - 1];
    return false;
}
