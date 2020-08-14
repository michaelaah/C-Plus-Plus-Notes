#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
/*
 * This is the Doctor header file for creating a Doctor class.
 * This serves as the class blue print of the object we wish to
 * implement (which is then implemented in the Object.cpp file).
 * In this file, the Doctor functions are only declared and not
 * implemented. They are implemented in the Doctor.cpp file.
*/
class Doctor
{
    // Public interface functions
    public:

        // Constructors and a Destructor
        Doctor();
        Doctor (std::string);
        Doctor (std::string, int);
        ~Doctor();

        // Class getters and setters
        std::string getName() const;
        void setName(std::string);

        int getID() const;
        void setID(int);

        int compare(Doctor);

        // To use an object in a map, this function must be overridden
        bool operator<(const Doctor &doc1) const;

        std::string conver(){
            return "I am the public interface.";
        }

    // Private members
    private:
        std::string name;
        int id;

};

#endif // DOCTOR_H
