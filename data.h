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

extern struct Project *projects;
extern int project_count;
extern int capacity;

void expand_array(int extra);
void add_project();
void show_projects();
void edit_project();
void search_project();
void sort_projects();
void insert_project();
void remove_project_by_index();
void remove_last_project();
void save_to_file();
void load_from_file();
void free_all();

