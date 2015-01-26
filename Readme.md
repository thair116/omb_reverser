Example usage
============

Compile with:
```
gcc omb_hw.c
```
Run with:
```
./a.out 3 0 < input.txt
```
First argument is buffer size, second is cleanup boolean (for deleting buffer overflows saved to disk)

Sample usage:

```
$ ./a.out 10 1 < input.txt
Buffer size is set to 10
Cleanup:  1
Enter a sentence.
zyxwvutsrqponmlkjihgfedcba a cb fed jihg onmlk utsrqp zyxwv yraM dah a elttil bmal %
```
