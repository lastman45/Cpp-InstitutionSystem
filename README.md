# Students Attendance System

A console-based C++ application for managing student enrollment and tracking daily attendance. The system supports two user roles — **Admin** and **Student** — with file-based persistent storage.

---

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running the Application](#running-the-application)
- [Usage](#usage)
  - [Main Menu](#main-menu)
  - [Admin Login](#admin-login)
  - [Student Login](#student-login)
- [Project Structure](#project-structure)
- [Data Storage](#data-storage)
- [Known Limitations & Bugs](#known-limitations--bugs)
- [Roadmap](#roadmap)
- [Contributing](#contributing)

---

## Features

### Admin
- Enroll new students with personal details (name, username, password, roll number, address, parent names)
- View a list of all currently enrolled students
- Delete individual students by roll number *(stub — not yet implemented)*
- Delete all students *(stub — not yet implemented)*
- Check attendance count of a student by roll number *(stub — not yet implemented)*
- Display a list of students with their attendance counts *(stub — not yet implemented)*

### Student
- Secure login with username and password
- Mark attendance for the current day *(stub — not yet implemented)*
- View personal attendance count *(stub — not yet implemented)*

---

## Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or later (e.g., `g++`, `clang++`, MSVC)
- Standard C++ libraries (included with most compilers)
- **Windows** is the primary target platform — the application uses `system("cls")` to clear the console. On Linux/macOS, replace `system("cls")` with `system("clear")` throughout the source.

### Compilation

Using `g++`:

```bash
g++ -std=c++11 -o StudentsAttendance StudentsAttendance.cpp
```

Using MSVC (Developer Command Prompt):

```bash
cl /EHsc StudentsAttendance.cpp
```

### Running the Application

```bash
./StudentsAttendance        # Linux/macOS
StudentsAttendance.exe      # Windows
```

---

## Usage

### Main Menu

```
 STUDENTS ATTENDANCE
1. Student Login
2. Admin Login
3. Exit
```

### Admin Login

**Default credentials:**
| Field    | Value  |
|----------|--------|
| Username | `admin` |
| Password | `pass` |

> ⚠️ The admin password is hardcoded in plain text. See [Known Limitations](#known-limitations--bugs).

Once logged in, the admin menu offers:

```
1. Enroll a Student
2. Delete all Students Enrolled
3. Delete a Student by Roll No.
4. Check List of Students Enrolled by Username
5. Check Present Count of Students by Roll No.
6. Get List of Students with Attendance count
7. Sign out
```

**Enrolling a student** prompts for:
- Full name
- Username
- Password
- Roll number
- Address
- Father's name
- Mother's name

The system prevents duplicate usernames.

### Student Login

Students log in with the username and password set during enrollment. After authentication:

```
1. Mark Attendance for Today
2. Count My Attendance
3. Logout
```

---

## Project Structure

```
StudentsAttendance.cpp      # Single-file source code
StudentDatabase.dat         # Generated at runtime — index of all enrolled students
<Username>.dat              # Generated per student — stores personal details
README.md
```

### Key Functions

| Function | Description |
|---|---|
| `main()` | Entry point; renders the main menu loop |
| `AdminSignin()` | Authenticates the admin |
| `AdminView()` | Admin menu and dispatch |
| `StudentSignin()` | Entry point for student login flow |
| `StudentView()` | Authenticates a student and shows their menu |
| `CheckStudentsCredentials()` | Verifies a student's username/password against `StudentDatabase.dat` |
| `EnrollStudent()` | Collects student info and writes to disk |
| `ListofStudentsEnrolled()` | Reads and prints all usernames from `StudentDatabase.dat` |
| `MarkMyAttendance()` | *(Stub)* Intended to record today's attendance |
| `CountMyAttendance()` | *(Stub)* Intended to count a student's total attendance |
| `DeleteStudentbyRollNo()` | *(Stub)* Intended to remove a student record |
| `DeleteAllStudents()` | *(Stub)* Intended to clear all student records |
| `DisplayStudentsPresent()` | *(Stub)* Intended to list students with attendance |
| `CheckPresentCountbyRollNo()` | *(Stub)* Intended to show attendance count by roll number |
| `Delay()` | Simulates a saving animation with a timed loop |

---

## Data Storage

The application uses plain text `.dat` files for persistence — no external database is required.

**`StudentDatabase.dat`** — One line per enrolled student, each line is the student's `.dat` filename:
```
alice.dat
bob.dat
```

**`<Username>.dat`** — One record per student (e.g., `alice.dat`):
```
Alice Johnson
alice
password123
CS-101
123 Main Street
John Johnson
Mary Johnson
```

> ⚠️ Passwords are stored in **plain text**. Do not use real passwords with this application.

---

## Known Limitations & Bugs

1. **Hardcoded admin credentials** — Username `admin` and password `pass` are embedded directly in the source code. There is no way to change them without recompiling.

2. **Plaintext password storage** — Both admin and student passwords are stored without any hashing or encryption.

3. **`EnrollStudent()` writes `Address` uninitialized** — The variable `Address` (a `std::string`) is declared but never assigned. `cin.getline()` reads into a separate `char add[100]` array that is never copied into `Address`. As a result, the address field in each student's `.dat` file will be empty.

4. **Several functions are stubs** — The following features are declared and menu-accessible but contain no real logic:
   - Mark attendance
   - Count attendance
   - Delete student by roll number
   - Delete all students
   - Display students present
   - Check present count by roll number

5. **`system("cls")` is Windows-only** — The application will not clear the screen correctly on Linux or macOS without modification.

6. **`ListofStudentsEnrolled()` strips only the last 4 characters** — This assumes every entry ends in `.dat`. If the database file is manually edited or corrupted, this will produce incorrect output.

7. **No input validation** — Fields like roll number and password accept any input, including empty strings and whitespace.

---

## Roadmap

Suggested improvements for future development:

- [ ] Implement `MarkMyAttendance()` — write a dated entry to the student's record file
- [ ] Implement `CountMyAttendance()` — count date entries in the student's record file
- [ ] Implement `DeleteStudentbyRollNo()` — search by roll number and remove the matching record
- [ ] Implement `DeleteAllStudents()` — clear `StudentDatabase.dat` and remove all individual `.dat` files
- [ ] Implement `DisplayStudentsPresent()` and `CheckPresentCountbyRollNo()`
- [ ] Fix the uninitialized `Address` bug in `EnrollStudent()`
- [ ] Hash passwords before storage (e.g., using SHA-256)
- [ ] Store admin credentials securely or load them from a config file
- [ ] Replace `system("cls")` with a cross-platform alternative
- [ ] Add input validation for all user-facing fields
- [ ] Migrate from `.dat` files to a structured format (SQLite, JSON, or CSV)

---

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature-name`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push to the branch: `git push origin feature/your-feature-name`
5. Open a pull request

Please document any new functions and update this README if you add or change features.
