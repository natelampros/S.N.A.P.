//
// Created by Nate Lampros on 9/21/21.
//


#ifndef CS235_LAB02_CDH_H
#define CS235_LAB02_CDH_H
#include <string>
#include <sstream>
using namespace std;

// cdh(HIST202,Th,3:00pm).

class Cdh {
private:
    string className;
    string dayofWeek;
    string classTime;

public:
    Cdh(string classNameIn, string dayofWeekIn, string classTimeIn){
        SetClassName(classNameIn);
        SetDayofWeek(dayofWeekIn);
        SetClassTime(classTimeIn);
    }
    ~Cdh() = default;


    void SetClassName(string classNameIn){
        this->className = classNameIn;
    }
    string GetClassName() const{
        return className;
    }


    void SetDayofWeek(string dayofWeekIn){
        this->dayofWeek = dayofWeekIn;
    }
    string GetDayofWeek() const{
        return dayofWeek;
    }


    void SetClassTime(string classTimeIn){
        this->classTime = classTimeIn;
    }
    string GetClassTime() const{
        return classTime;
    }

    string to_string() const {
        ostringstream os;
        os << "cdh(" << className << "," << dayofWeek << "," << classTime << ")";
        return os.str();
    }

    friend std::ostream& operator<< (ostream& os, const Cdh& myclass){
        os << myclass.to_string();
        return os;
    }
};


#endif //CS235_LAB02_CDH_H
