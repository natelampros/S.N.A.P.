//
// Created by Nate Lampros on 9/21/21.
//

#ifndef CS235_LAB02_SNAP_H
#define CS235_LAB02_SNAP_H
#include <string>
#include <sstream>
using namespace std;

// snap(12345,Charlie Brown,Manager,555-1234).

class Snap {
protected:
    string studentID;
    string studentName;
    string studentAddress;
    string studentPhone;

public:
    Snap(string studentIDIn, string studentNameIn, string studentAddressIn, string studentPhoneIn){
        SetStudentID(studentIDIn);
        SetStudentName(studentNameIn);
        SetStudentAddress(studentAddressIn);
        SetStudentPhone(studentPhoneIn);
    }

    ~Snap() = default;

    void SetStudentID (string studentIDIn){
        this->studentID = studentIDIn;
    }
    string GetStudentID() const{
        return studentID;
    }

    void SetStudentName(string studentNameIn){
        this->studentName = studentNameIn;
    }
    string GetStudentName() const{
        return studentName;
    }

    void SetStudentAddress(string studentAddressIn){
        this->studentAddress = studentAddressIn;
    }
    string GetStudentAddress() const{
        return studentAddress;
    }

    void SetStudentPhone(string studentPhoneIn){
        this->studentPhone = studentPhoneIn;
    }
    string GetStudentPhone() const{
        return studentPhone;
    }

    string to_string() const {
        ostringstream os;
        os << "snap(" << studentID << "," << studentName << "," << studentAddress << "," << studentPhone << ")";
        return os.str();
    }

    friend std::ostream& operator<< (ostream& os, const Snap& myclass){
        os << myclass.to_string();
        return os;
    }
};


#endif //CS235_LAB02_SNAP_H
