#include <iostream>

using namespace std;

typedef struct t_list_node {
    int id_number;
    string name;
    int age;
    double score;
    struct t_list_node *link;
} list_node;

class SList
{
    private:
        list_node *head;

    public:
        SList();
        ~SList();
        list_node* Retrieve(int id_number);
        void Insert(int id_number, string name, int age, double score);
        void Delete(int id_number);
        void Print();
};

string menu();