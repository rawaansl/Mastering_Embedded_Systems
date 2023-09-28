#ifndef LIST_H
#define LIST_H



typedef struct StudentRecord {
    char studentName[50];              // Adjust size as needed
    int studentID;
    float studentGPA;
    struct StudentRecord* nextRecord;  // Pointer to the next student record
} Student;


void addStudentRecord(void);
void fill_record_data(Student* p_newStudentData);
void printMenu();
void deleteRecord();
void viewRecords();
void deleteAllRecords();
void getNth();
void listSize();
void reverseList();





















#endif // LIST_H
