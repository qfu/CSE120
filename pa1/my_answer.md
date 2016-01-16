### Exercise B

1. print sequences:
```
I am the parent, my pid is 1
I just created a child process whose pid is 2
I (the parent) just created a second child process whose pid is 3
I am the first child, my pid is 2
I am the second child, my pid is 3
```

2. Because we use a FIFO scheduling algorithm in this case, and first child is created earlier than the second one.

3. Use one additional variable to save the pid of first child.

### Exercise C

print sequences
```
I am the parent, my pid is 1
About to yield to child process whose pid is 2
I am the first child, my pid is 2
Process 2 just yielded to me (the parent)
About to yield to child process whose pid is 3
I am the second child, my pid is 3
Process 3 just yielded to me (the parent)

```
### Exercise E
* processes: 1| 21|



print sequences
```
1 about to fork
1 just forked 2
1 about to fork
1 just forked 3
1 about to fork
1 just forked 4
1 yielding to 4
4 starting
4 yielding to 3
3 starting
3 yielding to 2
2 starting
2 yielding to 1
1 resumed by 2, yielding to 4
4 resumed by 1, yielding to 3
3 resumed by 4, yielding to 2
2 resumed by 3, yielding to 1
1 existing
2 existing
3 existing
4 existing
```
