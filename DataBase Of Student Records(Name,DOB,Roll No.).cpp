//data base of student


#include <iostream>
#include <string.h>
using namespace std;

class PersonAdditionalInfo {
    char address[20], license[20], insurance[20];
    long int contact;

public:
    PersonAdditionalInfo() : contact(0) {
        cout << "Constructor" << endl;
        strcpy(address, "XYZ");
        strcpy(license, "AB00000000");
        strcpy(insurance, "XXXXXXXXX");
    }

    ~PersonAdditionalInfo() {
        cout << "Destructor" << endl;
    }

    friend class Person;
};

class Person {
    char name[20], dob[20], blood[20], div[10];
    int roll_no;
    float ht, wt;
    static int count;
    PersonAdditionalInfo *pai;

public:
    Person() : roll_no(1), ht(0), wt(0), pai(new PersonAdditionalInfo) {
        cout << "Constructor" << endl;
        strcpy(name, "ABCD");
        strcpy(dob, "XX");
        strcpy(blood, "X");
        strcpy(div, "A");
        count++;
    }

    Person(Person *p1) : pai(new PersonAdditionalInfo) {
        cout << "Copy Constructor" << endl;
        strcpy(name, p1->name);
        strcpy(dob, p1->dob);
        strcpy(blood, p1->blood);
        strcpy(div, p1->div);
        roll_no = p1->roll_no;
        ht = p1->ht;
        wt = p1->wt;
        strcpy(pai->address, p1->pai->address);
        strcpy(pai->license, p1->pai->license);
        strcpy(pai->insurance, p1->pai->insurance);
        pai->contact = p1->pai->contact;
        count++;
    }

    static void showCount() {
        cout << "\nNo Of records count=" << count << "\n";
    }

    ~Person() {
        cout << "Destructor" << endl;
        delete pai;
        count--;
    }

    void getData(const char name[20]);
    void display() const;
};

int Person::count = 0;

void Person::getData(const char name[20]) {
    strcpy(this->name, name);
    cout << "\nEnter date of birth=" << endl;
    cin >> dob;
    cout << "\nEnter Blood Group=" << endl;
    cin >> blood;
    cout << "Enter Division";
    cin >> div;
    cout << "Enter Roll No=" << endl;
    cin >> roll_no;
    cout << "\nEnter height=" << endl;
    cin >> ht;
    cout << "\nEnter Weight=" << endl;
    cin >> wt;
    cout << "\nEnter Address" << endl;
    cin >> pai->address;
    cout << "Enter License Number=" << endl;
    cin >> pai->license;
    cout << "\nEnter Insurance Policy Number=" << endl;
    cin >> pai->insurance;
    cout << "\nEnter Contact Number=" << endl;
    cin >> pai->contact;
}

void Person::display() const {
    cout << "\t" << name;
    cout << "\t" << dob;
    cout << "\t" << blood;
    cout << "\t" << div;
    cout << "\t" << roll_no;
    cout << "\t" << ht;
    cout << "\t" << wt;
    cout << "\t" << pai->address;
    cout << "\t" << pai->license;
    cout << "\t" << pai->insurance;
    cout << "\t" << pai->contact;
}

int main() {
    Person *p1, *p2;
    int ch;
    p1 = new Person;
    p2 = new Person(p1);

    cout << "\tName";
    cout << "\tDOB";
    cout << "\tBlood";
    cout << "\tDivision";
    cout << "\tRoll No";
    cout << "\tHeight";
    cout << "\tWeight";
    cout << "\tAddress";
    cout << "\tLicense";
    cout << "\tInsurance";
    cout << "\tContact";
    cout << endl;



    cout << "Default Constructor Value \n";
    p1->display();
    cout << "\n";
    cout << "Copy Constructor Value \n";
    p2->display();

    int n;
    cout << "\nEnter How many Records You Want?";
    cin >> n;
    Person p3[n];
    char name[20];
    int x = 0;

    do {
        cout << "\nWelcome To Personal Database System";
        cout << "\n1. Enter The Record";
        cout << "\n2. Display The Record";
        cout << "\n3. Exit" << endl;
        cin >> ch;

        switch (ch) {
        case 1: {
            cout << "\nEnter The Name=";
            cin >> name;
            p3[x].getData(name);
            Person::showCount();
            x++;
            break;
        }
        case 2: {
            cout << "\tName";
            cout << "\tDOB";
            cout << "\tBlood";
            cout << "\tDivision";
            cout << "\tRoll No";
            cout << "\tHeight";
            cout << "\tWeight";
            cout << "\tAddress";
            cout << "\tLicense";
            cout << "\tInsurance";
            cout << "\tContact";
            for (int i = 0; i < x; i++) {
                cout << "\n";
                p3[i].display();
            }
            break;
        }
        }
    } while (ch != 3);

    delete p1;
    delete p2;

    return 0;
}
