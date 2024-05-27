#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string getCurrentTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", ltm);
    return string(timeStr);
}

string getCurrentDay()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char dayStr[10];
    strftime(dayStr, sizeof(dayStr), "%A", ltm);
    return string(dayStr);
}

string getWeather()
{
    return "It's sunny and 25 degrees Celsius.";
}

int main()
{
    string userInput;
    string botName = "ChatBot";
    string userName;

    cout << "Hello! I'm " << botName << ". What's your name?" << endl;
    getline(cin, userName);

    cout << "Nice to meet you, " << userName << "!" << endl;;

    while(true)
    {
        cout << "You : ";
        getline(cin, userInput);

        for(char &c : userInput)
        {
            c = tolower(c);
        }

        if(userInput == "hi" || userInput == "hello")
        {
            cout << botName << " : Hello, " << userName << "! How can I help you today?" << endl;
        }
        else if (userInput == "how are you?" || userInput == "how are you")
        {
            cout << botName << " : I'm just a bunch of code, but I'm functioning as expected! How about you?" << endl;
        }
        else if (userInput == "I am fine" || userInput == "I'm fine" || userInput == "fine")
        {
            cout << botName << " : That's sounds good." << endl;
        }
        else if (userInput == "what's the time?" || userInput == "what time is it?" || userInput == "time")
        {
            cout << botName << " : The current time is " << getCurrentTime() << "." << endl;
        }
        else if (userInput == "what's the day?" || userInput == "what day is it?" || userInput == "day")
        {
            cout << botName << " : Today is " << getCurrentDay() << "." << endl;
        }
        else if (userInput == "what's the weather?" || userInput == "weather")
        {
            cout << botName << " : " << getWeather() << "." << endl;
        }
        else if (userInput == "bye" || userInput == "exit")
        {
            cout << botName << " : Goodbye, " << userName << "! Have a great day!" << endl;
            break;
        }
        else
        {
            cout << botName << " : I'm sorry, I didn't understand that." << endl;
        }
    }

    return 0;
}