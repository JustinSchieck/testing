//
//  WeatherEntry.cpp
//  Assignment5-6
//
//  Created by Lucas Schoenardie on 2017-08-08.
//  Copyright © 2017 Lucas Schoenardie. All rights reserved.
//

#include <sstream>
#include <vector>
#include "WeatherEntry.hpp"

using namespace std;

WeatherEntry::WeatherEntry(string row)
{
    stringstream rowStream(row);
    vector<string> line = getNextLineAndSplitIntoTokens(rowStream);
    
    year = line[1];
    month = line[2];
    
    if(line[5] != "") maxTemp = atof(line[5].c_str());
    else maxTemp = 999999999;

}

string WeatherEntry::getYear() {
    return year;
}

string WeatherEntry::getMonth() {
    return month;
}

double WeatherEntry::getMaxTemp() {
    return maxTemp;
}

vector<string> WeatherEntry::getNextLineAndSplitIntoTokens(istream& str)
{
    vector<string> result;
    string line;
    getline(str,line);
    
    stringstream lineStream(line);
    string cell;
    
    while(getline(lineStream,cell, ','))
    {
        // Remove all double-quote characters
        cell.erase(
                   remove( cell.begin(), cell.end(), '\"' ),
                   cell.end()
                   );
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}
