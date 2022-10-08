#include "Student.h"
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
using namespace std;


Student::Student() {
	this->studentName="";
	this-> studentId =0;
	this-> numbcredits=0; 
	this-> counter=0;

	

	for (int i = 0; i < 6; i++) {
		courses[i] = nullptr;
		
	
	}
	 
}
Student::Student(std::string name, int id ,int counter, int credits,  Course* that[6]) {
	
	this->setname(name);
	this->setid(id);
	this->setcounter(counter);
	this->setcredits(credits);

	for (int i = 0; i < 6; i++) {                //copying the array
		this->courses[i] = that[i];
	}


}

void Student::setcounter(int count) {
	this->counter = count;
		
}

void Student::setname(std::string name) {
	this->studentName = name;
}
void Student::setid(int id) {
	this->studentId = id;
}

std::string Student::getname() {
	return this->studentName;
}
void Student::setcredits(int credits) {
	if (numbcredits > 15) {
		std::cerr << "Error! You cant exceed 15 credits\n";
		return;
	}
	this->numbcredits = credits;
}
void Student::addcourse( Course& that) {

	if (this->counter < 6) {

		for (int i = 0; i < counter; i++) {
			if (this->courses[i]->overlap(that) ) {
				std::cerr << "Error! This course overlaps with another course\n";
				return;
			}
		}
		courses[counter] =  new Course(that);
		counter++;

	}
	else {
		std::cerr << "Error! You are not allowed to exceed 6 courses\n";
		return;
	}

}

void Student::displaycourses() {
	std::cout << "Student "<<this->getid()<<" is enrolled to the following courses:\n";
	for (int i = 0; i < this->counter; i++) {
		std::cout << this->courses[i]->getcourseNumber() << " \"" << this->courses[i]->getcourseName() << "\" " << "\tLecture starts:" << this->courses[i]->gettime() <<"\tCredits: " << this->courses[i]->getcedits()<< "\n" << endl;
	}

}
int Student::getid() {
	return this->studentId;
}
int Student::getcredits() {
	return this->numbcredits;
}
Course Student::returncourse(int x) {
	return *(this->courses[x - 1]);
}
Student::~Student() {


	for (int i = 0; i < this->counter; i++) {
		delete courses[i];
	
	}
	
	std::cout << "object of type Student was deleted\n" << std::endl;

}
