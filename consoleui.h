#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "legendService.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
private:
    LegendService _service;
    void sort(char command, vector<Legend>& legends);
    void CommandList();
    void CommandFind();
    void CommandDelete();
    void displayCommands();
    bool checkName(string name, bool flag);
    string getName(string name);
    char getGender(char gender);
    int getBorn(int born);
    int getDeath(int death, int born);
    void commandAdd();
};

#endif // CONSOLEUI_H
