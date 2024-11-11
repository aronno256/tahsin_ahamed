#include <iostream>
#include <string>
#include <algorithm>
#include "student.h"
#include<ctime>

int count_s=0;

using namespace std;
///////////////////////////////////////
string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    //srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);
}

///////////////////////////////////////
string generaterandom_name()
{
    string firstname=generateRandomString(4);
    string lastname=generateRandomString(4);
    string name=firstname+" "+lastname;
    return name;
}
int generaterandom_adyear()
{
    return randomInRange(2020,2023);
}
string generaterandom_address()
{
    string address=generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4);
    return address;
}

string generaterandomid()
{
    string i="";
    i+=to_string(randomInRange(20,23));
    i+="00";
    i+=to_string(randomInRange(1,6));
    i+=to_string(randomInRange(1,2));
    i+=to_string(randomInRange(1,2));
    i+=to_string(randomInRange(1,70));
    return i;

}

double generaterandomgpa()
{

    /*
    double gpa;
    double quizzes[4];
    double midterm;
    double finals;
    double attendance;
    quizzes[1]=randomInRange(1,5);
    quizzes[2]=randomInRange(1,5);
    quizzes[3]=randomInRange(1,5);
    quizzes[4]=randomInRange(1,5);
    midterm=randomInRange(1,25);
    finals=randomInRange(1,50);
    attendance=randomInRange(1,5);
    double quizTotal=0;
    double totalMarks=0;
    for (int i = 0; i < 4; i++) {
        quizTotal += quizzes[i];
    }

    totalMarks = quizTotal + midterm + finals + attendance;
    if (totalMarks >= 90)
        gpa = 4.0;
    else if (totalMarks >= 80)
        gpa = 3.5;
    else if (totalMarks >= 70)
        gpa = 3.0;
    else if (totalMarks >= 60)
        gpa = 2.5;
    else if (totalMarks >= 50)
        gpa = 2.0;
    else
        gpa = 0.0;
    return gpa;
    */
    double gpa;
    gpa=randomInRange(2,4);
    return gpa;

}
////////////////////////////////////
void EditInformationByKeyboard(student &st) {
    string name, department, program, section, address;
    int admissionYear;

    cout << "Enter Student Name: ";
    getline(cin, name);
    st.setname(name);

    cout << "Enter Department: ";
    getline(cin, department);
    st.setdept(department);

    cout << "Enter Program: ";
    getline(cin, program);
    st.setprog(program);

    cout << "Enter Section: ";
    getline(cin, section);
    st.setsec(section);

    cout << "Enter Admission Year: ";
    cin >> admissionYear;
    st.set_admissionyear(admissionYear);
    cin.ignore();

    cout << "Enter Address: ";
    getline(cin, address);
    st.setaddress(address);
    count_s++;

    st.generateid();
}

void generateInformationRandom(student &st) {
    st.setid(generaterandomid());
    st.setname(generaterandom_name());
    st.setaddress(generaterandom_address());
    st.set_admissionyear(generaterandom_adyear());
    st.setgpa(generaterandomgpa());
    count_s++;
}

bool compareid(const student &a, const student &b) {
    return a.get_studentid() < b.get_studentid();
}

void ShowAllAlphabetically(student ar[]) {
    sort(ar, ar + count_s, compareid);

    for (int i = 0; i < count_s; i++) {
        cout << "Name: " << ar[i].getname() << endl;
        cout << "Id: " << ar[i].get_studentid() << endl;
        cout << "GPA: " << ar[i].getgpa() << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    student students[100];

    students[0].setname("Aronno");
    students[0].set_admissionyear(2022);
    students[0].setdept("CSE");
    students[0].setprog("CSE");
    students[0].setsec("2");
    students[0].generateid();
    //cout << "Generated Student ID: " << students[0].get_studentid() << endl;


    EditInformationByKeyboard(students[1]);


    generateInformationRandom(students[2]);
    generateInformationRandom(students[3]);
    generateInformationRandom(students[4]);
    generateInformationRandom(students[5]);
    generateInformationRandom(students[6]);
    generateInformationRandom(students[7]);
    generateInformationRandom(students[8]);
    generateInformationRandom(students[9]);

    ShowAllAlphabetically(students);


    return 0;
}
