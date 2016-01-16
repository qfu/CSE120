/* Programming Assignment 1: Exercise D
 *
 * Let's continue using Yield to effect a variety of executions sequences.
 * Using the code below, the sequence of the print statements will be ABP:
 *
 *	First Child (A)
 *	Second Child (B)
 *	Parent (P)
 *
 *
 * Questions
 *
 * 1. See if you can cause a change in the sequence as specified below just by
 * ADDING Yield statements (i.e., do not remove any of the ORIGINAL Yield
 * statements, just add extra ones anywhere you wish):
 *
 * a. BAP
 * b. BPA
 * c. PAB
 * d. PBA
 * e. APB
 *
 */

#include <stdio.h>
#include "aux.h"
#include "umix.h"

void ABP(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {

		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}

void BAP(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		Yield (ppid);	// todo
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {

		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Yield (pid1);		// todo
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}

void PAB(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		Yield (ppid);
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {
		Yield(ppid);
		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}

void BPA(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		Yield (ppid);
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {

		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}

void PBA(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		Yield(ppid);
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {
		Yield(ppid);
		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	Yield (pid2);
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}

void APB(){
	int ppid, pid1, pid2;

	ppid = Getpid ();

	if ((pid1 = Fork ()) == 0) {
		/* first child executes here */
		Printf("%s\n", "A"); // A id is 2
		//Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}


	Yield (pid1);

	if ((pid2 = Fork ()) == 0) {
		Yield (ppid);
		/* second child executes here */
		Printf("B\n");	// B id is 3
		//Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	Yield (pid2);	/* yield to second child before continuing */
	Printf("P\n");	// P 1
	//Printf ("I am the parent, my pid is %d\n", Getpid ());
}




void Main ()
{

  /*
	Something wierd happens if putting all functions together in the Main
	function and run it (The output seems overlaped). However, the output is OK if
	I just run one function in the Main function.
	*/
	Printf("ABP:\n");
	ABP();

	Printf("BAP:\n");
	BAP();

	Printf("PAB:\n");
	PAB();

	Printf("BPA:\n");
	BPA();

	Printf("PBA:\n");
	PBA();

	Printf("APB:\n");
	APB();





}
