#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include<stdlib.h>

int search_by_filename(const char *filename) {
    const char *directory = "/home/vrashabh"; // Replace with the actual path of the directory you want to search in
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directory);
    if (dir == NULL) {
        return -1; // Directory not found or cannot be opened.
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            closedir(dir);
            return 1; // File found.
        }
    }

    closedir(dir);
    return 0; // File not found.
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int found = search_by_filename(argv[1]);
    if (found == -1) {
        printf("Directory not found or cannot be opened.\n");
    } else if (found == 0) {
        printf("File not found.\n");
    } else {
        printf("File found. Opening the file...\n");

        // Compose the command to open the file
        char command[256];
        snprintf(command, sizeof(command), "xdg-open %s", argv[1]);

        // Execute the command to open the file in another window
        if (system(command) != 0) {
            printf("Error opening the file.\n");
            return 1;
        }
    }

    return 0;
}
