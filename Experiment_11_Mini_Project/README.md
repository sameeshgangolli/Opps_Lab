# Student Management System (Mini Project)

A simple C++ project developed for the Object-Oriented Programming (OOPS) practical curriculum.

## Overview
The Student Management System is a console application that manages basic student records. It allows adding, viewing, searching, and deleting student details, and saves records into a CSV file (`students_db.csv`).

## Features
- **Add Student**: Insert new student records (Roll No, Name, Department, Marks).
- **Display Records**: View all saved student details.
- **Search**: Search for a student using their Roll Number.
- **Delete**: Remove a student record from the list.
- **File Storage**: Saves records to a CSV file and loads them back on program startup.

## OOPS Concepts Used
- **Classes and Objects**: Used `Student` class to store student data and `StudentManager` class to handle operations.
- **Encapsulation**: Private data members with public member functions.
- **Vectors**: Used `std::vector` for dynamic storage of student objects.
- **File Handling**: Used `ifstream` and `ofstream` to save and read CSV files.

## Compilation and Execution
```bash
g++ main.cpp -o main.exe
.\main.exe
```
