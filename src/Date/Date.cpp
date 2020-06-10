//
// Created by ivan on 09.06.20.
//

#include "Date.hpp"

#include <map>

namespace date_time {
    std::ostream& operator<<(std::ostream& out, const DateTime time)
    {
        return out << time.to_string();
    }

    bool operator <(Time A, Time B) {
        if (A.hours != B.hours)
            return A.hours < B.hours;
        if (A.minutes != B.minutes)
            return A.minutes < B.minutes;
        return A.seconds < B.hours;
    }

    std::string Time::to_string() const {
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

    bool operator ==(Time A, Time B) {
        return A.hours == B.hours &&
                A.minutes == B.minutes &&
                A.seconds == B.seconds;
    }

    bool operator !=(Time A, Time B) {
        return !(A == B);
    }

    bool operator >(Time A, Time B) {
        return B < A;
    }

    int Time::toInt() const {
        return hours*3600 + minutes*60 + seconds;
    }

    bool operator <(Date A, Date B) {
        if (A.year != B.year)
            return A.year < B.year;
        if (A.month != B.month)
            return A.month < B.month;
        return A.day < B.day;
    }

    std::string Date::month_str() const {
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

    int Date::month_int() const {
        switch (month) {
            case Jan:
                return 0;
            case Feb:
                return 1;
            case Mar:
                return 2;
            case Apr:
                return 3;
            case Jun:
                return 4;
            case Jul:
                return 5;
            case Aug:
                return 6;
            case Sep:
                return 7;
            case Oct:
                return 8;
            case Nov:
                return 9;
            case Dec:
                return 10;
            case May:
                return 11;
        }
    }

    std::string Date::to_string() const {
        return std::to_string(year) + "-" + month_str() + "-" +  std::to_string(day);
    }

    bool operator ==(Date A, Date B) {
        return A.day == B.day &&
                A.month == B.month &&
                A.year == B.year;
    }

    bool operator !=(Date A, Date B) {
        return !(A == B);
    }

    bool operator >(Date A, Date B) {
        return B < A;
    }

    int Date::toInt() const {
        std::map<Month, int> days = {{Jan, 31}, {Feb, 28}, {Mar, 31}, {Apr, 30}, {May, 31}, {Jun, 30}, {Jul, 31}, {Aug, 31}, {Sep, 30}, {Oct, 31}, {Nov, 30}, {Dec, 31}};
        return year*31556926 +days[month]*86400 + day*86400;
    }

    bool operator <(DateTime A, DateTime B) {
        if (A.date != B.date)
            return A.date < B.date;
        return A.time < B.time;
    }

    DateTime::DateTime(int year, Month month, int day, int hours, int minutes, int seconds) {
        date = Date(year, month, day);
        time = Time(hours, minutes, seconds);
    }

    std::string DateTime::to_string() const {
        return date.to_string() + " " + time.to_string();
    }

    bool operator ==(DateTime A, DateTime B) {
        return A.date == B.date && A.time == B.time;
    }

    bool operator !=(DateTime A, DateTime B) {
        return !(A == B);
    }

    bool operator >(DateTime A, DateTime B) {
        return B < A;
    }

    int DateTime::toInt() const {
        return date.toInt() + time.toInt();
    }

    std::ostream& operator<<(std::ostream& out, const Time time)
    {
        return out << time.to_string();
    }

    std::ostream& operator<<(std::ostream& out, const Date date)
    {
        return out << date.to_string();
    }

    std::vector<int> DateTime::to_vector(){
        auto dateVector = date.to_vector();
        auto timeVector = time.to_vector();
        return {dateVector[0], dateVector[1], dateVector[2], timeVector[0], timeVector[1], timeVector[2]};
    }

    std::vector<int> Date::to_vector(){
        return {year, month_int(), day};
    }

    std::vector<int> Time::to_vector(){
        return { hours, minutes, seconds};
    }
}
