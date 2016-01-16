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
# Exercise D

* BAP:

```C


```
