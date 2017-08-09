//
//  WeatherEntry.hpp
//  Assignment5-6
//
//  Created by Lucas Schoenardie on 2017-08-08.
//  Copyright © 2017 Lucas Schoenardie. All rights reserved.
//

#ifndef WeatherEntry_hpp
#define WeatherEntry_hpp

#include <iostream>
#include <stdio.h>

class WeatherEntry {
    
public:
    WeatherEntry(std::string row);
    std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);
    std::string getYear();
    std::string getMonth();
    double getMaxTemp();

private:
    std::string year, month;
    double maxTemp;
};

#endif /* WeatherEntry_hpp */
