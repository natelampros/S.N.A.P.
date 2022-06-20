//
// Created by Nate Lampros on 9/21/21.
//

#ifndef CS235_LAB02_CSG_H
#define CS235_LAB02_CSG_H
#include "Snap.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// csg(CS142,33333,B+).

class Csg : public Snap{
private:
    string className;
    string studentID;
    string studentGrade;

public:
    Csg(string studentIdIn, string studentNameIn, string studentAddressIn, string studentPhoneIn, string classNameIn,
        string studentIDIn, string studentGradeIn) : Snap(studentIdIn, studentNameIn, studentAddressIn, studentPhoneIn) {
        SetClassName(classNameIn);
        SetStudentID(studentIDIn);
        SetStudentGrade(studentGradeIn);
    }

    ~Csg() = default;

    void SetClassName(string classNameIn){
        this->className = classNameIn;
    }
    string GetClassName() const{
        return className;
    }

    void SetStudentID(string studentIDIn){
        this->studentID = studentIDIn;
    }
    string GetStudentID() const{
        return studentID;
    }


    void SetStudentGrade(string studentGradeIn){
        this->studentGrade = studentGradeIn;
    }
    string GetStudentGrade() const{
        return studentGrade;
    }

    string CourseGrades() const{
        ostringstream os;
        os << className << "," << studentName << "," << studentGrade;
        return os.str();
    }

    string to_string() const {
        ostringstream os;
        os << "csg(" << className << "," << studentID << "," << studentGrade  << ")";
        return os.str();
    }

    friend std::ostream& operator<< (ostream& os, const Csg& myclass){
        os << myclass.to_string();
        return os;
    }

};


#endif //CS235_LAB02_CSG_H
