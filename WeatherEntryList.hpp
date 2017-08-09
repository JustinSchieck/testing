//
//  WeatherEntryList.hpp
//  Assignment5-6
//
//  Created by Lucas Schoenardie on 2017-08-08.
//  Copyright © 2017 Lucas Schoenardie. All rights reserved.
//

#ifndef WeatherEntryList_hpp
#define WeatherEntryList_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>


#include "WeatherEntry.hpp"

class WeatherEntryList {
    
public:
    WeatherEntryList(std::string filePath);
    std::vector<WeatherEntry> getEntries();
    
private:
    std::vector<WeatherEntry> entries;
    
};

#endif /* WeatherEntryList_hpp */
