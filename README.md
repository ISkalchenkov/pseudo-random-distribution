# Pseudo-random distribution
The program takes 3 command line arguements:  
```shell
./prd --file <filename> --numtickets <N> --parameter <N>
```
- file - filename with the list of students ([example](https://github.com/ISkalchenkov/pseudo-random-distribution/blob/main/example/studentList.txt))
- numtickets - number of exam tickets (tickets are numbered from 1 to N (including N))
- parameter - permutation parameter (numerical parameter deterministically changing distribution)

The program evenly and deterministically outputs to the console a line from the file + the number of ticket.
***
## Build
```shell
$ git clone https://github.com/ISkalchenkov/pseudo-random-distribution.git
$ mkdir build && cd build
$ cmake ..
$ make
```
## Run
Example:
```shell
$ ./prd --file ../example/studentList.txt --numtickets 30 --parameter 73
```
