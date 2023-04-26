#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "student.hpp"

using namespace std;




int main() {
    string sName;
    string sSurname;
    int sAge;
    int e;
    int id=0;

    Student student;

    do
    {
      

        int choice;
        cout << "1 add  " << endl;
        cout << "2 edit " << endl;
        cout << "3 delate" << endl;
        cout << "4 view" << endl;
        cout << "5 search" << endl;
        cin >> choice;

        if (choice == 1) // add +
        {
            
            string sName;
            string sSurName;
            int sAge;

            cout << "give me a name" << endl;
            cin >> sName;
            cout << "give me a suranme" << endl;
            cin >> sSurname;
            cout << "give me a age" << endl;
            cin >> sAge;

            ofstream foutput;
            ifstream finput;
            finput.open("student.txt");
            foutput.open("student.txt", ios::app);

            if (finput.is_open()) {
                id++;
                foutput << "ID:" << id << " NAME:" << sName << " SURNAME:" << sSurname << " AGE:" << sAge << endl;
            }
                

            finput.close();
            foutput.close();
            if (finput.is_open()==false and foutput.is_open()==false) { id++; }


        }
        
        
       

 else if (choice == 2) {  //edit
            string edit;
            string line;
            vector<string> lines;

            ifstream fin("student.txt");
            ofstream temp("temp.txt");

            while (getline(fin, line)) {
                lines.push_back(line);
            }
            fin.close();

            for (int i = 0; i < lines.size(); i++) {
                cout << i << ": " << lines[i] << endl;
            }

            cout << "Which line do you want to edit: ";
            cin >> edit;

            int index_to_edit = stoi(edit);
            if (index_to_edit >= 0 && index_to_edit < lines.size()) {
                cout << "Enter new data:" << endl;
                cout << "Name: ";
                cin >> sName;
                cout << "Surname: ";
                cin >> sSurname;
                cout << "Age: ";
                cin >> sAge;

                lines[index_to_edit] = sName + " " + sSurname + " " + to_string(sAge);
            }
            for (const auto& line : lines) {
                temp << line << endl;
            }
            temp.close();

            remove("student.txt");
            rename("temp.txt", "student.txt");
        }


        else if (choice == 3) { // delete
            string deleteline;
            string line;
            vector<string> lines;

            ifstream fin;
            fin.open("student.txt");
            ofstream temp;
            temp.open("temp.txt");


            while (getline(fin, line)) {
                lines.push_back(line);
            }
            fin.close();


            for (int i = 0; i < lines.size(); i++) {
                cout << i << ": " << lines[i] << endl;
            }


            cout << "Which line do you want to delete ";
            cin >> deleteline;


            int index_to_delete = stoi(deleteline);
            if (index_to_delete >= 0 && index_to_delete < lines.size()) {
                lines.erase(lines.begin() + index_to_delete);
            }


            for (const auto& line : lines) {
                temp << line << endl;
            }
            temp.close();


            remove("student.txt");
            rename("temp.txt", "student.txt");
        }
        else if (choice == 4)
        {
            string deleteline;
            string line;
            vector<string> lines;

            ifstream fin;
            fin.open("student.txt");
            ofstream temp;
            temp.open("temp.txt");


            while (getline(fin, line)) {
                lines.push_back(line);
            }
            fin.close();

            for (int i = 0; i < lines.size(); i++) {
                cout << i << ": " << lines[i] << endl;
            }
        }
        else if (choice == 5)
        {


            
            string line;
            int offset;
            string x = "";
            ifstream Myfile("student.txt");
            cout << " ID to search  ";
            cin >> x;
            /*
            while (getline(Myfile, line)) {
                if ((offset = line.find(x, 0)) != string::npos) {
                    cout << line << endl;
                }
            }
            */
            while (getline(Myfile, line)) {
                size_t found = line.find("ID:"+x);
                if (found != string::npos) { cout << line << endl; }
                else { cout << "This id does not exist" << endl; break; }
               //else { cout << "bbom!"; }

            }
            Myfile.close();
            
        }
        cout << " 1) repeat" << endl;
        cin >> e;
    } while (e == 1);

    return 0;
}
    

    
   

