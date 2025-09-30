#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    /* TODO */
    int id = ++last_student_id;
    if (num_of_students < MAX_STUDENTS) {
        students[num_of_students] = Student(name, id, midterm, final);
        num_of_students++;
    }
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int index = findStudentByID(id);
    if (index != -1) {
        for (int i = index; i < num_of_students - 1; i++) {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int index = findStudentByID(student.getID());
    if (index != -1) {
        students[index] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    
    int bestIndex = 0;
    float highestMidterm = students[0].getRecord().getMidterm();
    
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > highestMidterm) {
            highestMidterm = students[i].getRecord().getMidterm();
            bestIndex = i;
        }
    }
    return bestIndex;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    
    int bestIndex = 0;
    float highestFinal = students[0].getRecord().getFinal();
    
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > highestFinal) {
            highestFinal = students[i].getRecord().getFinal();
            bestIndex = i;
        }
    }
    return bestIndex;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    
    int bestIndex = 0;
    float highestTotal = students[0].getRecord().getTotal();
    
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getTotal() > highestTotal) {
            highestTotal = students[i].getRecord().getTotal();
            bestIndex = i;
        }
    }
    return students[bestIndex].getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getMidterm();
    }
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getFinal();
    }
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getTotal();
    }
    return sum / num_of_students;
}

