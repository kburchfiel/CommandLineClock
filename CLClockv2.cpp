//AMDG
//This program is based on Howard Hinnant's excellent date/time zone library, a similar form of which will become part of C++20. https://github.com/HowardHinnant/date
//The code is based on examples provided by Howard at https://howardhinnant.github.io/date/tz.html . 
//This program also utilizes time zone information from the IANA. https://www.iana.org/time-zones
//In addition, the program uses Unicode's windowsZones.xml file (Copyright © 1991-2013 Unicode, Inc.). https://github.com/unicode-org/cldr/blob/master/common/supplemental/windowsZones.xml
//Christopher Oicles's explanation of getting localtime_s to work (https://stackoverflow.com/a/35260146/13097194) proved invaluable.
//Special thanks to Richard Davis and Eric Bomgardner for testing out the program on their end
//Kenneth Burchfiel
//First released on 2020-8-18 (US EDT)

#include "date/tz.h"
#include <iostream>
#include <thread>
#include <iomanip>

using namespace date;
    using namespace std::chrono;

    void updatetimes()
    {
        std::cout << "\n"; //Helps ensure that the following introductory statements are readable within the console during subsuquent calls of updatetimes()
        std::cout << "These times will update every minute. Time zones were accurate as of 4/2020 but may have changed since then.\n";
        std::cout << "ConsoleWorldClock by Kenneth Burchfiel (MIT License), 8/2020; see .cpp file on Github for sources.\n";

        auto sc1 = system_clock::now(); //Using the same system_clock::now() return value (sc1) for all time zone entries prevents the program from displaying different second counts for different cities.
        
        auto local = make_zoned(current_zone(), floor<minutes>(sc1)); //A number of lines in this code come from either https://howardhinnant.github.io/date/date.html or https://howardhinnant.github.io/date/tz.html (both by Howard E. Hinnant)
 
        std::cout << "Local time:\t" << format("%I:%M %p %Z on %F", local) << '\n'; //http://www.cplusplus.com/reference/iomanip/put_time/ was a useful reference for specifiers like %R and %F. This code will output in the format "Local time:     11:11 PM EDT on 2020-08-18" with EDT replaced by the user's local time zone code. For 24-hour time, use %R instead of %I:%M %p.

        auto HNL = make_zoned("Pacific/Honolulu", floor<minutes>(sc1));
        std::cout << "Honolulu:\t" << format("%I:%M %p %Z on %F", HNL) << '\n';

        auto ANC = make_zoned("America/Anchorage", floor<minutes>(sc1));
        std::cout << "Anchorage:\t" << format("%I:%M %p %Z on %F", ANC) << '\n';

        auto LAX = make_zoned("America/Los_Angeles", floor<minutes>(sc1));
        std::cout << "Los Angeles:\t" << format("%I:%M %p %Z on %F", LAX) << '\n';

        auto DEN = make_zoned("America/Denver", floor<minutes>(sc1));
        std::cout << "Denver:\t\t" << format("%I:%M %p %Z on %F", DEN) << '\n';

        auto ORD = make_zoned("America/Chicago", floor<minutes>(sc1));
        std::cout << "Chicago:\t" << format("%I:%M %p %Z on %F", ORD) << '\n';

        auto BOG = make_zoned("America/Bogota", floor<minutes>(sc1));
        std::cout << "Bogota:\t\t" << format("%I:%M %p %Z on %F", BOG) << '\n';

        auto NYC = make_zoned("America/New_York", floor<minutes>(sc1));
        std::cout << "New York:\t" << format("%I:%M %p %Z on %F", NYC) << '\n';

        auto MAO = make_zoned("America/Manaus", floor<minutes>(sc1)); //Using airport codes for cities
        std::cout << "Manaus:\t\t" << format("%I:%M %p %Z on %F", MAO) << '\n';

        auto SCL = make_zoned("America/Santiago", floor<minutes>(sc1));
        std::cout << "Santiago:\t" << format("%I:%M %p %Z on %F", SCL) << '\n';

        auto GRU = make_zoned("America/Sao_Paulo", floor<minutes>(sc1));
        std::cout << "Sao Paulo:\t" << format("%I:%M %p %Z on %F", GRU) << '\n';

        auto UTC = make_zoned("Etc/UTC", floor<minutes>(sc1));
        std::cout << "UTC:\t\t" << format("%I:%M %p %Z on %F", UTC) << '\n';

        auto ACC = make_zoned("Africa/Accra", floor<minutes>(sc1));
        std::cout << "Accra:\t\t" << format("%I:%M %p %Z on %F", ACC) << '\n';

        auto LHR = make_zoned("Europe/London", floor<minutes>(sc1));
        std::cout << "London:\t\t" << format("%I:%M %p %Z on %F", LHR) << '\n';

        auto LOS = make_zoned("Africa/Lagos", floor<minutes>(sc1));
        std::cout << "Lagos:\t\t" << format("%I:%M %p %Z on %F", LOS) << '\n';

        auto BER = make_zoned("Europe/Berlin", floor<minutes>(sc1));
        std::cout << "Berlin:\t\t" << format("%I:%M %p %Z on %F", BER) << '\n';

        auto JNB = make_zoned("Africa/Johannesburg", floor<minutes>(sc1));
        std::cout << "Johannesburg:\t" << format("%I:%M %p %Z on %F", JNB) << '\n';

        auto ATH = make_zoned("Europe/Athens", floor<minutes>(sc1));
        std::cout << "Athens:\t\t" << format("%I:%M %p %Z on %F", ATH) << '\n';

        auto IST = make_zoned("Europe/Istanbul", floor<minutes>(sc1));
        std::cout << "Istanbul:\t" << format("%I:%M %p %Z on %F", IST) << '\n';

        auto NBO = make_zoned("Africa/Nairobi", floor<minutes>(sc1));
        std::cout << "Nairobi:\t" << format("%I:%M %p %Z on %F", NBO) << '\n';

        auto DXB = make_zoned("Asia/Dubai", floor<minutes>(sc1));
        std::cout << "Dubai:\t\t" << format("%I:%M %p %Z on %F", DXB) << '\n';

        auto KHI = make_zoned("Asia/Karachi", floor<minutes>(sc1));
        std::cout << "Karachi:\t" << format("%I:%M %p %Z on %F", KHI) << '\n';

        auto DEL = make_zoned("Asia/Kolkata", floor<minutes>(sc1));
        std::cout << "Delhi:\t\t" << format("%I:%M %p %Z on %F", DEL) << '\n'; //Delhi and Kolkata are in the same time zone

        auto JKT = make_zoned("Asia/Jakarta", floor<minutes>(sc1));
        std::cout << "Jakarta:\t" << format("%I:%M %p %Z on %F", JKT) << '\n';

        auto PVG = make_zoned("Asia/Shanghai", floor<minutes>(sc1));
        std::cout << "Shanghai:\t" << format("%I:%M %p %Z on %F", PVG) << '\n';
              
        auto NRT = make_zoned("Asia/Tokyo", floor<minutes>(sc1));
        std::cout << "Tokyo:\t\t" << format("%I:%M %p %Z on %F", NRT) << '\n';

        auto SYD = make_zoned("Australia/Sydney", floor<minutes>(sc1));
        std::cout << "Sydney:\t\t" << format("%I:%M %p %Z on %F", SYD) << '\n';

        auto AKL = make_zoned("Pacific/Auckland", floor<minutes>(sc1));
        std::cout << "Auckland:\t" << format("%I:%M %p %Z on %F", AKL);
                
    }

int main()
{
    
    updatetimes(); // The function is called immediately in order to avoid a blank screen before the if statement within the following while() loop returns true
while (true)
{
    //The code prior to the if statement determines the current time in GMT format. The while statement will use this time to run the updatetimes() function at the start of each new minute (in clock terms) rather than simply every 60 seconds.

    time_t timet1;
    time(&timet1); //http://www.cplusplus.com/reference/ctime/time/ was helpful
    tm currenttime;
    gmtime_s(&currenttime, &timet1); //Since only the seconds component of the time is necessary, it should not matter whether gmtime_s or localtime_s is used
    if (currenttime.tm_sec == 0) //If it's the start of a new minute
    {
        updatetimes(); //Each update of the updatetimes() function removes the previous update's text from view
        std::this_thread::sleep_for(std::chrono::milliseconds(1500)); //Without this line, the updatetimes() function would continue to run as long as the seconds counter on the clock was 0. Any number of milliseconds between 1000 and ~58000 would probably work; the goal is simply to make the thread sleep until currenttime.tm_sec does not equal 0.
    }
   else std::this_thread::sleep_for(std::chrono::milliseconds(100)); //Without this line, time() and gmtime_s() would run continuously, using lots of processor capacity. This line ensures that they run only ~10 times per second. The higher the millisecond count, the longer the potential delay between the arrival of a new minute and the call of updatetimes(); the lower the count, the greater the load on the processor. (If the millisecond count is set above 1000, there's a chance that the code will 'skip' a minute.) Choosing 100 here was somewhat arbitrary, but limiting the maximum updatetimes() call delay to around .1 seconds seemed reasonable.
    //Using a time trigger (https://docs.microsoft.com/en-us/windows/win32/taskschd/time-trigger-example--c---) would be a more sophisticated solution, but such sophistication is probably not warranted in the case of this simple program.
}



}