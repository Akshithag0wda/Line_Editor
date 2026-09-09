# Line Editor Help

## Available Options

### 1. Insert Line
Adds a new line at the selected line number.

Example:
Enter your choice: 1
Enter line number: 1
Enter text: Hello

### 2. Delete Line
Deletes a line using its line number.

Example:
Enter your choice: 2
Enter line number to delete: 1

### 3. Display Document
Displays all the lines with their line numbers.

Example:
Enter your choice: 3

Output:
1: Hello
2: Welcome

### 4. Save Document
Saves the current document into `document.txt`.

Example:
Enter your choice: 4

Output:
Document saved successfully.

### 5. Load Document
Loads the saved document from `document.txt`.

Example:
Enter your choice: 5

Output:
Document loaded successfully.

### 6. Exit
Exits the Line Editor.

Example:
Enter your choice: 6

Output:
Exiting Line Editor...

## Error Handling

- Invalid choice → Displays an error message.
- Invalid line number → Displays an error message.
- Delete from an empty document → Displays an error message.
- Document full → Displays an error message.
- File not found while loading → Displays an error message.
- File cannot be opened while saving → Displays an error message.