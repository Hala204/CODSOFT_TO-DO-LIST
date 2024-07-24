#include <iostream>
using namespace std;

const int MAX_TASKS = 100; 
const int MAX_DESCRIPTION_LENGTH = 99; 

struct Task 
{
    char description[MAX_DESCRIPTION_LENGTH + 1]; 
    bool completed;
};

Task tasks[MAX_TASKS]; 
int numTasks = 0;      


void displayMenu() 
{
    cout << endl;
    cout << "=== TO-DO LIST MANAGER ===" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

void addTask() 
{
    if (numTasks < MAX_TASKS) 
    {
        Task newTask;
        cout << "Enter task description (max " << MAX_DESCRIPTION_LENGTH << " characters): ";
        cin.getline(newTask.description, sizeof(newTask.description));

        newTask.completed = false;
        tasks[numTasks] = newTask;
        numTasks++;

        cout << "Task added successfully" << endl;
    }
    else 
    {
        cout << "Cannot add more tasks" << endl;
    }
}

void viewTasks() 
{
    if (numTasks == 0) 
    {
        cout << "No tasks available" << endl;
    }
    else 
    {
        cout << endl;
        cout << "=== TASK LIST ===" << endl;
        for (int i = 0; i < numTasks; ++i) 
        {
            cout << (i + 1) << ". " << tasks[i].description;
            if (tasks[i].completed) 
            {
                cout << " - (Completed)";
            }
            else
            {
                cout << " - (Pending)";
            }
            cout << endl;
        }
    }
}

void markTaskCompleted() 
{
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    cin.ignore(); 

    if (index > 0 && index <= numTasks) 
    {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed" << endl;
    }
    else 
    {
        cout << "Invalid task number Please try again" << endl;
    }
}

void removeTask()
{
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    cin.ignore(); 

    if (index > 0 && index <= numTasks) 
    {
        for (int i = index - 1; i < numTasks - 1; ++i) 
        {
            for (int j = 0; j <= MAX_DESCRIPTION_LENGTH; ++j) 
            {
                tasks[i].description[j] = tasks[i + 1].description[j];
            }
            tasks[i].completed = tasks[i + 1].completed;
        }
        numTasks--;
        cout << "Task removed successfully" << endl;
    }
    else 
    {
        cout << "Invalid task number Please try again" << endl;
    }
}


int main() 
{
    char choice;

    do 
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) 
        {
        case '1':
            addTask();
            break;
        case '2':
            viewTasks();
            break;
        case '3':
            markTaskCompleted();
            break;
        case '4':
            removeTask();
            break;
        case '5':
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice Please try again" << endl;
            break;
        }
    } 
    while (choice != '5');
}