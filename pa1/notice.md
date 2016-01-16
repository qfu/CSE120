Note: As you are developing your program, you may have many processes that
are lingering from previous runs that never completed.  
If you run up against ieng9's maximum number of processes that you can have running, you may encounter strange behavior.  So, periodically check for existing processes by
typing the command "ps -u <yourloginname>".  If you see any processes labeled
"pa1..." you can kill those by typing "kill -9 <pid1> <pid2> ..." where <pidn>
is the process id of the runaway process.  A convenient command that does this
is:  

ps -u <yourloginname> | grep pa1 | awk '{print $1}' | xargs kill -9

it is recommended that you use Printf, rather than printf

The Fork () system call is used to create a process.
The return value from Fork () is 0, while in the parent, the return value is the process identifier (pid) of the child.

Getpid () which returns the pid of the calling process.
Exit () which causes the calling process to be destroyed.

for the child to learn its identifier, it must call Getpid ().
