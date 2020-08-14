#include "Doctor.h"
// Including the doctor header file but in quotes.

using namespace std;
/*
This is the Doctor cpp file where the Doctor class's
functions are implemented.
*/

/*
 * Notice: the 'name' and 'id' variables used throughout this
 * file are not declared in this file but are in the Doctor.h
 * file. This is an important note. If we were to declare the
 * name and id variables in this file, we would then have declared
 * 2 name and 2 id variables separate from each other. 1 pair would
 * live with the class, as defined in the header file, and the
 * other pair, declared in this file, would be global variables
 * living in this file alone.
*/

/* Note: the ClassName:: syntax after the return type but before
 * the function name this syntax exists to tell the compiler which
 * class the function belongs to. */

/* Constructor */
Doctor::Doctor()
{
    name = "BLANK NAME";
    id = 99999;
}

/* Constructor */
Doctor::Doctor(string name)
{
    this->name = name;
    id = 99999;
}

/* Constructor */
Doctor::Doctor(string name, int id)
{
    this->name = name;
    this->id = id;
}

/* This is a destructor. The destructor is implicitly
 * called each time an object goes out of scope so that
 * heap memory is freed up for use. */
Doctor::~Doctor(){}


/* Getter and Setter methods */

string Doctor::getName()const{

    return name;
}

void Doctor::setName(string name){

    this->name = name;
}

/* This has 'const' declared after the
 * function name but before the brackets so
 * that the value returned is a const and
 * so that the getter method does not
 * modify the class when retrieving data. */
int Doctor::getID() const {

    return id;
}

void Doctor::setID(int id){

    this->id = id;
}

int Doctor::compare(Doctor doc2){
    if (id > doc2.getID()){

        return 1;
    } else { if (id < doc2.getID()){

            return -1;
        } else {

            return 0;
        }
    }
}

/* The operator< method needs to be overridden if
 * one wishes to use a map with this object in it.
 * the operator< method serves as a comparison method
 * so that the map knows how to sort the object and
 * determine if it is unique or not. Notice that the
 * arguments are a constant. */
bool Doctor::operator<(const Doctor &doc)const{

    return id < doc.getID();
}
