#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 

int main(void){ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
    
    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      

    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID 1045 is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 
    

    // Example phone found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee phone 909-555-2134 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-555-2134 is NOT found in the record\n");

    // Example phone not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-000-2134");
    if (matchPtr != NULL)
        printf("Employee phone 909-000-2134 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-000-2134 is NOT found in the record\n");

    // Example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if (matchPtr != NULL)
        printf("Employee salary 4.50 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 4.50 is NOT found in the record\n");

    // Example salary not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.98);
    if (matchPtr != NULL)
        printf("Employee salary 5.98 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 5.98 is NOT found in the record\n");

    return EXIT_SUCCESS; 
} 