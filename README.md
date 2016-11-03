Project Brief:

We have worked on a project, we finally succeed to implement various syscalls

and made it to executed. We are successfully implemented 

single command and two commands.



Project detail:

We made a tree. We have four other classes which inherit things 

from the Abstract Base class.(Four classes: Connector, And, Semi, Or)

Connector is a composite class which inherits 

pure virtual function from Base and it provides

functionality to other same level classes.

The lowest class is Command class which provides how every leaf class work.



Mechanism in command:

We made a command as a string variable, and store each command, 

connector into a vector. So that make us to separate left hand side

command is belongs to left, and the other belongs to the Right, which 

we did exactly same thing on the Lab3(Composite pattern: leaf class is operand

so we regard the each command(cmd+executable) as a operand in lab3 tree)



Code Problem:

1. We encountered a problem to deal with three or more commands.

	For example; ls -a; echo hello && mkdir test 
	
	the command above didn't work.

	We expected this logic error occured since our parsing was incorrect. 

	We weren't able to make the left parameter for the 
	
	connector classes as a Base Pointer Type.

2. We can't also handle when a single command but there's no executable(ex. ls) 

3. If we enter command like below, it occurs out of range error

	ls -a && echo hello(space between -a &&)

but it works if we use

	ls -a&& echo hello(no space between -a &&)
