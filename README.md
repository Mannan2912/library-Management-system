# Library & Student Record Management System

A modular C++ console application designed to handle book inventories, student records, and transaction logs (book issuance and returns) using persistent binary file storage (`.dat`).

---

## How It Works

1. **Authentication:**  
   The program reads valid credentials directly from `pass.txt` to verify login access with a maximum of 3 attempts before exit.

2. **Input:**  
   Takes console inputs for student records (ID, Class, Name), book records (ID, Name), and transaction details (Student ID, Book ID, issue/return dates). Includes custom input validation (`checkint`) to catch non-integer inputs gracefully.

3. **Processing & Storage:**  
   - Employs binary file streams (`ifstream`/`ofstream` with `ios::binary`) to serialize and write objects directly to disk (`student2.dat`, `Book.dat`, `issue.dat`).
   - Implements temporary file swap routines (`copy.dat` / `copy2.dat`) to safely update and delete binary records.
   - Enforces relational consistency: A book cannot be issued unless both the Student ID and Book ID exist in their respective database files.

4. **Output:**  
   Displays formatted console tables using `<iomanip>` (`setw`) alongside dynamic console clearing and loading indicators.

---

## File Structure

- `project.cpp`: Main driver handling credential verification and system menus.
- `header2.h`: Student record class, data validation, loading animations, and student CRUD operations.
- `Books.h`: Book record class and inventory CRUD routines.
- `Issue.h`: Issue transaction tracking and relational student-book verification.
- `pass.txt`: Plaintext credential file for authentication.

---

## How to Run
## How to Run

1. Make sure `project.exe` and `pass.txt` are in the same folder.
2. Open `project.exe` to run the program.

### Default Login Credentials
- **Username:** `admin123`
- **Password:** `admin@123`
