# c-intro
Files of course C

## Parallel Number Printer
A new program has been added to demonstrate printing numbers from 0 to 100 in parallel using 4 threads. The program is located in `threads/print_parallel.c`.

### Compilation and Execution
To compile the program, navigate to the `threads` directory and run the following command:
```
gcc -pthread print_parallel.c -o print_parallel
```
To execute the program, simply run:
```
./print_parallel
```
This will print numbers from 0 to 100 in parallel, with each thread handling a unique quarter of the range.
