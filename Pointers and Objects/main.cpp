#include <iostream>
#include <ostream>
#include <Doctor.h> // Including the Doctor header file within the '< >' symbols.
#include <vector>
#include <map>

using namespace std;

/*
This program is made to practice working with various elements of the C++ programming language.
This includes: classes with constructors and destructors, getters, setters, and printing such
variables to the console. This also includes pointers and Container objects (vector and map
specifically).
*/
int main()
{
    // Pointer Practice

    int value = 43;             // Declaring an int variable 'value'.
    int* ptrToValue = &value;   // Declaring a pointer to that int variable 'value'.

    // Note: Notation to declare a pointer is ' type* '.
    // Note: '&' is the "address of" operator.

    /* The printing below prints the data stored in value and in ptrToValue
      (which is the memory address of 'value') */
    cout << "Value: " << value << " ptrToValue: " << ptrToValue << endl;

    /* The printing below prints the data stored in value and the value of
       the object pointed to by the ptrToValue variable (which is the data
       stored in value). */
    cout << "Value: " << value << " ptrToValue: " << *ptrToValue << endl;

    // Note: for a null pointer, there exists NULL and nullptr.
    /*
    string obj = NULL;
    string* nulptr = &obj;

    cout << *nulptr << endl;        // This line here throws an error when finally
                                    // printing to the console. There is no detection
                                    // during compilation. */


    // Object Practice

    string name = "Bob";

    // Instantiating two Doctor objects with two different constructors.
    Doctor doc1 (name);
    Doctor doc2;

    // Printing a call to the Doctor objects getName getter method.
    cout << "\ndoc1 name: " + doc1.getName() << endl;
    cout << "doc2 name: " + doc2.getName() << endl;

    // Applying a setter method to one of the Doctor objects.
    doc1.setID(2019);

    // Printing a call to the Doctor objects getID getter method.
    cout << "doc1 id: " << doc1.getID() << endl;
    cout << "doc2 id: " << doc2.getID() <<endl;

    // Storing the id's in an int variable.
    int id1 = doc1.getID();
    int id2 = doc2.getID();

    // Practice printing integers.
    cout << "doc1 id: " << id1 << "\n";
    cout << "doc2 id: " << id2 << "\n";

    // Using setter methods.
    doc2.setName("Alice");
    doc2.setID(2020);

    // Checking that the setter methods worked.
    cout << "\ndoc1 name: " + doc1.getName() << endl;
    cout << "doc2 name: " + doc2.getName() << endl;

    // Calling a getter method in a print statement that returns an int.
    cout << "doc1 id: " << doc1.getID() << endl;
    cout << "doc2 id: " << doc2.getID() << endl;

    /* A header file for a class implementation is not totally necessary.
     * Specifically, the implementation of a function can be written
     * within the 'public' section of the .cpp class file. Below is an
     * example of a class implemented within the 'public' section of the
     * cpp file. */
    string inter = doc1.conver();
     cout <<'\n' << inter << endl;


    // Now we will try to use a vector!

    // This code instantiates a vector object
    std::vector<Doctor> docList;

    // This code adds the elements to the back of the vector list.
    docList.push_back(doc2);
    docList.push_back(doc1);

    // Iterating over the list and printing the names of the Doctor objects.
    for( unsigned int i = 0; i < docList.size(); i++){
        string name = docList[i].getName();
        cout << i + 1 << ": " + name << endl;
    }

    // This code removes elements from the back of the vector list.
    docList.pop_back();

    // Iterating over the list and printing the names of the Doctor objects.
    for( unsigned int i = 0; i < docList.size(); i++){
        string name = docList[i].getName();
        cout << i + 1 << ": " + name << endl;
    }

    docList.push_back(doc1);

     // 2019 < 2020 expecting -1
    int compareResult = doc1.compare(doc2);
    cout << "result (expecting -1): " << compareResult << endl;

    doc1.setID(2021);
    // 2021 > 2020 expecting 1
    compareResult = doc1.compare(doc2);
    cout << "result (expecting 1): " << compareResult << endl;

    doc1.setID(2020);
    // 2020 < 2020 expecting 0
    compareResult = doc1.compare(doc2);
    cout << "result (expecting 0): " << compareResult << "\n" << endl;

    // Allows random element access
    Doctor temp = docList.at(1);

    cout << "Retrieved via the at operator: " + temp.getName() << endl;

    // Assignment with random element access
    docList.at(1) = doc2;
    Doctor temp2 = docList.at(1);
    cout << "retrieved after assignment with the at function : " + temp2.getName() << '\n' << endl;




    // Now we will attempt to use a Map!
    // Must figure out how to instantiate a Map, add, remove and search for elements and keys.

     /* Problem: Each Doctor sees a number of patients. So we will have a map of doctors, the keys,
     * and the elements will be a list of the patients. */

     cout << "Map Printing" << '\n' << endl;

     std::map<Doctor, std::vector<std::string> > hospitalList;

     Doctor md1("Zeb",2020);

     std::vector<std::string> md1Patientlist;

     md1Patientlist.push_back("zoey");
     md1Patientlist.push_back("zander");
     md1Patientlist.push_back("zion");

     // Adding doctor obj and string vector to map obj
     hospitalList.insert({md1,md1Patientlist});


     Doctor md2("Mark",2025);
     std::vector<std::string> md2Patientlist;
     md2Patientlist.push_back("milly");
     md2Patientlist.push_back("moses");
     md2Patientlist.push_back("marten");

      // Adding doctor obj and string vector to map obj
     hospitalList.insert({md2,md2Patientlist});


     Doctor md3("Ravin",2029);
     std::vector<std::string> md3Patientlist;
     md3Patientlist.push_back("robby");
     md3Patientlist.push_back("reba");
     md3Patientlist.push_back("rorey");

     // Adding doctor obj and string vector to map obj
     hospitalList.insert({md3,md3Patientlist});


     for (auto i: hospitalList){
        cout << "Doctor: " << i.pair::first.getName() << '\n';
        cout << "ID: " << i.pair::first.getID() << '\n';
        cout << "Patients: \n";
        for ( auto j: i.pair::second){
            cout << j << '\n';
        }

        cout << '\n';
     }



    return 0;
}
