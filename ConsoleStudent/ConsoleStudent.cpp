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

    Student student;


    int choice;
    cout << " 1 zeby dodac  " << endl;           
    cout << "2 zeby edytowac: " << endl;
    cout << "3 zeby usunac" << endl;
    cin >> choice;

    
    
        if (choice == 1) {
            cout << "podaj imnie" << endl;
            cin >> sName;
            cout << "podaj nazwisko" << endl;
            cin >> sSurname;
            cout << "podaj wiek" <<  endl;
            cin >> sAge;
            ofstream zapis("student.txt");

            zapis << sName << " , ";
            zapis << sSurname << " , ";
            zapis << sAge << " , " << endl;


            zapis.close();



        }
        else if (choice == 2) {
            fstream edit;
            edit.open("student.txt");
            string linia;
            do
            {
                getline(edit, linia);
                cout << linia << endl;
            } while (linia != "");

            edit.close();

            cout << "podaj inne dane" << endl;





        }



        else if (choice == 3) {
            std::ifstream file_in("student.txt");
            std::ofstream file_out("temp.txt");
            std::string line;
            int line_number = 1; // numer linii do usunięcia

            int current_line_number = 1;
            while (std::getline(file_in, line)) {
                if (current_line_number != line_number) {
                    file_out << line << std::endl;
                }
                current_line_number++;
            }

            file_in.close();
            file_out.close();

            
            std::remove("student.txt");
            std::rename("temp.txt", "student.txt");

            return 0;
        }
            
            

  }
    

    
   

