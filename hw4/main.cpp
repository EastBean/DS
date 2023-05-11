#include <iostream>
#include <fstream>
#include <string>
#include "hw4.h"
using namespace std;


//reference
//(1) website(fileio): https://www.learncpp.com/cpp-tutorial/basic-file-io/
//(2) website(string.compare): https://popawaw.tistory.com/39
//(2) lms lecture: 6-linked list, https://lms.handong.edu/courses/12089/external_tools/2

int main() {
    SList* list = new SList();

    string filename;    //파일 이름을 입력받을 변수
    string text;        //텍스트 파일의 맨 처음 줄을 받아올 변수
    string str;         //메뉴판을 보여준 뒤 입력받은 값을 받아올 변수

    int id_number;      //학번
    string name;        //이름
    int age;            //나이
    double score;       //점수
    
    cout << "Enter input file name : ";
    cin >> filename;        //맨 처음 파일의 이름을 입력받음

    ifstream inf(filename); 
    getline(inf, text);     //"id_number", "name", "age", "score"을 받아서 없앰(맨 처음 줄)

    while(inf >> id_number >> name >> age >> score) {
        list->Insert(id_number, name, age, score);      //파일이 끝날때까지 링크드 리스트에 파일 속 데이터들을 insert함.
    }

    inf.close();

    while(str.compare("Q") != 0) {      //입력받은 값이 Q일때까지 반복
        str = menu();                   //메뉴판을 실행시키고 입력받은 값을 str에 받아옴
        if(str.compare("A") == 0) {     //입력받은 값이 A일 경우에 각 데이터들을 입력받고 링크드 리스트에 그 데이터를 insert함
            cout << "==> Type student name : ";
            cin >> name;
            cout << "==> Type student id : ";
            cin >> id_number;
            cout << "==> Type age of student : ";
            cin >> age;
            cout << "==> Type score : ";
            cin >> score;

            list->Insert(id_number, name, age, score);

            cout << "\n" << name << "'s record is added." << endl;

        }
        else if(str.compare("D") == 0) {    //입력받은 값이 D일 경우에 학번을 하나 입력받고 해당하는 학번의 데이터를 delete.
            cout << "==> Type student id : ";
            cin >> id_number;

            list->Delete(id_number);

        }
        else if(str.compare("R") == 0) {    //입력받은 값이 R일 경우에 학번을 하나 입력받고 해당 학번을 retrieve한 뒤, 그 결과를 출력.
            list_node *temp;

            cout << "==> Type student id : ";
            cin >> id_number;

            temp = list->Retrieve(id_number);

            if(temp != NULL) cout << "\n" << temp->name << "'s age is " << temp->age << " and score is " << temp->score << endl;
            else cout << "\n" << "No record shown" << endl;
        }
        else if(str.compare("P") == 0) {    //입력받은 값이 P일 경우에 모든 데이터들을 print.
            cout << "id_number       name\t\tage\t\tscore" << endl;
            list->Print();
        }
    }

    cout << "\nBye!\n" << endl;             //종료 문구 출력.

    return 0;
}