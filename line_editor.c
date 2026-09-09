#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int count = 0;

/* Function Prototypes */
void insertLine();
void deleteLine();
void displayDocument();
void saveDocument();
void loadDocument();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== SIMPLE LINE EDITOR =====\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Save Document\n");
        printf("5. Load Document\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Remove newline left by scanf

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                saveDocument();
                break;

            case 5:
                loadDocument();
                break;

            case 6:
                printf("Exiting Line Editor...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1 to 6.\n");
        }
    }

    return 0;
}

/* Insert a new line */
void insertLine()
{
    int lineNumber;
    char text[MAX_LENGTH];

    if (count >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    printf("Enter line number (1 to %d): ", count + 1);
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > count + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    /* Shift lines downward */
    for (int i = count; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[lineNumber - 1], text);
    count++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine()
{
    int lineNumber;

    if (count == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > count)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Shift lines upward */
    for (int i = lineNumber - 1; i < count - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    count--;

    printf("Line deleted successfully.\n");
}

/* Display the document */
void displayDocument()
{
    if (count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n===== DOCUMENT =====\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

/* Save document to a file */
void saveDocument()
{
    FILE *file;

    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not save the document.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}

/* Load document from a file */
void loadDocument()
{
    FILE *file;

    file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("Error: Document file not found.\n");
        return;
    }

    count = 0;

    while (count < MAX_LINES &&
           fgets(lines[count], MAX_LENGTH, file) != NULL)
    {
        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}