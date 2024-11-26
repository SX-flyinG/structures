#include <iostream>
#include <string.h>

using namespace std;

struct Student {
private:
    char* name;
    char* surname;
    double averageMark;
public:
    Student() {
        name = new char[9] { 'B', 'o', 'r', 'y', 's', 'l', 'a', 'v', '\0' };
        surname = new char[11] { 'L', 'i', 'n', 'c', 'h', 'e', 'v', 's', 'k', 'y', '\0' };
        averageMark = 11.2;
    }

    void AssingValues(const char* name, const char* surname, double averageMark) {
        delete[] this->name;
        this->name = nullptr;

        delete[] this->surname;
        this->surname = nullptr;

        this->name = new char[strlen(name) + 1];

        for (int i = 0; i < strlen(name) + 1; i++) {
            this->name[i] = (char)name[i];
        }

        this->surname = new char[strlen(surname) + 1];

        for (int i = 0; i < strlen(surname) + 1; i++) {
            this->surname[i] = (char)surname[i];
        }

        this->averageMark = averageMark;
    }

    const char* getName() {
        return name;
    }

    const char* getSurname() {
        return surname;
    }

    double getAverageMark() {
        return averageMark;
    }
};

struct Group {
private:
    char* groupName;
    int amountOfStudents;
    Student* arrayOfStudents;
public:
    Group() {
        groupName = new char[4] { 'P', '3', '8', '\0' };
        amountOfStudents = 0;
        arrayOfStudents = new Student[0];
    }

    void AddStudent(Student student) {
        Student* tempArrOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents; i++) {
            tempArrOfStudents[i].AssingValues(
                arrayOfStudents[i].getName(),
                arrayOfStudents[i].getSurname(),
                arrayOfStudents[i].getAverageMark());
        }

        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;

        amountOfStudents++;

        arrayOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents - 1; i++) {
            arrayOfStudents[i].AssingValues(
                tempArrOfStudents[i].getName(),
                tempArrOfStudents[i].getSurname(),
                tempArrOfStudents[i].getAverageMark());
        }

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;

        arrayOfStudents[amountOfStudents - 1].AssingValues(
            student.getName(),
            student.getSurname(),
            student.getAverageMark());
    }

    void Deleter(int indexToDelete) { // 
        if (indexToDelete < 0 || indexToDelete >= amountOfStudents) {
            cout << "Invalid index!" << endl;
            return;
        }
        Student* tempArrOfStudents = new Student[amountOfStudents - 1];  //
        int tempIndex = 0;

        for (int i = 0; i < amountOfStudents; i++) {
            if (i != indexToDelete - 1) {
                tempArrOfStudents[tempIndex].AssingValues(           //
                    arrayOfStudents[i].getName(),                    // 
                    arrayOfStudents[i].getSurname(),                 //
                    arrayOfStudents[i].getAverageMark()              //
                );
                tempIndex++;
            }
        }


        amountOfStudents--;         // 


        delete[] arrayOfStudents;
        arrayOfStudents = tempArrOfStudents;  // 
    }


    void PrintGroupInfo() {
        cout << "Group name: " << this->groupName << endl;
        cout << "Amount of students: " << this->amountOfStudents << endl;
        for (int i = 0; i < amountOfStudents; i++) {
            cout << "Student: " << i + 1 << endl;
            cout << "Name: " << this->arrayOfStudents[i].getName() << endl;
            cout << "Surname: " << this->arrayOfStudents[i].getSurname() << endl;
            cout << "Average mark: " << this->arrayOfStudents[i].getAverageMark() << endl << endl;
        }
    }

    const char* getGroupName() {
        return this->groupName;
    }

    void setGroupName(const char* groupName) {
        delete[] this->groupName;
        this->groupName = nullptr;

        this->groupName = new char[strlen(groupName) + 1];

        for (int i = 0; i < strlen(groupName) + 1; i++) {
            this->groupName[i] = (char)groupName[i];
        }
    }

    int getAmountOfStudents() {
        return this->amountOfStudents;
    }

    void setAmountOfStudents(int amountOfStudents) {
        this->amountOfStudents = amountOfStudents;
    }

    Student* getStudentsArray() {
        return this->arrayOfStudents;
    }

    void setStudentsArray(Student* arrayOfStudents, int n) {
        delete[] this->arrayOfStudents;
        this->arrayOfStudents = nullptr;

        this->arrayOfStudents = new Student[n];

        for (int i = 0; i < n; i++) {
            this->arrayOfStudents[i] = (Student)arrayOfStudents[i];
        }
    }

    ~Group() {
        delete[] groupName;
        groupName = nullptr;

        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;
    }
};

int main()
{

    Group groupObj;
    Student studentObj;
    while (true) {
        cout << "There are " << groupObj.getAmountOfStudents() << " in your group \"" << groupObj.getGroupName() << "\"" << "\nAdd student:1\nDelete student:2\n:";
        int choise;
        cin >> choise;
        if (choise == 1) {  // 
            cout << "Write the lenght of the name: ";                                      //
            int nameLenght;                                                                //
            cin >> nameLenght;                                                             //
            char* nameOfstudent = new char[nameLenght];                                    //
            cout << "Write the name: ";                                                    //
            cin >> nameOfstudent;                                                          //
            cout << "Write the lenght of the surname: ";                                   //
            int surnameLenght;                                                             //
            cin >> surnameLenght;                                                          //
            char* surnameOfstudent = new char[surnameLenght];                              // 
            cout << "Write the sername: ";                                                 //
            cin >> surnameOfstudent;                                                       //
            double averageMark;                                                            //
            cout << "Write the average mark: ";                                            //
            cin >> averageMark;                                                            //
            studentObj.AssingValues(nameOfstudent, surnameOfstudent, averageMark);         //
            groupObj.AddStudent(studentObj);                                               //
            cout << "---------" << endl;                                                   //
            groupObj.PrintGroupInfo();                                                     //
            cout << "---------" << endl;                                                   //
        }
        else if (choise == 2) {
            if (groupObj.getAmountOfStudents() < 1) {                                       //
                cout << "There is no one to delete..." << endl << endl;                       //
            }                                                                               //
            else {                                                                          //
                int index;                                                                  //
                cout << "Write the index of student you want to delete: ";                  // 
                cin >> index;                                                                 //
                cout << endl;                                                               //
                groupObj.Deleter(index);                                                    //
                cout << "---------" << endl;                                                //
                groupObj.PrintGroupInfo();                                                  //
                cout << "---------" << endl;                                                //
            }
        }
    }
}