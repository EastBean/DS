#include <iostream>
#include "hw4.h"

using namespace std;

string menu() {         //Q를 입력받기 전까지 반복될 메뉴판
    string str;

    cout << "\n*********** MENU ****************" << endl;
    cout << "A : Add new data" << endl;
    cout << "D : Delete data" << endl;
    cout << "R : Retrieve data" << endl;
    cout << "P : Print list" << endl;
    cout << "Q : Quit" << endl;
    cout << "Choose menu : ";
    cin >> str;

    return str;         //입력받은 값을 str 변수에 저장
    
}

SList::SList() {
    head = NULL;
}

SList::~SList() {
    list_node *curr = head, *next;
    while(curr) {
        next = curr->link;
        delete curr;
        curr = next;
    }
}

list_node* SList::Retrieve(int id_number) {
    list_node *prev;
    list_node *curr = head;

    while(curr != NULL && curr->id_number != id_number) {   //입력받은 학번이 나올때까지 curr이 다음 링크를 가리키게 하며 탐색함
        prev = curr;                                        //탐색에 성공하거나 NULL에 도달하면 멈춤.
        curr = curr->link;
    }

    if(curr != NULL) return curr;                           //탐색에 성공했으면, 그때의 curr을 리턴
    else return NULL;                                       //탐색에 실패했으면 NULL을 리턴
}

void SList::Insert(int id_number, string name, int age, double score) {
    list_node *prev;
    list_node *curr = head;

    list_node *new_node = new list_node;
    
    new_node->id_number = id_number;
    new_node->name = name;
    new_node->age = age;
    new_node->score = score;
                                                                //매번 insert할 때마다 오름차순을 고려해야해서 여러 case로 나눔.
    if(head == NULL) {                                          //head가 NULL일 경우의 new_node 배치
        new_node->link = head;
        head =  new_node;
    }

    else if(new_node->id_number < head->id_number) {            //입력받은 new_node의 학번이 현재 head가 가리키는 node의 학번보다 작을 경우의 new_node 배치
        new_node->link = head;                  
        head = new_node;
    }

    else {                                                      //그 이외의 경우
        while(curr != NULL && curr->id_number < id_number) {    //curr가 가리키는 node의 학번이 현재 입력받은 학번보다 크거나 curr이 가리키는 node가 NULL을 가리키게 되면 종료
        prev = curr;                                            //curr을 이동시키며 curr이 가리키는 node의 학번이 입력받은 학번보다 클 때를 찾음
        curr = curr->link;
        }
        if(curr == NULL) {                                      //만약 찾지 못하고 curr이 NULL에 도착했을 경우, 현재 입력받은 학번이 가장 커서 끝까지 도착한 것임.
            prev->link = new_node;                              //new_node를 맨 끝에 배치하고 NULL을 가리키게 설정함.
            new_node->link = NULL;
        }
        else {                                                  //curr의 학번이 입력받은 학번 보다 클 경우, new_node가 curr을 가리키고 prev가 new_node를 가리키게 설정함.
            new_node->link = curr;
            prev->link = new_node;
            
        }

    }
}

void SList::Delete(int id_number) {
    list_node *prev;
    list_node *curr = head;
    string name;

    while(curr != NULL && curr->id_number != id_number) {
        prev = curr;                                            //입력받은 학번이 나올때까지 curr이 다음 링크를 가리키게 하며 탐색함
        curr = curr->link;                                      //탐색에 성공하거나 NULL에 도달하면 멈춤.
    }

    if(curr != NULL) {                                          //curr이 가리키는 node가 NULL을 가리키지 않으므로 입력받은 학번이 linked list안에 존재함
        name = curr->name;                                      //삭제 후 메시지 출력을 위해 이름을 name 변수에 저장함.
        if(curr == head) head = curr->link;                     //curr이 head가 같은 node를 가리킬 경우의 설정
        else {                                                  //curr이 head와 다른 node를 가리킬 경우의 설정
            prev->link = curr->link;
        }
        delete curr;                                            //삭제가 완료되었으니 curr을 delete해줌.
        
        cout << "\n" << name << "'s record is deleted." << endl;
    }

}

void SList::Print() {
    list_node *prev;
    list_node *curr = head;

    while(curr != NULL) {                                       //curr을 이동시키며 curr이 가리키는 node가 NULL을 가리킬 때까지 linked list의 내용을 한 줄씩 출력함. 여백 유지를 위해 "\t"를 사용.
        cout << curr->id_number << "\t\t" << curr->name << "\t\t" << curr->age << "\t\t" << curr->score << endl;
        curr = curr->link;
    }
}