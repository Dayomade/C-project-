tasks = []

def add_task(task):
    tasks.append({"title": task, "completed": False})

def read_tasks():
    if not tasks:
        print("No tasks found.")
        return
    for index, task in enumerate(tasks, 1):
        status = "Done" if task["completed"] else "Pending"
        print(f"{index}. {task['title']} [{status}]")

def update_task(index):
    if 1 <= index <= len(tasks):
        tasks[index - 1]["completed"] = True
    else:
        print("Invalid task number.")

def delete_task(index):
    if 1 <= index <= len(tasks):
        tasks.pop(index - 1)
    else:
        print("Invalid task number.")

while True:
    print("\n--- TODO LIST ---")
    print("1. Add Task")
    print("2. Read Tasks")
    print("3. Mark Completed")
    print("4. Delete Task")
    print("5. Exit")
    
    choice = input("Choose an option: ")
    
    if choice == "1":
        task_name = input("Enter task name: ")
        add_task(task_name)
    elif choice == "2":
        read_tasks()
    elif choice == "3":
        num = int(input("Enter task number to mark as completed: "))
        update_task(num)
    elif choice == "4":
        num = int(input("Enter task number to delete: "))
        delete_task(num)
    elif choice == "5":
        print("Goodbye!")
        break
    else:
        print("Invalid choice, try again.")