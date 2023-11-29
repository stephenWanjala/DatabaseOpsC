# C++ Oracle Database Connection

This C++ program demonstrates how to connect to an Oracle database, process multiple rows from a query result, and handle multi-statement transactions. It includes the creation of a Users and Transactions table in the database and seeding them with sample data.

## Technologies Used

- C++ (Code::Blocks IDE)
- Oracle Database
- Oracle ODBC Driver

## Installation

1. **Install Oracle Database:**
   - Download and install Oracle Database on your system.
   - Follow the installation guide provided by Oracle.

2. **Set Up Oracle Connection:**
   - Create a new user and schema in Oracle.
   - Note down the connection details (username, password, host, port, SID).

3. **Install Code::Blocks:**
   - Download and install Code::Blocks IDE.

4. **Install Oracle ODBC Driver:**
   - Download and install Oracle ODBC driver for your system.

5. **Configure ODBC Data Source:**
   - Set up an ODBC data source using the Oracle driver, providing the connection details.

6. **Modify C++ Code:**
   - Open the C++ code in Code::Blocks.
   - Replace placeholders in the code with your actual connection details.

7. **Compile and Run:**
   - Compile and run the C++ program in Code::Blocks.

## Database Setup (SQL Script)

```sql
-- Create the database
CREATE DATABASE TransactionsDB;

-- Use the database
USE TransactionsDB;

-- Create Users table
CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    UserName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL,
);

-- Create Transactions table
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY,
    UserID INT,
    Amount DECIMAL(10, 2) NOT NULL,
    TransactionDate DATETIME NOT NULL,
    FOREIGN KEY (UserID) REFERENCES Users(UserID),
);

```

## Seed the database with some data (SQL Script)

```sql
-- Seed Users table
INSERT INTO Users (UserID, UserName, Email) VALUES
(1, 'JohnDoe', 'john.doe@example.com'),
(2, 'JaneSmith', 'jane.smith@example.com'),
(3, 'BobJohnson', 'bob.johnson@example.com');

-- Seed Transactions table
INSERT INTO Transactions (TransactionID, UserID, Amount, TransactionDate) VALUES
(101, 1, 50.00, '2023-01-01 08:00:00'),
(102, 2, 75.50, '2023-01-02 12:30:00'),
(103, 1, 30.25, '2023-01-03 15:45:00');
```

