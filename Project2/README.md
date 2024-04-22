## TITLE : DIRECTORY LINEAR SEARCH FOR FILE NAME. 

### Problem statement
The program performs an efficient linear search on a given directory to find a specific file using system calls to interact with the file system and directory entries. The linear  search algorithm ensures a quick search process, making it ideal for large directories. Upon completion, the program provides appropriate output based on whether the specified 
name is present in the directory or not.

### Solution
Solution Code is given in `code.c` file.

### Flow of the code
1. The program starts by including necessary header files and defining the function `search_by_filename`.

2. The `search_by_filename` function is defined to search for a given filename in the specified directory. It takes the filename as input and opens the directory specified by the `directory` variable.

3. Inside the `search_by_filename` function, the `opendir` system call is used to open the directory specified by `directory`. If it fails to open the directory, the function returns -1 to indicate an error.

4. The function then uses a loop to iterate through each entry in the directory using the `readdir` system call. For each entry, it compares the entry's filename with the provided filename using the `strcmp` function. If a match is found, the function returns 1 to indicate that the file is found.

5. If the loop completes without finding the filename, the directory stream is closed using the `closedir` system call, and the function returns 0 to indicate that the file is not found.

6. In the `main` function, the program checks if the number of command-line arguments is correct. If it's not, a usage message is displayed, and the program returns with an error code.

7. If the correct number of arguments is provided, the program calls the `search_by_filename` function with the filename provided as a command-line argument (`argv[1]`).

8. The `search_by_filename` function returns the result of the search (1 if the file is found, 0 if not, or -1 in case of an error), and this result is stored in the variable `found`.

9. The program then checks the value of `found` to determine the appropriate output. If `found` is -1, it means there was an error opening the directory, so a corresponding error message is displayed. If `found` is 0, it means the file was not found, and a message indicating that the file is not found is displayed.

10. If `found` is 1, it means the file is found, and a message saying "File found. Opening the file..." is displayed. The program then proceeds to construct a command using the `snprintf` function to open the file in another window (specific to Linux using `xdg-open` command).

11. The constructed command is executed using the `system` function. If the command execution returns an error (non-zero value), an error message "Error opening the file" is displayed, and the program returns with an error code.

12. If everything executes without errors, the program ends by returning 0, indicating successful execution.

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

  


