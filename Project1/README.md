## TITLE : TO COPY THE FILES FROM SOURCE DIRECTORY TO BACKUP DIRECTORY.



### Problem statement
Develop a program to create a backup of files from a source directory to a backup directory. The program takes two directory paths, ‘sourceDirectory’ and ‘backupDirectory,’ as input and performs the following tasks:Create a backup directory with the path specified in ‘backupDirectory.’Copy all the files and subdirectories from the ‘sourceDirectory’ to the backup directory.

### Solution
Solution Code is given in **code.c** file.

### Flow of the code
1.The program starts by defining the source and backup directories as strings (sourceDirectory and backupDirectory).

2.It then constructs a command to create the backup directory using sprintf() to format the command with the backupDirectory path and save it in the backupCommand string.

3.The system() function is used to execute the backupCommand, which creates the backup directory using the terminal command mkdir -p. The -p flag ensures that the directory is created even if the parent directories don’t exist.

4.The program checks the return value of system() (stored in backupResult) to verify if the backup directory was created successfully. A return value of 0 indicates success, and any nonzero value indicates an error. If there was an 
  error, the program prints a corresponding error message and returns 1 to indicate failure.

5.Next, the program constructs a command to copy files from the source directory to the backup directory using sprintf() and saves it in the same backupCommand string.

6.The system() function is used again to execute the backupCommand, which performs the file copy operation using the terminal command cp -r.

7.The program checks the return value of system() (stored in backupCopyResult) to verify if the backup was completed successfully. A return value of 0 indicates success, and any nonzero value indicates an error. If there was an error, 
  the program prints a corresponding error message and returns 1 to indicate failure.

8.If both the backup directory creation and file copy operations were successful, the program returns 0 to indicate successful execution.

### Advantages
1.Simple and straightforward: The code is relatively simple and easy to understand, making it accessible to developers of various skill levels.

2.Platform independence: The code uses standard C libraries, which means it can run on multiple platforms without modification.

3.Error handling: The code checks the return values of system calls to handle errors during the directory creation and file backup processes.

4.Backup automation: The code automatically creates the backup directory and copies the files from the source directory to the backup directory, providing an automated backup solution

### Disadvantages
1.Lack of input validation: The code does not validate the input directories (sourceDirectory and backupDirectory) or check if they exist before performing operations on them. This can lead to unintended consequences or errors if the input directories are invalid.

2.Fixed buffer size: The backupCommand buffer has a fixed size of 1000, which may not be sufficient for very long directory paths or command strings. This can lead to buffer overflow issues if the constructed command exceeds the buffer size.

### How To Run ?
* Use bellow code  to redirect to folder
  ```
  cd foldername 
* Use bellow code to compile file
  ```
   cc code.c 
* Use bellow code to run code
  ```
  ./a.out
`note : all commands must be run in ubuntu ar any linux terminal`
* Use *cd folder name* to redirect to folder
* Use *cc code.c* to compile file
* Use *./a.out* to run code
* **note : all commands must be run in ubuntu ar any linux terminal**
  

