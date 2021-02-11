#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

void menu1();
void menu2();
void listoffiles();
void mergefiles(int number);
void writefilelist();

int main()
{
    menu1();
    return 0;
}

void menu1()
{
    // Simple menu with option choosing via switch-case
    system("cls"); // Works on Microsoft Windows only
    cout << "Choose action: " << endl << "1. Create list of files" << endl << "2. Merge files" << endl << "3. Show File List" << endl << "4. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        listoffiles();
        break;
    case 2:
        menu2();
        break;
    case 3:
        writefilelist();
        break;
    case 4:
        exit(1);
        break;
    default:
        cout << "Wrong choice. Choose number from 1 to 4.";
    }
}

void menu2()
{
    // Another simplistic menu but with if instead of switch
    system("cls"); // Works on Microsoft Windows only
    cout << "Write how many files do you want to merge or write 0 to exit to main menu" << endl;
    int choice;
    cin >> choice;
    if (choice == 0)
        menu1();
    else
        mergefiles(choice);
}

void listoffiles()
{
    system("cls"); // Works on Microsoft Windows only
    system("dir /a-d /b > filelist.txt"); // creates list.txt files and writes all files in current directory into it
    cout << "List of files created.";
    menu1();
}

void mergefiles(int number)
{
    system("cls"); // Works on Microsoft Windows only
    ofstream mergedfile("MergedFiles.txt"); // creates file that will store merge result
    cout << endl << "Write names of files you want to merge (example.txt) and confirm each with ENTER" << endl;
    string filename; // creates variable that will store all names of files that will be merged (one by one)
    for (int i = 0; i <= number; i++)
    {
        cout << i + 1 << ": ";
        cin >> filename;
        fstream file("<<filename<<"); // opens file of current number
        string filecontent;
        noskipws(file); // considers things such as tab spaces, carriage returns whitespaces
        if (file.is_open())
        {
            //this loop puts content of current inde file into our merged file
            while (file)
            {
                getline(file, filecontent);
                mergedfile << filecontent;
            }
            file.close();
        }
        else
        {
            cout << endl << "Wrong file name (number " << i << ") !";
        }
    }
    mergedfile.close();
}

void writefilelist()
{
    system("cls"); // Works on Microsoft Windows only
    fstream list("filelist.txt"); // open filelist.txt
    if (!list) //if can't open filelist.txt do this instead
    {
        listoffiles(); // call function to create filelist.txt
        fstream list("filelist.txt"); // and open it
    }
    string listcontent;
    cout << endl << "Found following files: " << endl;
    if (list.is_open())
    {
        // outputs content of filelist.txt in console
        while (getline(list, listcontent))
            cout << listcontent << endl;
    }
    list.close();
    system("PAUSE");
    menu1();
}
