#include <iostream>
#include <cstring>
#include <algorithm>

class Group;

class Student {
private:
    unsigned int studentID;
    char* surname;
    int* grades;
    Group* group;
public:
    Student();
    Student(unsigned int studentID, const char* surname, const int* grades, Group* group);
    Student(const Student& other);
    ~Student();

    std::string getLastName() const {
        return surname;
    }

    int getGrade(int subjectIndex) const {
        if (subjectIndex < 0 || subjectIndex >= Group::NUM_SUBJECTS) {
            return -1;
        }
        return grades[subjectIndex];
    }

    int getGradeCount() const {
        return Group::NUM_SUBJECTS;
    }

    // Getters
    unsigned int getStudentID() const;
    const char* getSurname() const;
    const int* getGrades() const;
    Group* getGroup() const;

    // Setters
    void setStudentID(unsigned int studentID);
    void setSurname(const char* surname);
    void setGrades(const int* grades);
    void setGroup(Group* group);

    // Assignment operator overload
    Student& operator=(const Student& other);

    // Output operator overload
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    // Comparison operator overloads
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator<=(const Student& other) const;
    bool operator>=(const Student& other) const;
};

// Default constructor
Student::Student() : studentID(0), surname(nullptr), grades(nullptr), group(nullptr) {}

// Constructor with parameters
Student::Student(unsigned int studentID, const char* surname, const int* grades, Group* group)
    : studentID(studentID), group(group) {
    // Allocate dynamic memory for surname
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);

    // Allocate dynamic memory for grades
    this->grades = new int[Group::NUM_SUBJECTS];
    for (int i = 0; i < Group::NUM_SUBJECTS; i++) {
        this->grades[i] = grades[i];
    }
}

// Copy constructor
Student::Student(const Student& other) {
    // Copy student ID and group
    this->studentID = other.studentID;
    this->group = other.group;

    // Allocate dynamic memory for surname
    this->surname = new char[strlen(other.surname) + 1];
    strcpy(this->surname, other.surname);

    // Allocate dynamic memory for grades
    this->grades = new int[Group::NUM_SUBJECTS];
    for (int i = 0; i < Group::NUM_SUBJECTS; i++) {
        this->grades[i] = other.grades[i];
    }
}

// Destructor
Student::~Student() {
    // Free dynamic memory
    delete[] surname;
    delete[] grades;
}

// Getters
unsigned int Student::getStudentID() const {
    return studentID;
}

const char* Student::getSurname() const {
    return surname;
}

const int* Student::getGrades() const {
    return grades;
}

Group* Student::getGroup() const {
    return group;
}

// Setters
void Student::setStudentID(unsigned int studentID) {
    this->studentID = studentID;
}

void Student::setSurname(const char* surname) {
    // Free previous memory
    delete[] this->surname;

    // Allocate new dynamic memory for surname
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

void Student::setGrades(const int* grades) {
    // Free previous memory
    delete[] this->grades;

    // Allocate new dynamic memory for grades
    this->grades = new int[Group::NUM_SUBJECTS];
    for (int i = 0; i < Group::NUM_SUBJECTS; i++) {
        this->grades[i] = grades[i];
    }
}

void Student::setGroup(Group* group) {
    this->group = group;
}

// Assignment operator overload
Student& Student::operator=(const Student& other) {
    if (this == &other) { // Check for self-assignment
        return *this;
    }
    // Copy student ID and group
    this->studentID = other.studentID;
    this->group = other.group;

    // Free previous memory for surname
    delete[] this->surname;

    // Allocate dynamic memory for surname
    this->surname = new char[strlen(other.surname) + 1];
    strcpy(this->surname, other.surname);

    // Free previous memory for grades
    delete[] this->grades;

    // Allocate dynamic memory for grades
    this->grades = new int[Group::NUM_SUBJECTS];
    for (int i = 0; i < Group::NUM_SUBJECTS; i++) {
        this->grades[i] = other.grades[i];
    }

    return *this;
}

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student ID: " << student.studentID << "\n";
    os << "Surname: " << student.surname << "\n";
    os << "Grades: ";
    for (int i = 0; i < Group::NUM_SUBJECTS; i++) {
        os << student.grades[i] << " ";
    }
    os << "\nGroup: " << student.group->getSurname() << "\n";
    return os;
}

// Comparison operator overloads
bool Student::operator==(const Student& other) const {
    return this->studentID == other.studentID;
}

bool Student::operator!=(const Student& other) const {
    return !(*this == other);
}

bool Student::operator<(const Student& other) const {
    // Compare surnames lexicographically
    return strcmp(this->surname, other.surname) < 0;
}

bool Student::operator>(const Student& other) const {
    return other < *this;
}

bool Student::operator<=(const Student& other) const {
    return !(other < *this);
}

bool Student::operator>=(const Student& other) const {
    return !(*this < other);
}

class Group {
private:
    int index;
    Student** students;
    int count;
    int maxSize;

    std::string surname;
public:
    std::string getSurname() const {
        return surname;
    }
    static const int NUM_SUBJECTS = 5;
    Group() : index(0), students(nullptr), count(0), maxSize(0) {}

    Group(int index, int maxSize) : index(index), count(0), maxSize(maxSize) {
        students = new Student * [maxSize];
    }

    Group(const Group& other) : index(other.index), count(other.count), maxSize(other.maxSize) {
        students = new Student * [maxSize];
        for (int i = 0; i < count; i++) {
            students[i] = new Student(*other.students[i]);
        }
    }

    ~Group() {
        for (int i = 0; i < count; i++) {
            delete students[i];
        }
        delete[] students;
    }

    // getters and setters
    int getIndex() const {
        return index;
    }

    void setIndex(int newIndex) {
        index = newIndex;
    }

    Student* operator[](int i) const {
        return students[i];
    }

    // assignment operator
    Group& operator=(const Group& other) {
        if (this != &other) {
            index = other.index;
            count = other.count;
            maxSize = other.maxSize;
            for (int i = 0; i < count; i++) {
                delete students[i];
            }
            delete[] students;
            students = new Student * [maxSize];
            for (int i = 0; i < count; i++) {
                students[i] = new Student(*other.students[i]);
            }
        }
        return *this;
    }

    // sort by increasing product of grades
    void sortByProduct() {
        std::sort(students, students + count, [](const Student* a, const Student* b) {
            int productA = 1, productB = 1;
            for (int i = 0; i < a->getGradeCount(); i++) {
                productA *= a->getGrade(i);
            }
            for (int i = 0; i < b->getGradeCount(); i++) {
                productB *= b->getGrade(i);
            }
            return productA < productB;
            });
    }

    // find students with last name shorter than 8 letters
    Group findByShortLastName() const {
        Group result(index, maxSize);
        for (int i = 0; i < count; i++) {
            if (students[i]->getLastName().length() < 8) {
                result.addStudent(*students[i]);
            }
        }
        return result;
    }

    void addStudent(const Student& s) {
        if (count == maxSize) {
            std::cout << "Error: Group is full" << std::endl;
            return;
        }
        students[count++] = new Student(s);
    }

    void print(std::ostream& os) const {
        os << "Group " << index << std::endl;
        for (int i = 0; i < count; i++) {
            os << *students[i] << std::endl;
        }
    }
};
