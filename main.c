

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Project {
    char name[100];
    char description[200];
    char status[50];
    char start_date[20];
    char end_date[20];
};

struct Project *projects = NULL;
int project_count = 0;
int capacity = 0;

// Расширение массива БЕЗ realloc
void expand_array(int extra) {
    int new_capacity = capacity + extra;

    struct Project *new_array = (struct Project*)malloc(new_capacity * sizeof(struct Project));
    if (!new_array) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (int i = 0; i < project_count; i++) {
        new_array[i] = projects[i];
    }

    free(projects);
    projects = new_array;
    capacity = new_capacity;
}

// Добавление проекта
void add_project() {
    if (project_count >= capacity) {
        expand_array(2);
    }

    printf("Enter name: ");
    scanf(" %[^\n]", projects[project_count].name);

    printf("Enter description: ");
    scanf(" %[^\n]", projects[project_count].description);

    printf("Enter status: ");
    scanf(" %[^\n]", projects[project_count].status);

    printf("Enter start date: ");
    scanf(" %[^\n]", projects[project_count].start_date);

    printf("Enter end date: ");
    scanf(" %[^\n]", projects[project_count].end_date);

    project_count++;
    printf("Project added.\n");
}

// Показ всех проектов
void show_projects() {
    if (project_count == 0) {
        printf("No projects.\n");
        return;
    }

    for (int i = 0; i < project_count; i++) {
        printf("\nProject #%d\n", i);
        printf("Name: %s\n", projects[i].name);
        printf("Description: %s\n", projects[i].description);
        printf("Status: %s\n", projects[i].status);
        printf("Start Date: %s\n", projects[i].start_date);
        printf("End Date: %s\n", projects[i].end_date);
    }
}

// Редактирование проекта
void edit_project() {
    int index;

    printf("Enter project index: ");
    scanf("%d", &index);

    if (index < 0 || index >= project_count) {
        printf("Invalid index!\n");
        return;
    }

    int choice;

    printf("1 - Name\n");
    printf("2 - Description\n");
    printf("3 - Status\n");
    printf("4 - Start Date\n");
    printf("5 - End Date\n");
    printf("Select field to change: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("New name: ");
            scanf(" %[^\n]", projects[index].name);
            break;
        case 2:
            printf("New description: ");
            scanf(" %[^\n]", projects[index].description);
            break;
        case 3:
            printf("New status: ");
            scanf(" %[^\n]", projects[index].status);
            break;
        case 4:
            printf("New start date: ");
            scanf(" %[^\n]", projects[index].start_date);
            break;
        case 5:
            printf("New end date: ");
            scanf(" %[^\n]", projects[index].end_date);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Data successfully updated.\n");
}

// Поиск проекта
void search_project() {
    char search_name[100];
    int found = 0;

    printf("Enter project name to search: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < project_count; i++) {
        if (strcmp(projects[i].name, search_name) == 0) {
            printf("\nProject found (index %d)\n", i);
            printf("Name: %s\n", projects[i].name);
            printf("Description: %s\n", projects[i].description);
            printf("Status: %s\n", projects[i].status);
            printf("Start Date: %s\n", projects[i].start_date);
            printf("End Date: %s\n", projects[i].end_date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Project not found.\n");
    }
}

// Удаление последнего проекта
void remove_last_project() {
    if (project_count == 0) {
        printf("Nothing to delete.\n");
        return;
    }

    project_count--;

    struct Project *new_array = NULL;

    if (project_count > 0) {
        new_array = (struct Project*)malloc(project_count * sizeof(struct Project));

        for (int i = 0; i < project_count; i++) {
            new_array[i] = projects[i];
        }
    }

    free(projects);
    projects = new_array;
    capacity = project_count;

    printf("Last project removed.\n");
}

// Очистка памяти
void free_all() {
    free(projects);
    projects = NULL;
    project_count = 0;
    capacity = 0;
}

int main() {
    int choice;

    do {
        printf("\n===== Project Management =====\n");
        printf("1 - Add Project\n");
        printf("2 - Show Projects\n");
        printf("3 - Edit Project\n");
        printf("4 - Search Project\n");
        printf("5 - Remove Last Project\n");
        printf("0 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_project();
                break;
            case 2:
                show_projects();
                break;
            case 3:
                edit_project();
                break;
            case 4:
                search_project();
                break;
            case 5:
                remove_last_project();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid menu item!\n");
        }

    } while (choice != 0);

    free_all();
    return 0;
}