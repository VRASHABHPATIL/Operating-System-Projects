#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
        char* sourceDirectory = "";
        char* backupDirectory = "";
        char backupCommand[1000];
        sprintf(backupCommand, "mkdir -p %s", backupDirectory); // Construct the command to 
        create the backup directory
        int backupResult = system(backupCommand);// Execute the backup directory creation command
        if (backupResult == 0) {
                printf("Backup directory created successfully!\n");
        } else {
                printf("Failed to create backup directory with error code %d\n", backupResult);
                return 1;
        }
        sprintf(backupCommand, "cp -r %s %s", sourceDirectory, backupDirectory); // Construct the command to backup the files
        int backupCopyResult = system(backupCommand); // Execute the backup command
        if (backupCopyResult == 0) {
                printf("Backup completed successfully!\n");
        } else {
                printf("Backup failed with error code %d\n", backupCopyResult);
                return 1;
        }
        return 0;
}
