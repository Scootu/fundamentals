#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Time {
private:
    int _hours, _minutes, _seconds;

public:
    // Constructor with normalization
    Time(int hours, int minutes, int seconds) {
        SetTime(hours, minutes, seconds);
    }

    // Setter with validation and normalization
    void SetTime(int hours, int minutes, int seconds) {
        if (hours < 0 || minutes < 0 || seconds < 0) {
            throw invalid_argument("Invalid time values");
        }
        _hours = hours + (minutes / 60) + (seconds / 3600);
        _minutes = (minutes % 60) + (seconds / 60);
        _seconds = seconds % 60;
    }

    // Getters
    int GetHours() const { return _hours; }
    int GetMinutes() const { return _minutes; }
    int GetSeconds() const { return _seconds; }

    // Total time in seconds
    int GetTotalSeconds() const {
        return _hours * 3600 + _minutes * 60 + _seconds;
    }

    // Total time in minutes
    int GetTotalMinutes() const {
        return _hours * 60 + _minutes;
    }

    // String representation of time
    string ToString(const string &separator = ":") const {
        ostringstream oss;
        oss << _hours << separator << _minutes << separator << _seconds;
        return oss.str();
    }

    // Print time in HH:MM:SS format
    void PrintHHMMSS() const {
        cout << ToString(":") << "\n";
    }
};

int main() {
    Time t(1, 70, 90); // Normalized to 2:11:30
    t.PrintHHMMSS();   // Outputs: 2:11:30
    cout << "Total Seconds: " << t.GetTotalSeconds() << endl;
    return 0;
}
