//AMDG
//This program is based on Howard Hinnant's excellent date/time zone library, a similar form of which will become part of C++20. https://github.com/HowardHinnant/date
//The code is based on examples provided by Howard at https://howardhinnant.github.io/date/tz.html . 
//This program also utilizes time zone information from the IANA. https://www.iana.org/time-zones
//In addition, the program uses Unicode's windowsZones.xml file (Copyright © 1991-2013 Unicode, Inc.). https://github.com/unicode-org/cldr/blob/master/common/supplemental/windowsZones.xml
//One significant limitation of the program is that it must be reloaded to update the times. This limitation may be addressed in a future update.
//Special thanks to Richard Davis and Eric Bomgardner for testing out the program on their end
//Kenneth Burchfiel
//First released on 2020-8-18 (US EDT)


#include "date/tz.h"
#include <iostream>

using namespace date;
    using namespace std::chrono;

int main()
{

std::cout << "These times (shown in a 24-hour format) will not update unless the program is reloaded. Time zones were accurate as of 4/2020 but may have changed since then. "; 
std::cout << "Program By Kenneth Burchfiel (MIT License), 8/2020; see Github for sources.\n";

auto local = make_zoned(current_zone(), floor<seconds>(system_clock::now())); //This line comes from https://howardhinnant.github.io/date/tz.html (by Howard E. Hinnant)
    std::cout << "Local time:\t" << local << '\n'; //this code comes essentially from https://howardhinnant.github.io/date/tz.html as well


   auto HNL = make_zoned("Pacific/Honolulu", floor<seconds>(system_clock::now()));
    std::cout << "Honolulu:\t" << HNL << '\n';
   
auto ANC = make_zoned("America/Anchorage", floor<seconds>(system_clock::now()));
    std::cout << "Anchorage:\t" << ANC << '\n';

auto LAX = make_zoned("America/Los_Angeles", floor<seconds>(system_clock::now()));
    std::cout << "Los Angeles:\t" << LAX << '\n';

auto DEN = make_zoned("America/Denver", floor<seconds>(system_clock::now()));
    std::cout << "Denver:\t\t" << DEN << '\n';

auto ORD = make_zoned("America/Chicago", floor<seconds>(system_clock::now()));
    std::cout << "Chicago:\t" << ORD << '\n';

auto BOG = make_zoned("America/Bogota", floor<seconds>(system_clock::now()));
    std::cout << "Bogota:\t\t" << BOG << '\n';

    auto NYC = make_zoned("America/New_York", floor<seconds>(system_clock::now()));
    std::cout << "New York:\t" << NYC << '\n';
    
 auto MAO = make_zoned("America/Manaus", floor<seconds>(system_clock::now())); //Using airport codes for cities
    std::cout << "Manaus:\t\t" << MAO << '\n';

auto GRU = make_zoned("America/Sao_Paulo", floor<seconds>(system_clock::now())); 
    std::cout << "Sao Paulo:\t" << GRU << '\n';

auto UTC = make_zoned("Etc/UTC", floor<seconds>(system_clock::now())); 
    std::cout << "UTC:\t\t" << UTC << '\n';

auto ACC = make_zoned("Africa/Accra", floor<seconds>(system_clock::now())); 
    std::cout << "Accra:\t\t" << ACC << '\n';

auto LHR = make_zoned("Europe/London", floor<seconds>(system_clock::now())); 
    std::cout << "London:\t\t" << LHR << '\n';

    auto LOS = make_zoned("Africa/Lagos", floor<seconds>(system_clock::now()));
    std::cout << "Lagos:\t\t" << LOS<< '\n';

auto BER = make_zoned("Europe/Berlin", floor<seconds>(system_clock::now())); 
    std::cout << "Berlin:\t\t" << BER << '\n';

auto JNB = make_zoned("Africa/Johannesburg", floor<seconds>(system_clock::now())); 
    std::cout << "Johannesburg:\t" << JNB << '\n';

auto ATH = make_zoned("Europe/Athens", floor<seconds>(system_clock::now())); 
    std::cout << "Athens:\t\t" << ATH << '\n';


auto IST = make_zoned("Europe/Istanbul", floor<seconds>(system_clock::now())); 
    std::cout << "Istanbul:\t" << IST << '\n';

auto NBO = make_zoned("Africa/Nairobi", floor<seconds>(system_clock::now())); 
    std::cout << "Nairobi:\t" << NBO << '\n';

auto DXB = make_zoned("Asia/Dubai", floor<seconds>(system_clock::now())); 
    std::cout << "Dubai:\t\t" << DXB << '\n';

auto KHI = make_zoned("Asia/Karachi", floor<seconds>(system_clock::now())); 
    std::cout << "Karachi:\t" << KHI << '\n';

auto DEL = make_zoned("Asia/Kolkata", floor<seconds>(system_clock::now())); 
    std::cout << "Delhi:\t\t" << DEL << '\n'; //Delhi and Kolkata are in the same time zone

auto JKT = make_zoned("Asia/Jakarta", floor<seconds>(system_clock::now())); 
    std::cout << "Jakarta:\t" << JKT << '\n'; 

auto PVG = make_zoned("Asia/Shanghai", floor<seconds>(system_clock::now())); 
    std::cout << "Shanghai:\t" << PVG << '\n'; 

auto NRT = make_zoned("Asia/Tokyo", floor<seconds>(system_clock::now())); 
    std::cout << "Tokyo:\t\t" << NRT << '\n'; 

auto SYD = make_zoned("Australia/Sydney", floor<seconds>(system_clock::now())); 
    std::cout << "Sydney:\t\t" << SYD << '\n'; 

auto AKL = make_zoned("Pacific/Auckland", floor<seconds>(system_clock::now())); 
    std::cout << "Auckland:\t" << AKL << '\n'; 

    /* Edited out so that the program will fit on a Windows console without any scrolling
auto CXI = make_zoned("Pacific/Kiritimati", floor<seconds>(system_clock::now())); 
    std::cout << "Tabwakea:\t" << CXI << '\n'; //The largest village on Kiritimati, according to Wikipedia
    */

char c; //keeps console window open
    std::cin >> c;


}