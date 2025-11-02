#include <stdio.h>


void updateSector(int grid[3][3]);
void querySector(int grid[3][3]);
void runDiagnostic(int grid[3][3]);
void displayGrid(int grid[3][3]);
void showStatus(int status);

int main() {
    int grid[3][3] = {0};  
    int choice;

    printf(" IESCO Power Grid Monitoring System \n");

    do {
       
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Display Grid Values\n");
        printf("5. Exit\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            updateSector(grid);
        else if (choice == 2)
            querySector(grid);
        else if (choice == 3)
            runDiagnostic(grid);
        else if (choice == 4)
            displayGrid(grid);
        else if (choice == 5)
            printf("Exiting system... Goodbye!\n");
        else
            printf("Invalid choice! Try again.\n");

    } while (choice != 5);

    return 0;
}


void updateSector(int grid[3][3]) {
    int row, col, flag, value;

    printf("\nEnter sector position (row and column 0-2): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nSelect which status to change:\n");
    printf("0. Power (1 = ON, 0 = OFF)\n");
    printf("1. Overload (1 = Overloaded, 0 = Normal)\n");
    printf("2. Maintenance (1 = Required, 0 = Not Required)\n");
    printf("Enter your choice: ");
    scanf("%d", &flag);

    if (flag < 0 || flag > 2) {
        printf("Invalid flag number!\n");
        return;
    }

    printf("Enter new value (0 or 1): ");
    scanf("%d", &value);

    if (value != 0 && value != 1) {
        printf("Invalid value! Enter 0 or 1 only.\n");
        return;
    }

   
    if (value == 1)
        grid[row][col] = grid[row][col] | (1 << flag);
    else
        grid[row][col] = grid[row][col] & (~(1 << flag));

    printf("Sector (%d,%d) updated successfully!\n", row, col);
}


void querySector(int grid[3][3]) {
    int row, col, status;

    printf("\nEnter sector position (row and column 0-2): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
        return;
    }

    status = grid[row][col];
    printf("\nStatus of Sector (%d,%d):\n", row, col);
    showStatus(status);
}


void showStatus(int status) {
   
    if (status & (1 << 0))
        printf("Power Status        : ON\n");
    else
        printf("Power Status        : OFF\n");

    
    if (status & (1 << 1))
        printf("Overload Warning    : Overloaded\n");
    else
        printf("Overload Warning    : Normal\n");

    
    if (status & (1 << 2))
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}


void runDiagnostic(int grid[3][3]) {
    int i, j;
    int powerOn = 0, overloaded = 0, maintenance = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int status = grid[i][j];
            if (status & (1 << 0)) powerOn++;
            if (status & (1 << 1)) overloaded++;
            if (status & (1 << 2)) maintenance++;
        }
    }

    printf("\n SYSTEM DIAGNOSTIC REPORT\n");
    printf("Total sectors             : %d\n", 3 * 3);
    printf("Power ON sectors          : %d\n", powerOn);
    printf("Overloaded sectors        : %d\n", overloaded);
    printf("Under Maintenance sectors : %d\n", maintenance);
    
}


void displayGrid(int grid[3][3]) {
    int i, j;
    printf("\nCurrent Grid (integer values):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%3d ", grid[i][j]);
        }
        printf("\n");
    }
}
