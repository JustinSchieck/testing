//
//  WeatherEntryList.cpp
//  Assignment5-6
//
//  Created by Lucas Schoenardie on 2017-08-08.
//  Copyright © 2017 Lucas Schoenardie. All rights reserved.
//

#include "WeatherEntryList.hpp"

using namespace std;

WeatherEntryList::WeatherEntryList(string file)
{
    ifstream weatherFile(file);
    
    string lineContents;
    while (!weatherFile.eof())
    {
        getline(weatherFile, lineContents);
        
        WeatherEntry entry(lineContents);
        entries.push_back(entry);
    }
    weatherFile.close();
}

vector<WeatherEntry> WeatherEntryList::getEntries() {
    return entries;
};
