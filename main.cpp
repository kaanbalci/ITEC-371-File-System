//------------------------------------------------------------------------------------------------|
// -------------------------------- Kaan Balci ITEC 371 project 1 --------------------------------|
// ----------- Note* was not able to finish project fully turned in last working build i had -----|
//------------------------------------------------------------------------------------------------|
//------------------------------------------------------------------------------------------------|
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

using namespace std;

//-------------------------------------------------------------------------------|
//----------------------globals -------------------------------------------------|
//-------------------------------------------------------------------------------|
char directory[8];
char filename[12];
string contents;
int CPU;
int MEM;
int NUM_FILES = 0;


//-------------------------------------------------------------------------------|
//-------------------function prototypes ----------------------------------------|
//-------------------------------------------------------------------------------|
void CreateDir();
void CreateFile();
void EndDir();


//-----------------------------------------------------------------------------------------|
// here the prompt is given with choices to create directory, file, end dir or quit -------|
// while loop until option quit is chosen. If statement to differentiate input and then ---|
// call respective function ---------------------------------------------------------------|
//-----------------------------------------------------------------------------------------|
int main(int argc, char *argv[])
{

    string choice;

    while(choice != "Quit") {

        cout << "\n\t Welcome to RUFS creator. Enter a command";
        cout << "\n\t CreateDir or CreateFile or EndDir Quit\n\n\t";

        cin >> choice;

        if (choice == "CreateDir") {
            CreateDir();
        } else if (choice == "CreateFile") {
            CreateFile();
        } else if (choice == "EndDir") {
            EndDir();
        } else if (choice == "Quit") {
            cout << "\n\t Root.d\n\n\t";
            if(filename[13] = 'p') {
                cout << filename;
                cout << "\n\t CPU Req: " << CPU;
                cout << "\n\t Memory Req: " << MEM;
            }



        } else {
            "\n\tInvalid Input!";
        }

    }
    return 0;
}
//------------------------------------------------------------------------------|
// Create directory function that uses mkdir to create a directory -------------|
//------------------------------------------------------------------------------|

void CreateDir()
{
    cout << "Enter Directory Name\n\t";
    cin >> directory;
    mkdir(directory,0755);

}
//------------------------------------------------------------------------------|
// CreateFile function using cin and checking weather it is a .p or .t format --|
//------------------------------------------------------------------------------|

void CreateFile()
{
    try
    {
        cout << "\n\tEnter Filename\n\n\t";
        cin >> filename;
        ofstream DATAFILE;
        //------------------------------------------------------------------------------|
        //bitwise "or" to output files in binary using ios::binary call ----------------|
        //------------------------------------------------------------------------------|
        DATAFILE.open(filename, ios::out | ios::binary);
        if(filename[13] = 't')
        {
            cout << "\n\tEnter contents of file\n\n\t";
            cin >> contents;
            DATAFILE << contents;
            rename(filename, directory);

        }
        else if(filename[13]= 'p'){
            cout << "\n\tEnter CPU requirements\n\n\t";
            cin >> CPU;
            cout << "\n\tEnter CPU requirements\n\n\t";
            cin >> MEM;
            DATAFILE << CPU;
            DATAFILE << "\n";
            DATAFILE << MEM;
        }
        else{
            cout << "Enter filename with .p or .t!\n\n\t";
        }

        DATAFILE.write((char *) filename, sizeof(*filename));
        DATAFILE.close();
        NUM_FILES++;

    }
    catch(exception X)
    {
        cout << "\n\tERROR!";
    }
}
//------------------------------------------------------------------------------|


void EndDir()
{

}

//------------------------------------------------------------------------------|
