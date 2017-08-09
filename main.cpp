//
//  main.cpp
//  Assignment5-6
//
//  Created by Lucas Schoenardie on 2017-08-07.
//  Copyright © 2017 Lucas Schoenardie. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "WeatherEntryList.hpp"
#include "WeatherEntry.hpp"

using namespace std;

void displayInvalidSelection();
void displayMenu();
string getUsersFileName();
int getInteger();
int getProblem();

void processFile(vector<WeatherEntryList> &list);

void displayAvgByMonth(WeatherEntryList &entries, string month);

vector<WeatherEntryList> list;




int main(int argc, const char * argv[]) {
    
    int userSelection;
    
    do {
        userSelection = getProblem();
        
        while (userSelection < 1 || userSelection > 3) {
            displayInvalidSelection();
            userSelection = getInteger();
        }
        
        switch (userSelection) {
            case 1:
                processFile(list);
                break;
            case 2:
                cout << "2" << endl;
                break;
            case 3:
                break;
            default:
                cout << "Sorry, something went wrong\n\n";
                break;
        }
        
    }
    while(userSelection != 3);
    
    std::cout << std::endl;

    
//    WeatherEntryList list("/Users/lberteh/Desktop/2014-Barrie-Oro-Daily.csv");
//    
//    cout << list.getEntries()[1].getMaxTemp() << endl;
    
   
//    ifstream fileStream("/Users/lberteh/Desktop/2014-Barrie-Oro-Daily.csv");
//    
//    if(fileStream.fail()) cout << "Error, could not open file" << endl;
//    
//    vector<string> row;
//    vector<vector<string>> allRows;
//    vector<vector<string>> monthly;
//    
//    while(!fileStream.eof()){
//        
//        row = getNextLineAndSplitIntoTokens(fileStream);
//        allRows.push_back(row);
//        
//    }
//    
//    copy_if (allRows.begin(), allRows.end(), back_inserter(monthly),
//             [](vector<string> row){
//                                       return atoi(row[2].c_str()) == 1;
//                                   } );
//    
//    int count = 0;
//    
//    for(auto n : monthly) {
//        
//        if (n[5] == "") count++;
//        // cout << n[2] << " - " << n[5] << endl;
//    }
//    
//    
//    cout << "(" << count << " out of " << monthly.size() << ")" << endl;

    
    return 0;
}

int getProblem()
{
    displayMenu();
    return getInteger();
}

void displayMenu()
{
    const char *menuText =
    
    R"PREFIX(
Please make a selection from the following:
    
(1)Open a Climate File to Process
(2)Save the Climate Data
(3)Exit
    
>>>>> )PREFIX";
        
    cout << menuText;
}

// helper functions

int getInteger()
{
    int userInput;
    cin >> userInput;
    while(cin.fail()) {
        displayInvalidSelection();
        cin.clear();
        cin.ignore(256,'\n');
        cin >> userInput;
    }
    cin.ignore(256,'\n');
    return userInput;
}

void displayInvalidSelection()
{
    cout << "\nInvalid Input, please try again! \n\n>>>>> ";
}

// Option 1
bool fileOpened(string fileName) {
    ifstream stream(fileName);
    
    if(stream.fail()){
        return false;
    }
    else {
        stream.close();
        return true;
    }
    
}

void processFile(vector<WeatherEntryList> &list) {
    
    string fileName = getUsersFileName();
   
    while(!fileOpened(fileName)){
        cout << "File not found\n";
        fileName = getUsersFileName();
        fileOpened(fileName);
    }
    
    WeatherEntryList entries(fileName);
    list.push_back(entries);
    string months[] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
    cout << endl;
    for(int i = 0; i < 12; i++)
        displayAvgByMonth(entries, months[i]);
        

}

string getUsersFileName() {
    cin.clear();
    string fileName;
    cout << "Enter file name you wish to open: ";
    getline(cin, fileName);
    while(fileName.empty()){
        cout << "\nFile name can't be null. Please enter a valid file name.\n";
        cout << "Enter file name you wish to open: ";
        getline(std::cin, fileName);
    }
    cin.clear();
    return fileName;
}

void displayAvgByMonth(WeatherEntryList &entries, string month) {
    
    vector<WeatherEntry> monthly;
    
    for(int i = 0; i < entries.getEntries().size(); i++){
            if(entries.getEntries()[i].getMonth() == month)
                monthly.push_back(entries.getEntries()[i]);
    }
    
    int count = 0;
    
    double sum = 0;
    
    for(auto n : monthly) {
        if (n.getMaxTemp() == 999999999)
            count++;
        else {
            sum += n.getMaxTemp();
        }
    }
    
    string mon = "";
    
    switch (stoi(month)) {
        case 1:
            mon = "Jan";
            break;
        case 2:
            mon = "Feb";
            break;
        case 3:
            mon = "Mar";
            break;
        case 4:
            mon = "Apr";
            break;
        case 5:
            mon = "May";
            break;
        case 6:
            mon = "Jun";
            break;
        case 7:
            mon = "Jul";
            break;
        case 8:
            mon = "Aug";
            break;
        case 9:
            mon = "Sep";
            break;
        case 10:
            mon = "Oct";
            break;
        case 11:
            mon = "Nov";
            break;
        case 12:
            mon = "Dec";
            break;

        default:
            break;
    }
    
    cout << mon << ": " << sum/(monthly.size()-count) << " (" << count << " of " << monthly.size() << ")" << endl;
    
}

