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

    Student student;

    do
    {
        int choice;
        cout << " 1 add  " << endl;
        cout << "2 edit " << endl;
        cout << "3 delate" << endl;
        cout << "4 preview" << endl;
        cin >> choice;



        if (choice == 1) // add +
        {
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

                if (finput.is_open())
                    foutput << sName << " " << sSurname << " " << sAge << endl;

                

                finput.close();
                foutput.close();
            
            


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
        cout << " 1) repeat" << endl;
        cin >> e;
    } while (e == 1);

        return 0;
}
    

    
   

