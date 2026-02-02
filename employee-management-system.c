#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char ssn[20];
    char name[50];
    char department[30];
    char designation[30];
    float salary;
    char phone[15];
    struct Employee *prev;
    struct Employee *next;
};

struct Employee *head = NULL;
struct Employee *tail = NULL;

struct Employee* createEmployee() {
    struct Employee *newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

    printf("Enter Employee Details:\n");

    printf("SSN: ");
    scanf("%s", newEmployee->ssn);

    printf("Name: ");
    getchar();
    fgets(newEmployee->name, sizeof(newEmployee->name), stdin);
    newEmployee->name[strcspn(newEmployee->name, "\n")] = 0;

    printf("Department: ");
    fgets(newEmployee->department, sizeof(newEmployee->department), stdin);
    newEmployee->department[strcspn(newEmployee->department, "\n")] = 0;

    printf("Designation: ");
    fgets(newEmployee->designation, sizeof(newEmployee->designation), stdin);
    newEmployee->designation[strcspn(newEmployee->designation, "\n")] = 0;

    printf("Salary: ");
    scanf("%f", &newEmployee->salary);

    printf("Phone Number: ");
    scanf("%s", newEmployee->phone);

    newEmployee->prev = NULL;
    newEmployee->next = NULL;

    return newEmployee;
}

void createList() {
    int n;
    printf("Enter number of employees to add: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of employees!\n");
        return;
    }

    printf("\n--- Creating Employee List using End Insertion ---\n");

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        struct Employee *newEmployee = createEmployee();

        if (head == NULL) {
            head = tail = newEmployee;
        } else {
            tail->next = newEmployee;
            newEmployee->prev = tail;
            tail = newEmployee;
        }

        printf("Employee added successfully!\n");
    }

    printf("\n%d employees added to the database.\n", n);
}

void display() {
    if (head == NULL) {
        printf("No employee records found!\n");
        return;
    }

    struct Employee *current = head;
    int count = 0;

    printf("\n=== EMPLOYEE DATABASE ===\n");
    printf("%-12s %-20s %-15s %-15s %-10s %-15s\n",
           "SSN", "Name", "Department", "Designation", "Salary", "Phone");
    printf("----------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-12s %-20s %-15s %-15s %-10.2f %-15s\n",
               current->ssn, current->name, current->department,
               current->designation, current->salary, current->phone);
        current = current->next;
        count++;
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("Total number of employees: %d\n", count);
}

void displayReverse() {
    if (tail == NULL) {
        printf("No employee records found!\n");
        return;
    }

    struct Employee *current = tail;
    int count = 0;

    printf("\n=== EMPLOYEE DATABASE (REVERSE ORDER) ===\n");
    printf("%-12s %-20s %-15s %-15s %-10s %-15s\n",
           "SSN", "Name", "Department", "Designation", "Salary", "Phone");
    printf("----------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-12s %-20s %-15s %-15s %-10.2f %-15s\n",
               current->ssn, current->name, current->department,
               current->designation, current->salary, current->phone);
        current = current->prev;
        count++;
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("Total number of employees: %d\n", count);
}

void insertAtEnd() {
    struct Employee *newEmployee = createEmployee();

    if (head == NULL) {
        head = tail = newEmployee;
    } else {
        tail->next = newEmployee;
        newEmployee->prev = tail;
        tail = newEmployee;
    }

    printf("Employee record inserted at the end successfully!\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty! No employee to delete.\n");
        return;
    }

    if (head == tail) {
        printf("Deleted employee: %s (%s)\n", head->name, head->ssn);
        free(head);
        head = tail = NULL;
        return;
    }

    struct Employee *temp = tail;
    tail = tail->prev;
    tail->next = NULL;

    printf("Deleted employee: %s (%s)\n", temp->name, temp->ssn);
    free(temp);
}

void insertAtFront() {
    struct Employee *newEmployee = createEmployee();

    if (head == NULL) {
        head = tail = newEmployee;
    } else {
        newEmployee->next = head;
        head->prev = newEmployee;
        head = newEmployee;
    }

    printf("Employee record inserted at the front successfully!\n");
}

void deleteFromFront() {
    if (head == NULL) {
        printf("List is empty! No employee to delete.\n");
        return;
    }

    if (head == tail) {
        printf("Deleted employee: %s (%s)\n", head->name, head->ssn);
        free(head);
        head = tail = NULL;
        return;
    }

    struct Employee *temp = head;
    head = head->next;
    head->prev = NULL;

    printf("Deleted employee: %s (%s)\n", temp->name, temp->ssn);
    free(temp);
}

void demonstrateDeque() {
    int choice;

    printf("\n=== DOUBLE ENDED QUEUE (DEQUE) DEMONSTRATION ===\n");
    printf("DLL can be used as a Deque with insertions/deletions at both ends\n");

    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front (addFirst)\n");
        printf("2. Insert at Rear (addLast)\n");
        printf("3. Delete from Front (removeFirst)\n");
        printf("4. Delete from Rear (removeLast)\n");
        printf("5. Display Deque\n");
        printf("6. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFront(); break;
            case 2: insertAtEnd(); break;
            case 3: deleteFromFront(); break;
            case 4: deleteFromEnd(); break;
            case 5: display(); break;
            case 6: return;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;

    printf("=== EMPLOYEE RECORD MANAGEMENT SYSTEM ===\n");
    printf("Using Doubly Linked List (DLL)\n");

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Create Employee List (End Insertion)\n");
        printf("2. Display All Employees and Count\n");
        printf("3. Display Employees in Reverse Order\n");
        printf("4. Insert Employee at End\n");
        printf("5. Delete Employee from End\n");
        printf("6. Insert Employee at Front\n");
        printf("7. Delete Employee from Front\n");
        printf("8. Demonstrate Double Ended Queue (Deque)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: displayReverse(); break;
            case 4: insertAtEnd(); break;
            case 5: deleteFromEnd(); break;
            case 6: insertAtFront(); break;
            case 7: deleteFromFront(); break;
            case 8: demonstrateDeque(); break;
            case 9:
                printf("Thank you for using Employee Management System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
