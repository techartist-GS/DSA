#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Data structure for student information, i.e., node
struct Node {
    int prn;
    char name[20];
    Node *next;
};

class Panclub {
    int num, cnt;
    char nm[20];  // Data members
    Node *head;   // Pointer to the first node 

public:
    // Constructor to initialize the object
    Panclub() {
        num = cnt = 0;
        head = NULL;
    }

    Node* create();
    void display(Node*);
    Node* concat(Node*, Node*);  // Member functions with arguments
    void reverse(Node*);
    Node* insert_president(Node*);
    void insert_sec(Node*);
    void insert_member(Node*);
    Node* del_president(Node*);
    Node* del_secretary(Node*);
    Node* del_member(Node*);
};

// To create the list of divisions
Node* Panclub::create() {
    Node *temp, *n1;
    temp = n1 = NULL;

    cout << "\nHow many students' data do you want to insert in Panclub database: ";
    cin >> cnt;

    while (cnt > 0) {
        n1 = new Node; // Allocate memory for all fields of the struct
        cout << "\nEnter the PRN number of student: ";
        cin >> num;
        n1->prn = num;

        cout << "\nEnter the name of student: ";
        cin >> nm;
        strcpy(n1->name, nm);

        n1->next = NULL; // Make the next field null

        if (head == NULL) { // Check if head is empty
            head = n1;   // Make new node the head
            temp = head;
        } else {
            temp = head;
            while (temp->next != NULL) { // Attach at the end of the list
                temp = temp->next;
            }
            temp->next = n1;
        }
        cnt--;
    }

    return head;
}

void Panclub::display(Node *head) { // Display the list of both divisions
    Node *temp;
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            cout << "[" << temp->prn << "|" << temp->name << "]->NULL";
        } else {
            cout << "[" << temp->prn << "|" << temp->name << "]->";
        }
        temp = temp->next;
    }
    cout << endl;
}

Node* Panclub::concat(Node *head1, Node *head2) { // To concatenate both divisions' data into one list
    Node *head3, *temp, *temp1;
    head3 = temp = temp1 = NULL;
    temp = head1;
    head3 = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp1 = head2;
    temp->next = temp1;

    return head3;
}

void Panclub::reverse(Node *head) {
    Node *temp;
    temp = head;

    if (temp == NULL)
        return;

    reverse(temp->next);
    cout << "[" << temp->prn << "|" << temp->name << "]->";
}

Node* Panclub::insert_president(Node *head) {
    Node *temp, *n2;
    temp = n2 = NULL;
    temp = head;
    n2 = new Node;
    
    cout << "\nEnter the PRN number of President: ";
    cin >> n2->prn;
    cout << "\nEnter the name of President: ";
    cin >> n2->name;
    
    n2->next = temp;
    head = n2;
    return head;
}

void Panclub::insert_member(Node *head) {
    Node *temp, *n2;
    int pn;
    temp = head;
    n2 = new Node;
    
    cout << "\nEnter the PRN number of Member: ";
    cin >> n2->prn;
    cout << "\nEnter the name of Member: ";
    cin >> n2->name;
    
    n2->next = NULL;
    
    cout << "\nEnter the PRN number after which you want to add this member: ";
    cin >> pn;
    
    while (temp != NULL) {
        if (temp->prn == pn) {
            n2->next = temp->next;
            temp->next = n2;
            break;
        }
        temp = temp->next;
    }
    
    cout << "\n\nMember added successfully…!!";
}

void Panclub::insert_sec(Node *head) {
    Node *temp, *n2;
    temp = head;
    n2 = new Node;
    
    cout << "\nEnter the PRN number of Secretary: ";
    cin >> n2->prn;
    cout << "\nEnter the Name of Secretary: ";
    cin >> n2->name;
    
    n2->next = NULL;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = n2;
}

// Delete the president node from list
Node* Panclub::del_president(Node *head) {
    Node *temp;
    temp = head;
    head = temp->next;
    delete temp;
    return head;
}

// Delete the secretary node from the list
Node* Panclub::del_secretary(Node *head) {
    Node *temp, *t1;
    temp = head;
    
    while (temp->next != NULL) {
        t1 = temp;
        temp = temp->next;
    }
    
    t1->next = NULL;
    delete temp;
    return head;
}

// Delete a member from the list
Node* Panclub::del_member(Node *head) {
    Node *temp, *t1;
    int pn;
    temp = head;
    
    cout << "\nEnter the PRN number after which you want to delete member: ";
    cin >> pn;
    
    while (temp != NULL) {
        if (temp->prn == pn) {
            t1 = temp->next;
            temp->next = t1->next;
            delete t1;
            break;
        }
        temp = temp->next;
    }
    
    cout << "\n\nMember removed successfully…!!";
    return head;
}

int main() {
    Panclub p1, p2, p3;
    Node *h1, *h2, *h3;
    h1 = h2 = h3 = NULL;
    int ch;

    cout << "\n\t!!!Group B: Assignment No:01!!!" << endl; // Prints assignment number and group

    do {
        cout << "\n\n1. Enter data of SE A Division:";
        cout << "\n2. Enter data of SE B Division:";
        cout << "\n3. Concatenation of Lists..";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n\nPlease enter the student info who is a registered member..";
                cout << "\n\nEnter the Panclub Data of SE A Division:\n";
                h1 = p1.create();
                cout << "\nSE Comp Division A List is as follows:\n\n";
                p1.display(h1);
                cout << "\n\nReverse List of SE Div A:\n\n";
                p1.reverse(h1);
                p1.insert_sec(h1);
                cout << "\nAfter insertion of Secretary: \n";
                p1.display(h1);
                h1 = p1.insert_president(h1);
                cout << "\nAfter insertion of President: \n";
                p1.display(h1);
                p1.insert_member(h1);
                cout << "\nAfter insertion of member…\n";
                p1.display(h1);
                h1 = p1.del_president(h1);
                cout << "\n\nAfter deletion of president…\n";
                p1.display(h1);
                h1 = p1.del_secretary(h1);
                cout << "\n\nAfter deletion of secretary…\n";
                p1.display(h1);
                h1 = p1.del_member(h1);
                cout << "\n\nAfter deletion of member…\n";
                p1.display(h1);
                break;

            case 2:
                cout << "\n\nEnter the Panclub Data of SE B Division:\n";
                h2 = p2.create();
                cout << "\nSE Comp Division B List is as follows:\n\n";
                p2.display(h2);
                cout << "\n\nReverse List of SE Div B:\n\n";
                p2.reverse(h2);
                p2.insert_sec(h2);
                cout << "\nAfter insertion of Secretary: \n";
                p2.display(h2);
                h2 = p2.insert_president(h2);
                cout << "\nAfter insertion of President: \n";
                p2.display(h2);
                p2.insert_member(h2);
                cout << "\nAfter insertion of member…\n";
                p2.display(h2);
                h2 = p2.del_president(h2);
                cout << "\n\nAfter deletion of president…\n";
                p2.display(h2);
                h2 = p2.del_secretary(h2);
                cout << "\n\nAfter deletion of secretary…\n";
                p2.display(h2);
                h2 = p2.del_member(h2);
                cout << "\n\nAfter deletion of member...\n";
                p2.display(h2);
                break;

            case 3:
                h3=p3.concat(h1,h2);
                cout<<"The concatenation of Div : A and Div : B of SE Comp Class are as follows.\n\n";
                p3.display(h3);
                break;
          }
     }while(ch!=4);
      return 0;
}
