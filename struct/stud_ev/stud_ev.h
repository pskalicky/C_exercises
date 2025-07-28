#ifndef STUD_EV_H
#define STUD_EV_H
typedef struct {
    int id;         // Unique identifier for the student
    char name[50];  // Name of the student
    int age;        // Age of the student
    float gpa;      // Grade Point Average of the student
} Student;

typedef enum {
    STATE_BEGIN,
    STATE_WAITING_ID,
    STATE_WAITING_NAME,
    STATE_WAITING_AGE,
    STATE_WAITING_GPA,
    STATE_CANCELLED,
    STATE_ERROR,
    STATE_END
} create_student_state;

#endif //STUD_EV_H
