//
// Created by ivan on 09.06.20.
//

#include "Date.hpp"

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
        return (!(A < B) && !(B < A));
    }

    bool operator !=(Time A, Time B) {
        return !(A == B);
    }

    bool operator >(Time A, Time B) {
        return B < A;
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

    std::string Date::to_string() const {
        return std::to_string(year) + "-" + month_str() + "-" +  std::to_string(day);
    }

    bool operator ==(Date A, Date B) {
        return (!(A < B) && !(B < A));
    }

    bool operator !=(Date A, Date B) {
        return !(A == B);
    }

    bool operator >(Date A, Date B) {
        return B < A;
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
        return (!(A < B) && !(B < A));
    }

    bool operator !=(DateTime A, DateTime B) {
        return !(A == B);
    }

    bool operator >(DateTime A, DateTime B) {
        return B < A;
    }

    std::ostream& operator<<(std::ostream& out, const Time time)
    {
        return out << time.to_string();
    }

    std::ostream& operator<<(std::ostream& out, const Date date)
    {
        return out << date.to_string();
    }
}