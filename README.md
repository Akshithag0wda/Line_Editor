# Simple Line Editor in C

## Team Members

- Member 1: Akshitha N
- Member 2: Amrita Jyoti
- Member 3: Ananya Singh

## Problem Statement

A line editor is a simple text editor that works with text one line at a time.
Our project is a command-line line editor written in C. It allows the user to
create, view, modify, save, and load a small text document through the terminal.

## Data Structure

We use an array of strings to store the document lines.

```c
char lines[100][200];

## Features Implemented

- **Insert Line** – Adds a new line of text at a specified line number.
- **Delete Line** – Removes a line from the document by its line number.
- **Display Document** – Prints all current lines with their line numbers.
- **Save Document** – Writes the current in-memory document to `document.txt`.
- **Load Document** – Reads an existing `document.txt` back into memory.

## Compilation and Execution Instructions

Compile with GCC:
```bash
gcc line_editor.c -o line_editor
