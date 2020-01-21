/*
@file		Structs.cpp
@author		Pedro Aguilar-Espejo
@version	1.0
A program that allows the user to enter, store, and display student names, 
houses(Gryffindor, Hufflepuff, Ravenclaw, Slytherin) And GPAs.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// structs defined here

//Includes all information required for a student attending Hogwarts
struct Student {

	string student_name = "TBD";
	string house_name = "TBD";
    float student_gpa = 0;

};

// function prototypes to be defined here

/**
* Prints students in a list
*
*   @param TBD
*   @return void
*/
void list_students(Student students[]);

/**
* Adds students with Name, House, GPA
*
*   @param TBD
*   @return Student

*/
Student add_student();

/**
* Lsits students with highest GPA
*
*   @param TBD
*   @return void
*/
void list_student_gpa(Student student_gpa[]);

int main() {

    Student wizard;
	int menu;

    Student list_wizards[10] = {};
    int counter = 0;
    
        do {
            cout << "Welcome to Hogwarts School of Witchcraft and Wizardry!\n\n";
            cout << "1.) Add a Student\n";
            cout << "2.) List Students\n";
            cout << "3.) List Student(s) with highest GPA\n";
            cout << "4.) Exit Program\n\n";
            cout << "Please enter your choice: ";
            cin >> menu;
            cin.ignore();
            cout << endl;

            switch (menu) {
            case 1:
                if(counter < 10)
              list_wizards[counter] = add_student();
                counter++;
                break;
            case 2:
                list_students(list_wizards);
                break;
            case 3:
                list_student_gpa(list_wizards);
                break;
            case 4:
                cout << "\nEnd of program.";
                break;
            default:
                cout << "\nInvalid choice\n\n" << "Choose again!\n\n";

            }

        } while (menu != 4);
      
	return 0;

}

// functions below this line

Student add_student() {

    Student new_student;
    //takes student name from user
	cout << "What is your students name?: ";
	getline(cin, new_student.student_name);

    // takes students GPA from user
	cout << "\nPlease enter students GPA(as a float ie: 0.0): ";
	cin >> new_student.student_gpa;

    //extra credit requirement, makes user take a small test in order to see which house the student belongs too.
	cout << "\n\nTo determine your students house please answer a few questions.\n\n";

    int gryffindor = 0;
    int hufflepuff = 0;
    int ravenclaw = 0;
    int slytherin = 0;

    int answer1, answer2, answer3, answer4;

    std::cout << "The new wizard trial! Answer the following questions to place your student in their approriate house!\n\n";
    do {
    std::cout << "\nQ1) What is your students favorite breakfast?:\n\n";
    std::cout << "1) Eggs\n2) Cereal\n3) Nails\n4) Candy\n" << "\n\nAnswer: ";
    std::cin >> answer1;
    // Adds one point to each house if they are chosen for each answer
        if (answer1 == 1) {
            hufflepuff++;
        }
        else if (answer1 == 2) {
            slytherin++;
        }
        else if (answer1 == 3) {
            ravenclaw++;
        }
        else if (answer1 == 4) {
            gryffindor++;
        }
        else {
            std::cout << "\nInvalid input. Try again\n";
        }
    } while (answer1 > 4);

    do {
        std::cout << "\nQ2) What does your student enjoy more? Mornings or Evenings?\n\n1) Morning\n2) Evening\n" << "\n\nAnswer: ";
        std::cin >> answer2;

        if (answer2 == 1) {
            gryffindor++;
            ravenclaw++;
        }
        else if (answer2 == 2) {
            slytherin++;
            hufflepuff++;
        }
        else {
            std::cout << "\nInvalid input. Try again\n\n";
        }
    } while (answer2 > 2);

    do {
        std::cout << "\nQ3) What does your student fear most?\n\n";
        std::cout << "1) Spiders\n2) Failure\n3) Disaster\n4) They dont have a fear\n" << "\n\nAnswer: ";
        std::cin >> answer3;

        if (answer3 == 1) {
            slytherin++;
        }
        else if (answer3 == 2) {
            hufflepuff++;
        }
        else if (answer3 == 3) {
            ravenclaw++;
        }
        else if (answer3 == 4) {
            gryffindor++;
        }
        else {
            std::cout << "\nInvalid input. Try again\n";
        }
    } while (answer3 > 4);

    do {
        std::cout << "\nQ4) Your arrives at a crossroad, Which way would your student go?\n\n";
        std::cout << "1) Straight\n";
        std::cout << "2) Left\n";
        std::cout << "3) Right\n";
        std::cout << "4) Up\n" << "\n\nAnswer: ";
        std::cin >> answer4;

        if (answer4 == 1) {
            hufflepuff++;
        }
        else if (answer4 == 2) {
            slytherin++;
        }
        else if (answer4 == 3) {
            gryffindor++;
        }
        else if (answer4 == 4) {
            ravenclaw++;
        }
        else {
            std::cout << "\nInvalid input. Try again\n";
        }
    } while (answer4 > 4);

    int score = 0;
    std::string house;

    // Goes through all the scores and compares to each on to see which one is highest
    if (gryffindor > score) {

        score = gryffindor;
        house = "Gryffindor";

    }

    if (hufflepuff > score) {

        score = hufflepuff;
        house = "Hufflepuff";

    }

    if (ravenclaw > score) {

        score = ravenclaw;
        house = "Ravenclaw";

    }

    if (slytherin > score) {

        score = slytherin;
        house = "Slytherin";

    }
    // adds house to new_student and prints results to the user
    cout << "\nYour student was placed in house " << house << " congratulations!\n\n";
   
    new_student.house_name = house;
    
    return new_student;
}

void list_students(Student students[]) {

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ".) ";
        cout << "Student Name: " << students[i].student_name << "\n";
        cout << "Student GPA: " << setprecision(1) << fixed << students[i].student_gpa << "\n";
        cout << "Student House: " << students[i].house_name << "\n\n";

    }

}

void list_student_gpa(Student student_gpa[]) {

    Student student_highest[10];
    int counter = 0;

    cout << "The student(s) with the highest GPA is: \n\n";

    // maybe try for loop inside for loop for comparison?
    //attempts to find highest GPA student and store in an array to print later
    for (int i = 0; i < 10; i++) {
        if (student_gpa[counter].student_gpa > student_gpa[i].student_gpa) {
            student_highest[counter] = student_gpa[i];
            counter++;
           
        }
            
    }

    for (int i = 0; i < counter; i++) {
        cout << "Name: " << student_highest[i].student_name << "\n";
        cout << "GPA: " << student_highest[i].student_gpa << "\n\n";
    }
}


