//
// Created by Nate Lampros on 9/21/21.
//

#ifndef CS235_LAB02_CR_H
#define CS235_LAB02_CR_H
#include <string>
#include <sstream>
using namespace std;

// cr(CS101,Turing Aud.).

class cr {
private:
    string className;
    string roomNumber;

public:
    cr(string classNameIn, string roomNumberIn){
        SetClassName(classNameIn);
        SetRoomNumber(roomNumberIn);
    }

    ~cr() = default;

    void SetClassName(string classNameIn){
        this->className = classNameIn;
    }
    string GetClassName() const{
        return className;
    }

    void SetRoomNumber(string roomNumberIn){
        this->roomNumber = roomNumberIn;
    }
    string GetRoomNumber() const{
        return roomNumber;
    }

    string to_string() const{
        ostringstream os;
        os << "cr(" << className << "," << roomNumber << ")";
        return os.str();
    }

    friend std::ostream& operator<< (ostream& os, const cr& myclass)
    {
        os << myclass.to_string();
        return os;
    }

};


#endif //CS235_LAB02_CR_H
