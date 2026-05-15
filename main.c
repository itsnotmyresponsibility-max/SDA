#include "data.h"

int main() {

    int choice;

    char name[100];

    do {

        printf("\n BST Project Management \n");

        printf("1 - Add Project\n");
        printf("2 - Show Inorder (LNR)\n");
        printf("3 - Show Preorder (NLR)\n");
        printf("4 - Show Postorder (LRN)\n");
        printf("5 - DFS Traversal\n");
        printf("6 - BFS Traversal\n");
        printf("7 - Search Project\n");
        printf("8 - Delete Project\n");
        printf("9 - Show Min Project\n");
        printf("10 - Show Max Project\n");
        printf("11 - Tree Height\n");
        printf("12 - Save Tree\n");
        printf("13 - Load Tree\n");
        printf("0 - Exit\n");

        printf("Your choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                add_project();

                break;

            case 2:

                printf("\n INORDER (LNR) \n");

                inorder(root);

                break;

            case 3:

                printf("\n PREORDER (NLR) \n");

                preorder(root);

                break;

            case 4:

                printf("\n POSTORDER (LRN) \n");

                postorder(root);

                break;

            case 5:

                printf("\n DFS \n");

                dfs(root);

                break;

            case 6:

                printf("\n BFS \n");

                bfs(root);

                break;

            case 7: {

                printf("Enter project name: ");

                scanf(" %[^\n]", name);

                struct Node *found = search(root, name);

                if(found != NULL) {

                    print_project(found);
                }
                else {

                    printf("Project not found.\n");
                }

                break;
            }

            case 8:

                printf("Enter project name to delete: ");

                scanf(" %[^\n]", name);

                root = delete_node(root, name);

                printf("Project deleted.\n");

                break;

            case 9: {

                struct Node *min = find_min(root);

                if(min != NULL) {

                    printf("\n MIN PROJECT \n");

                    print_project(min);
                }
                else {

                    printf("Tree is empty.\n");
                }

                break;
            }

            case 10: {

                struct Node *max = find_max(root);

                if(max != NULL) {

                    printf("\n MAX PROJECT \n");

                    print_project(max);
                }
                else {

                    printf("Tree is empty.\n");
                }

                break;
            }

            case 11:

                printf("Tree height: %d\n",
                       tree_height(root));

                break;

            case 12: {

                FILE *file = fopen("tree.txt", "w");

                if(file == NULL) {

                    printf("File error!\n");

                    break;
                }

                save_tree(root, file);

                fclose(file);

                printf("Tree saved successfully.\n");

                break;
            }

            case 13: {

                FILE *file = fopen("tree.txt", "r");

                if(file == NULL) {

                    printf("File not found!\n");

                    break;
                }

                load_tree(file);

                fclose(file);

                printf("Tree loaded successfully.\n");

                break;
            }

            case 0:

                free_tree(root);

                printf("Program finished.\n");

                break;

            default:

                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}
