#include <stdio.h>


void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[100];    
    int top = -1;     
    int maxSize;       
    int choice;       

   
    printf("        STACK IMPLEMENTATION        \n");
   

    
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

    do {
       
       
        printf("1. PUSH (Insert element)\n");
        printf("2. POP (Remove element)\n");
        printf("3. PEEK (View top element)\n");
        printf("4. DISPLAY (Show all elements)\n");
        printf("5. EXIT\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
        if (choice == 1)
            push(stack, &top, maxSize);
        else if (choice == 2)
            pop(stack, &top);
        else if (choice == 3)
            peek(stack, top);
        else if (choice == 4)
            display(stack, top);
        else if (choice == 5)
            printf("\nExiting program... Thank you!\n");
        else
            printf("\nInvalid choice! Please try again.\n");

    } while (choice != 5);

    return 0;
}


void push(int stack[], int *top, int maxSize) {
    int value;

    
    if (*top == maxSize - 1) {
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);

        *top = *top + 1;     
        stack[*top] = value; 
        printf("%d has been pushed onto the stack.\n", value);
    }
}


void pop(int stack[], int *top) {
    
    if (*top == -1) {
        printf("\nStack Underflow! No elements to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[*top]);
        *top = *top - 1; 
    }
}


void peek(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is empty! Nothing to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is empty! Nothing to display.\n");
    } else {
        printf("\nCurrent Stack Elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
