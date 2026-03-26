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

void addTask(string& title);
void deleteTask(string& title);
void updateTaskT(string& o_title, string& n_title);
void updateTaskD(string& title, string& description);
void updateTaskS(string& title, string& status);
void listTasks();

void saveTasks();
void uploadTasks();
int getId(){
    int id = 0;
    if (!Tasks.empty()){
        id = Tasks[Tasks.size() - 1].id + 1;
    }
    return id;
}

int main(int argc, const char* argv[]){

    // ./{name_of_file} {command} {details}
    // [      0       ] [   1   ] [   2   ]

    if (argc < 2){
        cout << "Incorrect input\n";
        return 1;
    }

    uploadTasks();

    string command = argv[1];
    if (command == "add")
    {
        string title = argv[2];
        addTask(title);
        saveTasks();
    }
    else if (command == "update")
    {
        string type = argv[2];
        if (type == "title")
        {
            string title = argv[3];
            string n_title = argv[4];
            updateTaskT(title, n_title);
            saveTasks();
        }
        else if (type == "description")
        {
            string title = argv[3];
            string description = argv[4];
            updateTaskD(title, description);
            saveTasks();
        }
        else if (type == "status")
        {
            string title = argv[3];
            string status = argv[4];
            updateTaskS(title, status);
            saveTasks();
        }
        else
        {
            cout << "Incorrect input\n";
            return 1;
        }
    }
    else if (command == "delete")
    {
        string title = argv[2];
        deleteTask(title);
        saveTasks();
    }
    else if (command == "list")
    {
        listTasks();
        return 0;
    }
    else
    {
        cout << "Incorrect input\n";
        return 1;
    }

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

    for (int i = 0; i < Tasks.size(); i++){
        cout << "Task №" << Tasks[i].id << ", title: " << Tasks[i].title << ", description: " << Tasks[i].description << ", status: " << Tasks[i].status << ".\n";
    }

    /*
    ifstream file("data.txt");
    string line;
    while (getline(file, line)){
        cout << line << "\n";
    }
    file.close();
    */
}
void uploadTasks(){
    ifstream file("data.txt");
    string line;
    while(getline(file, line)){
        Task newTask;

        auto p = line.find("|");
        string ID = line.substr(0, p);
        line = line.substr(p + 1);
        p = line.find("|");
        string T = line.substr(0, p);
        line = line.substr(p + 1);
        p = line.find("|");
        string D = line.substr(0, p);
        line = line.substr(p + 1);
        p = line.find("|");
        string S = line.substr(0, p);

        newTask.id = stoi(ID);
        newTask.title = T;
        newTask.description = D;
        newTask.status = S;
        Tasks.push_back(newTask);
    }
    file.close();
}

void saveTasks(){
    ofstream file("data.txt");
    for (int i = 0; i < Tasks.size(); i++){
        file << Tasks[i].id << "|" << Tasks[i].title << "|" << Tasks[i].description << "|" << Tasks[i].status << "\n";
    }
    file.close();
}
