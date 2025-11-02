#include <stdio.h>
#include <string.h>

#define SIZE 4


int product_code[SIZE] = {1, 2, 3, 4};
int quantity_in_stock[SIZE] = {50, 10, 20, 8};
int price_per_product[SIZE] = {100, 200, 300, 150};


int cart_quantity[SIZE] = {0};


char customer_name[50];
long long customer_cnic;


void customerInformation();
void displayInventory();
void updateInventory(int index, int qty);
void addItemToCart();
void displayTotalBill();
void showInvoice();

int main() {
    int choice;
    printf(" SUPERMARKET MANAGEMENT SYSTEM \n");
    do {
        
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInformation();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addItemToCart();
                break;
            case 4:
                displayTotalBill();
                break;
            case 5:
                showInvoice();
                break;
            case 6:
                printf("\nExiting system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


void customerInformation() {
    printf("\nEnter customer name: ");
    scanf(" %[^\n]", customer_name);
    printf("Enter customer CNIC number: ");
    scanf("%lld", &customer_cnic);
    printf("\nCustomer information recorded successfully.\n");
}


void displayInventory() {
    printf("\n---------- INVENTORY ----------\n");
    printf("Product Code\tQuantity\tPrice\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%03d\t\t%d\t\t%d\n", product_code[i], quantity_in_stock[i], price_per_product[i]);
    }
    printf("---------------------------------\n");
}

/
void updateInventory(int index, int qty) {
    quantity_in_stock[index] -= qty;
}


void addItemToCart() {
    int code, qty, found = 0;
    printf("\nEnter product code to add to cart: ");
    scanf("%d", &code);
    for (int i = 0; i < SIZE; i++) {
        if (product_code[i] == code) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (qty <= quantity_in_stock[i]) {
                cart_quantity[i] += qty;
                updateInventory(i, qty);
                printf("Item added to cart successfully!\n");
            } else {
                printf("Sorry, only %d items in stock!\n", quantity_in_stock[i]);
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid product code!\n");
    }
}


void displayTotalBill() {
    float total = 0, discounted_total = 0;
    char promo[20];

    for (int i = 0; i < SIZE; i++) {
        total += cart_quantity[i] * price_per_product[i];
    }

    printf("\nYour total bill is: %.2f\n", total);
    printf("Do you have a promo code? (Enter code or 'no'): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        discounted_total = total * 0.75; 
        printf("Promo applied! You got 25%% discount.\n");
        printf("Discounted total: %.2f\n", discounted_total);
    } else {
        printf("No promo applied. Total: %.2f\n", total);
    }
}


void showInvoice() {
    float total = 0, discounted_total = 0;
    printf("\n------------- INVOICE -------------\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Customer CNIC: %lld\n", customer_cnic);
    printf("----------------------------------\n");
    printf("Code\tQty\tPrice\tSubtotal\n");
    for (int i = 0; i < SIZE; i++) {
        if (cart_quantity[i] > 0) {
            float subtotal = cart_quantity[i] * price_per_product[i];
            printf("%03d\t%d\t%d\t%.2f\n", product_code[i], cart_quantity[i], price_per_product[i], subtotal);
            total += subtotal;
        }
    }
    discounted_total = total * 0.75;
    printf("----------------------------------\n");
    printf("Total (no discount): %.2f\n", total);
    printf("Total (with 25%% discount): %.2f\n", discounted_total);
    printf("----------------------------------\n");
    printf("Thank you for shopping!\n");
}
