-- Create the database
CREATE DATABASE TransactionsDB;

-- Use the database
USE TransactionsDB;

-- Create Users table
CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    UserName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL
);

-- Create Transactions table
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY,
    UserID INT,
    Amount DECIMAL(10, 2) NOT NULL,
    TransactionDate DATETIME NOT NULL,
    FOREIGN KEY (UserID) REFERENCES Users(UserID)
);


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
