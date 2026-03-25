/*
Здесь я продумаю архитектуру моего проекта. 
1. Хорошо сначала нужно определиться с первыми состояниями которые будет иметь задача. 
2. Потом с архитектурой, а именно сколько файлов в первом этапе, потом что и тд.
3. И исполнение

Я тут подумал что мой этот проект будет иметь больше версий, потому что я тут подумал что я хочу попробовать его развивать 
так что мне потребуется сразу определиться с версиями.
В первой версии я хочу сделать базу, типу состояния первые задать, также первые 4 команды, и как будет само исполнения
и все пока что писать в одном файле main.cpp
Во второй версии я уже подумывал расширить и состояния и команды, и попробовать использовать уже .h (header file)
В третьей версии я уже буду работать над более детальной структурой и версии задач, по типу description и другие более
complicated вещи, и буду упрощать структуру, добавлю доп файлы, также подключу фичи.
Но начиная уже с 3 и более версией я врядли буду заниматься до лета, потому что мне нужно научиться а усложнять я буду
только когда наберусь опыта и улучшу уже там все проекты.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    int id;
    string title; 
    string description;
    string status;
};

vector<Task> Tasks;

void addTask(const string& title){}
void deleteTask(){}
void updateTask(){}
void listTasks(){}
void saveTasks(){}
int getId(){}

int main(int argc, const char* argv[]){

    //

    return 0;
}

void addTask(string& title){
    Task newTask;
    newTask.id = getId();
    newTask.title = title;
    newTask.description = "";
    newTask.status = "todo";
    Tasks.push_back(newTask);
}
void deleteTask(string& title){
    for (int i = 0; i < Tasks.size(); i++){
        if (title == Tasks[i].title){
            Tasks.erase(Tasks.begin() + i);
        }
    }
}
void updateTaskT(string& o_title, string& n_title){
    for (int i = 0; i < Tasks.size(); i++){
        if (o_title == Tasks[i].title){
            Tasks[i].title = n_title;
        }
    }
}
void updateTaskD(string& title, string& description){
    for (int i = 0; i < Tasks.size(); i++){
        if (title == Tasks[i].title){
            Tasks[i].description = description;
        }
    }
}
void updateTaskS(string& title, string& status){
    for (int i = 0; i < Tasks.size(); i++){
        if (title == Tasks[i].title){
            Tasks[i].status = status;
        }
    }
}
void listTasks(){
    ifstream file("data.txt");
    string line;
    while (getline(file, line)){
        cout << line << "\n";
    }
    file.close();
}
void saveTasks(){
    ofstream file("data.txt", ios::app);
    for (int i = 0; i < Tasks.size(); i++){
        file << Tasks[i].id << "|" << Tasks[i].title << "|" << Tasks[i].description << "|" << Tasks[i].status << "\n";
    }
    file.close();
}