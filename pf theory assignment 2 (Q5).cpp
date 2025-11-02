#include <stdio.h>
#include <string.h>


void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


char toggleBits(char ch) {
    
    ch = ch ^ (1 << 1);  
    ch = ch ^ (1 << 4);  
    return ch;
}


void encode(char message[]) {
    reverseString(message);  
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);  
    }
}


void decode(char message[]) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);  
    }
    reverseString(message);  
}

int main() {
    char message[200];
    int choice;

    printf(" TCS Message Encoder/Decoder\n");
    printf("1. Encode Message\n");
    printf("2. Decode Message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); 

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; 

    if (choice == 1) {
        encode(message);
        printf("\nEncoded Message: %s\n", message);
    } else if (choice == 2) {
        decode(message);
        printf("\nDecoded Message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
