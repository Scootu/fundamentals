#include <iostream>
#include <string>
#include <iomanip> // For formatting

class Time
{
private:
    int total_seconds; // Single source of truth

public:
    // Constructor to initialize total_seconds
    Time(int hours = 0, int minutes = 0, int seconds = 0)
    {
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }

    // Set time using hours, minutes, and seconds
    void SetTime(int hours, int minutes, int seconds)
    {
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }

    // Get total seconds
    int GetTotalSeconds() const
    {
        return total_seconds;
    }

    // Get total minutes
    int GetTotalMinutes() const
    {
        return total_seconds / 60;
    }

    // Print time in HH:MM:SS format
    void PrintHHMMSS(const std::string &separator = ":") const
    {
        int hours = total_seconds / 3600;
        int minutes = (total_seconds % 3600) / 60;
        int seconds = total_seconds % 60;
        std::cout << std::setfill('0') << std::setw(2) << hours << separator
                  << std::setfill('0') << std::setw(2) << minutes << separator
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }

    // Getter and Setter for Hours
    int GetHours() const
    {
        return total_seconds / 3600;
    }
    void SetHours(int hours)
    {
        int minutes = (total_seconds % 3600) / 60;
        int seconds = total_seconds % 60;
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }
    // Getter and Setter for Minutes
    int GetMinutes() const
    {
        return (total_seconds % 3600) / 60;
    }

    void SetMinutes(int minutes)
    {
        int hours = total_seconds / 3600;
        int seconds = total_seconds % 60;
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }

    // Getter and Setter for Seconds
    int GetSeconds() const
    {
        return total_seconds % 60;
    }

    void SetSeconds(int seconds)
    {
        int hours = total_seconds / 3600;
        int minutes = (total_seconds % 3600) / 60;
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }
};

int main()
{
    Time t(1, 30, 45);
    t.PrintHHMMSS();
    return 0;
}