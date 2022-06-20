#include <iostream>
#include <string>
#include <vector>
#include "Snap.h"
#include "Csg.h"
#include "Cdh.h"
#include "cr.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);

/*
    #define CONSOLE 1 // 1 is console 0 is output file

    cout << endl << "Input File: " << argv[1];
    //ifstream in(argv[1]);

    cout << endl << "Output File: " << (CONSOLE ? "cout" : argv[2]);
    ostream& out = CONSOLE ? cout : *(new ofstream(tests[TEST_NUM].output));
*/
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    vector<Snap> snaps;
    vector<Csg> csgs;
    vector<Csg> courseGrades;
    vector<Cdh> cdhs;
    vector<cr> crs;



    out << "Input Strings:" << endl;
    for (string line; getline(in, line);){	// Read until EOF
        if ("snap(" == line.substr(0, 5)) {
            // snap(12345,Charlie Brown,Manager,555-1234).
            out << line << endl;

            string iD = line.substr(5, line.find(',') - 5);

            line = line.substr(line.find(',') + 1);
            string studentName = line.substr(0, line.find(','));

            line = line.substr(line.find(',') + 1);
            string studentJob = line.substr(0, line.find(','));

            line = line.substr(line.find(',') + 1);
            string studentPhone = line.substr(0, line.find(')'));

            snaps.push_back(Snap(iD, studentName, studentJob, studentPhone));
        }

        else if ("csg(" == line.substr(0, 4)){
            // csg(CS142,33333,B+).
            out << line << endl;

            string courseName = line.substr(4, line.find(',') - 4);

            line = line.substr(line.find(',') + 1);
            string iD = line.substr(0, line.find(','));

            line = line.substr(line.find(',') + 1);
            string grade = line.substr(0, line.find(')'));

            csgs.push_back(Csg(std::string(), std::string(), std::string(), std::string(), courseName, iD, grade));

        }

        else if ("cdh(" == line.substr(0, 4)){
            // cdh(HIST202,Th,3:00pm).
            out << line << endl;

            string courseName = line.substr(4, line.find(',') - 4);

            line = line.substr(line.find(',') + 1);
            string day = line.substr(0, line.find(','));

            line = line.substr(line.find(',') + 1);
            string time = line.substr(0, line.find(')'));

            cdhs.push_back(Cdh(courseName, day, time));
        }

        else if ("cr(" == line.substr(0, 3)) {
            // cr(CS101,Turing Aud.).
            out << line << endl;

            string courseName = line.substr(3, line.find(',') - 3);

            line = line.substr(line.find(',') + 1);
            string room = line.substr(0, line.find(')'));

            crs.push_back(cr(courseName, room)); //TODO ADD TO VECTOR
        }
        else{
            out << "**Error: " << line << endl;
        }

    }

    out <<  "\nVectors:";

    for (int i = 0; i < snaps.size(); ++i){
        out << endl << snaps[i];
    }

    for (int i = 0; i < csgs.size(); ++i){
        out << endl << csgs[i];
    }

    for (int i = 0; i < cdhs.size(); ++i){
        out << endl << cdhs[i];
    }

    for (int i = 0; i < crs.size(); ++i){
        out << endl << crs[i];
    }


    out << endl << "\nCourse Grades:" << endl;
    string originalClass = csgs.at(0).GetClassName();
    for(int i = 0; i < csgs.size(); ++i){ //TODO ALTERNATIVE SO THAT IT DOESNT PRINT SAME THING TWICE

        string tempClass = csgs.at(i).GetClassName();
        if (originalClass != tempClass){
            out << endl;
            originalClass = tempClass;
        }

        out << csgs.at(i).GetClassName() << ",";
        for (int j = 0; j < snaps.size(); ++j){
            if (csgs.at(i).GetStudentID() == snaps.at(j).GetStudentID()){
                out << snaps.at(j).GetStudentName() << ",";
                break;
            }
        }

        out << csgs.at(i).GetStudentGrade();

        out << endl;
    }

    out << "\nStudent Schedules:" << endl;
    string originalName = snaps.at(0).GetStudentName();
    for (int i = 0; i < snaps.size(); ++i){
        string tempName = snaps.at(i).GetStudentName();
        if (originalName != tempName){
            out << endl;
            originalName = tempName;
        }

        out << snaps.at(i).GetStudentName() << ", " << snaps.at(i).GetStudentID() << ", " << snaps.at(i).GetStudentAddress() << ", " << snaps.at(i).GetStudentPhone() << endl;
        for (int j = 0; j < csgs.size(); ++j){
            if (csgs.at(j).GetStudentID() == snaps.at(i).GetStudentID()){
                out << "  " << csgs.at(j).GetClassName() << " ";
                for (int k = 0; k < cdhs.size(); ++k){
                    if (cdhs.at(k).GetClassName() == csgs.at(j).GetClassName()){
                        out << cdhs.at(k).GetDayofWeek();
                        if (k < cdhs.size() - 1 && cdhs.at(k).GetClassName().compare(cdhs.at(k+1).GetClassName()) != 0) {
                            out << " " << cdhs.at(k).GetClassTime() << ", ";

                            for (int z = 0; z < crs.size(); ++z) {
                                if (crs.at(z).GetClassName() == csgs.at(j).GetClassName()) {
                                    out << crs.at(z).GetRoomNumber();
                                }
                            }
                        }
                        else if (k == cdhs.size()-1){
                            out << " " << cdhs.at(k).GetClassTime() << ", ";

                            for(int z = 0; z < crs.size(); ++z){
                                if (crs.at(z).GetClassName() == csgs.at(j).GetClassName()){
                                    out << crs.at(z).GetRoomNumber();
                                }
                            }
                        }
                    }
                }
                out << endl;
            }
        }
    }

}//main func
