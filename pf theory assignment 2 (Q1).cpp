#include <stdio.h>
#include <string.h>

// ---------- Function Prototypes ----------
void addNewBook(long int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(long int isbns[], char titles[][50], int quantities[], int count);
void generateLowStockReport(long int isbns[], char titles[][50], float prices[], int quantities[], int count);

// ---------- Main Function ----------
int main() {
    long int isbns[200] = {
        978000000001, 978000000002, 978000000003, 978000000004, 978000000005,
        978000000006, 978000000007, 978000000008, 978000000009, 978000000010,
        978000000011, 978000000012, 978000000013, 978000000014, 978000000015,
        978000000016, 978000000017, 978000000018, 978000000019, 978000000020,
        978000000021, 978000000022, 978000000023, 978000000024, 978000000025,
        978000000026, 978000000027, 978000000028, 978000000029, 978000000030,
        978000000031, 978000000032, 978000000033, 978000000034, 978000000035,
        978000000036, 978000000037, 978000000038, 978000000039, 978000000040,
        978000000041, 978000000042, 978000000043, 978000000044, 978000000045,
        978000000046, 978000000047, 978000000048, 978000000049, 978000000050,
        978000000051, 978000000052, 978000000053, 978000000054, 978000000055,
        978000000056, 978000000057, 978000000058, 978000000059, 978000000060,
        978000000061, 978000000062, 978000000063, 978000000064, 978000000065,
        978000000066, 978000000067, 978000000068, 978000000069, 978000000070,
        978000000071, 978000000072, 978000000073, 978000000074, 978000000075,
        978000000076, 978000000077, 978000000078, 978000000079, 978000000080,
        978000000081, 978000000082, 978000000083, 978000000084, 978000000085,
        978000000086, 978000000087, 978000000088, 978000000089, 978000000090,
        978000000091, 978000000092, 978000000093, 978000000094, 978000000095,
        978000000096, 978000000097, 978000000098, 978000000099, 978000000100
    };

    char titles[200][50] = {
        "Harry Potter", "The Alchemist", "Atomic Habits", "The Great Gatsby", "1984",
        "To Kill a Mockingbird", "Pride and Prejudice", "Moby Dick", "War and Peace", "Jane Eyre",
        "The Hobbit", "The Catcher in the Rye", "Animal Farm", "Crime and Punishment", "Brave New World",
        "Lord of the Flies", "Fahrenheit 451", "The Odyssey", "Wuthering Heights", "The Kite Runner",
        "The Book Thief", "The Da Vinci Code", "Twilight", "Dune", "The Hunger Games",
        "Percy Jackson", "The Fault in Our Stars", "Gone Girl", "It", "The Shining",
        "Misery", "Carrie", "The Stand", "Inferno", "Angels and Demons",
        "Digital Fortress", "Deception Point", "A Game of Thrones", "A Clash of Kings", "A Storm of Swords",
        "A Feast for Crows", "A Dance with Dragons", "The Witcher", "Blood of Elves", "Time of Contempt",
        "Baptism of Fire", "The Lady of the Lake", "Sword of Destiny", "The Last Wish", "The Silmarillion",
        "The Fellowship of the Ring", "The Two Towers", "The Return of the King", "The Chronicles of Narnia", "The Lion, the Witch and the Wardrobe",
        "Prince Caspian", "The Voyage of the Dawn Treader", "Silver Chair", "The Last Battle", "Eragon",
        "Eldest", "Brisingr", "Inheritance", "The Maze Runner", "Scorch Trials",
        "Death Cure", "Kill Order", "Fever Code", "Divergent", "Insurgent",
        "Allegiant", "Four", "The Host", "Life of Pi", "Memoirs of a Geisha",
        "The Girl on the Train", "Before We Were Strangers", "Eleanor Oliphant is Completely Fine", "The Night Circus", "Circe",
        "Song of Achilles", "The Midnight Library", "The Invisible Life of Addie LaRue", "Project Hail Mary", "Artemis",
        "Ready Player One", "Ready Player Two", "Ender’s Game", "Speaker for the Dead", "Shadow of the Hegemon",
        "The Martian", "Contact", "The Time Machine", "The War of the Worlds", "The Invisible Man",
        "Dracula", "Frankenstein", "Sherlock Holmes", "The Sign of Four", "A Study in Scarlet"
    };

    float prices[200] = {
        999.50, 850.00, 1200.75, 650.00, 700.25,
        750.00, 600.00, 950.00, 880.00, 720.00,
        1100.00, 680.00, 500.00, 940.00, 870.50,
        620.00, 540.00, 730.00, 760.00, 880.00,
        890.00, 930.00, 610.00, 980.00, 750.00,
        700.00, 830.00, 950.00, 860.00, 940.00,
        910.00, 880.00, 970.00, 990.00, 950.00,
        910.00, 970.00, 1200.00, 1250.00, 1300.00,
        1400.00, 1350.00, 800.00, 780.00, 760.00,
        740.00, 720.00, 710.00, 700.00, 1000.00,
        1500.00, 1550.00, 1600.00, 1650.00, 1700.00,
        1750.00, 1800.00, 1850.00, 1900.00, 1950.00,
        2000.00, 2050.00, 2100.00, 2150.00, 2200.00,
        2250.00, 2300.00, 2350.00, 2400.00, 2450.00,
        2500.00, 2550.00, 2600.00, 2650.00, 2700.00,
        2750.00, 2800.00, 2850.00, 2900.00, 2950.00,
        3000.00, 3050.00, 3100.00, 3150.00, 3200.00,
        3250.00, 3300.00, 3350.00, 3400.00, 3450.00,
        3500.00, 3550.00, 3600.00, 3650.00, 3700.00,
        3750.00, 3800.00, 3850.00, 3900.00, 3950.00
    };

    int quantities[200] = {
        9, 10, 11, 12, 13, 14, 15, 9, 10, 11,
        12, 13, 14, 15, 9, 10, 11, 12, 13, 14,
        15, 9, 10, 11, 12, 13, 14, 15, 9, 10,
        11, 12, 13, 14, 15, 9, 10, 11, 12, 13,
        14, 15, 9, 10, 11, 12, 13, 14, 15, 9,
        10, 11, 12, 13, 14, 15, 9, 10, 11, 12,
        13, 14, 15, 9, 10, 11, 12, 13, 14, 15,
        9, 10, 11, 12, 13, 14, 15, 9, 10, 11,
        12, 13, 14, 15, 9, 10, 11, 12, 13, 14,
        15, 9, 10, 11, 12, 13, 14, 15, 9, 10
    };

    int count = 100;
    int choice;

    do {
        printf("\n===== ?? Liberty Books Inventory Menu =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, titles, quantities, count);
                break;
            case 3:
                generateLowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting... ??\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

// ---------- Add New Book ----------
void addNewBook(long int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    long int new_isbn;
    int duplicate = 0;

    printf("Enter new book ISBN: ");
    scanf("%ld", &new_isbn);

    // Check for duplicate ISBN
    for (int i = 0; i < *count; i++) {
        if (isbns[i] == new_isbn) {
            printf("? ISBN already exists. Book not added.\n");
            return;
        }
    }

    isbns[*count] = new_isbn;
    printf("Enter title: ");
    scanf(" %[^\n]", titles[*count]);
    printf("Enter price: ");
    scanf("%f", &prices[*count]);
    printf("Enter quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("? Book added successfully! Total books: %d\n", *count);
}

// ---------- Process a Sale ----------
void processSale(long int isbns[], char titles[][50], int quantities[], int count) {
    long int isbn;
    int copies;
    int found = 0;

    printf("Enter ISBN of the sold book: ");
    scanf("%ld", &isbn);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &copies);

            if (copies <= quantities[i]) {
                quantities[i] -= copies;
                printf("? Sale successful! Remaining stock of '%s': %d\n", titles[i], quantities[i]);
            } else {
                printf("? Not enough stock. Available: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (!found)
        printf("? Book with given ISBN not found.\n");
}

// ---------- Generate Low-Stock Report ----------
void generateLowStockReport(long int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    printf("\n===== ?? Low-Stock Report (Less than 5 units) =====\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %ld | Title: %-30s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("? All books have sufficient stock.\n");
}
