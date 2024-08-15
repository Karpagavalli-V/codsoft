#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task
{
    string description;
    bool completed;
};
vector<Task> tasks;
void addTask()
{
    Task newTask;
    cout << "Enter the description of the new task: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}
void viewTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
        return;
    }
    cout << "Tasks List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}
void markTaskCompleted()
{
    viewTasks();
    if (tasks.empty()) return;
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed." << endl;
}
void removeTask()
{
    viewTasks();
    if (tasks.empty()) return;
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully." << endl;
}
void showMenu()
{
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}
int main()
{
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    while (choice != 5);
    return 0;
}
