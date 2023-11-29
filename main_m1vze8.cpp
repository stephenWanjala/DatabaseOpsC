#include <iostream>
#include <string>
#include <sql.h>
#include <sqlext.h>

int main() {
    SQLHENV hEnv = NULL;
    SQLHDBC hDbc = NULL;
    SQLHSTMT hStmt = NULL;
    SQLRETURN ret;

    // Allocate environment handle
    if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) == SQL_ERROR) {
        std::cerr << "Error allocating environment handle." << std::endl;
        return -1;
    }

    // Set the ODBC version environment attribute
    if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0) == SQL_ERROR) {
        std::cerr << "Error setting ODBC version attribute." << std::endl;
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
        return -1;
    }

    // Allocate connection handle
    if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) == SQL_ERROR) {
        std::cerr << "Error allocating connection handle." << std::endl;
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
        return -1;
    }

    // Connect to the database
    SQLCHAR connectionString[] = "DSN=myDSN;UID=root;PWD=wanjala;";
    ret = SQLConnect(hDbc, (SQLCHAR*)"myDSN", SQL_NTS, (SQLCHAR*)"root", SQL_NTS, (SQLCHAR*)"wanjala", SQL_NTS);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "Error connecting to the database." << std::endl;
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
        return -1;
    }

    // The rest of your code remains unchanged

    // Disconnect and free handles
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    return 0;
}
