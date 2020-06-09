//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_DATE_HPP
#define OOP_EXAM_DATE_HPP

#include <iostream>
#include <iomanip>
#include <string>

namespace date_time {
    enum Month {
        Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };

    class Date {
    private:
        int year;
        Month month;
        int day;
        std::string month_str() const {
            switch (month) {
                case Jan:
                    return "Jan";
                case Feb:
                    return "Feb";
                case Mar:
                    return "Mar";
                case Apr:
                    return "Apr";
                case Jun:
                    return "Jun";
                case Jul:
                    return "Jul";
                case Aug:
                    return "Aug";
                case Sep:
                    return "Sep";
                case Oct:
                    return "Oct";
                case Nov:
                    return "Nov";
                case Dec:
                    return "Dec";
                case May:
                    return "May";
            }
        }
    public:
        std::string to_string() const {
            return std::to_string(year) + "-" + month_str() + "-" +  std::to_string(day);
        }
        Date(int _year = 0, Month _month = Month(0), int _day = 1975): year(_year), month(_month), day(_day){}
    };
   /* inline std::ostream& operator<<(std::ostream& out, const Date date)
    {
        return out << date.to_string();
    }*/
    class Time {
        int hours;
        int minutes;
        int seconds;
    public:
        Time(int _hours = 0 , int _minutes = 0, int _sec = 0): hours(_hours), minutes(_minutes), seconds(_sec){}
        std::string to_string() const {
           std::string res;
           if (hours < 10)
               res += '0';
           res += std::to_string(hours);
           res += ':';
           if (minutes < 10)
               res += '0';
           res += std::to_string(minutes);
           res += ':';
           if (seconds < 10)
               res += '0';
           res += std::to_string(seconds);
           return res;
        }
    };
  /*  inline std::ostream& operator<<(std::ostream& out, const Time time)
    {
        return out << time.to_string();
    }*/

    class DateTime {
    private:
        Date date;
        Time time;
    public:
        DateTime(int year, Month month, int day, int hours, int minutes, int seconds) {
            date = Date(year, month, day);
            time = Time(hours, minutes, seconds);
        }
        std::string to_string() const {
            return date.to_string() + " " + time.to_string();
        }
    };

  /*  inline std::ostream& operator<<(std::ostream& out, const DateTime time)
    {
        return out << time.to_string();
    }*/
}

#endif //OOP_EXAM_DATE_HPP
