#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

std::vector<Time> readDates() {
    std::vector<Time> dates;
    std::string line;
    while (std::getline(std::cin, line) && line != "*") {
        std::istringstream iss(line);
        Time date;
        char dash;
        iss >> date.year >> dash >> date.month >> dash >> date.day;
        dates.push_back(date);
    }
    return dates;
}

Time parseTime(const std::string& timeStr) {
    Time time;
    std::istringstream iss(timeStr);
    char dash, colon;
    iss >> time.year >> dash >> time.month >> dash >> time.day >> time.hour >> colon >> time.minute >> colon >> time.second;
    return time;
}

std::string formatTime(const Time& time) {
    std::ostringstream oss;
    oss << time.year << "-" << std::setfill('0') << std::setw(2) << time.month << "-" << std::setw(2) << time.day
        << " " << std::setw(2) << time.hour << ":" << std::setw(2) << time.minute << ":" << std::setw(2) << time.second;
    return oss.str();
}

Time addDuration(const Time& startTime, int duration) {
    Time endTime = startTime;
    endTime.second += duration;
    endTime.minute += endTime.second / 60;
    endTime.second %= 60;
    endTime.hour += endTime.minute / 60;
    endTime.minute %= 60;
    endTime.day += endTime.hour / 24;
    endTime.hour %= 24;
    return endTime;
}

int main() {
    freopen("15.txt", "r", stdin);
    std::vector<Time> dates = readDates();

    std::string line;
    while (std::getline(std::cin, line) && line != "***") {
        Time startTime = parseTime(line);
        int duration;
        std::cin >> duration;
        std::cin.ignore();

        int dayIndex = (startTime.year - dates[0].year) * 365 + (startTime.month - dates[0].month) * 30 + (startTime.day - dates[0].day);
        Time endDate = addDuration(dates[dayIndex], duration);
        std::cout << formatTime(endDate) << std::endl;
    }

    return 0;
}