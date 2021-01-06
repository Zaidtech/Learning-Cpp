#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Distance{
    private:
        float feet;
        float inches;
    public: 
        void Inputs(){
            cout <<"\nEnter feet : ";
            cin >>feet;
            cout <<"\nEnter inches : ";
            cin >> inches;
            if(inches >12.0)
            {
                feet = feet+ int((inches/12)); // performing a type cast
                inches = inches - int((inches/12));
            }
        }
        float  Feet(){
            return feet;
        } 
        float Inch(){
            return inches; 
        }
}; 

int  main(){
    int number = 0;
    cout << "Enter the number of Distance obj to be created: ";
    cin >> number;
    Distance distance_obj[number];
    for(int i =0;i<number;i++) distance_obj[i].Inputs();

    ofstream Open_file("Distance.txt", ios::out|ios::app);

    // Iterate over  the obj and apend(app) value to the file  
    for(int i=0;i<number;i++){
        Open_file << "Feet : " << distance_obj[i].Feet() << "   "<<"Inches: " << distance_obj[i].Inch() << " \n";
    }

    Open_file.close();
    string line;
    ifstream reader; 
    // by default open mode = ios::in mode 
    reader.open("Distance.txt"); 
    // Execute a loop until EOF (End of File) 
    while (reader) { 
        // Read a Line from File 
        getline(reader,line); 
        // Print line to Console 
        cout << line << endl; 
    } 
       // Close the file 
    reader.close(); 
    return 0; 
} 