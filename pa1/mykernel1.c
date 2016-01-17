/* mykernel1.c: your portion of the kernel
 *
 *	Below are functions that are called by other parts of the kernel.
 *	Your ability to modify the kernel is via these functions.  You may
 *	modify the bodies of these functions, and add code outside or them,
 *	in any way you wish (however, you cannot change their interfaces).
 *
 */

#include "aux.h"
#include "sys.h"
#include "mykernel1.h"

/* MySwitchContext (p) should cause a context switch from the calling
 * process to process p.  It should return the ID of the calling process.
 * The ID of the calling process can be determined by calling GetCurProc (),
 * which returns the currently running process's ID. The routine
 * SwitchContext (p) is an internal working version of context switching.
 * This is provided so that the kernel works without modification, to
 * allow the other exercises to execute and to illustrate proper behavior.
 * For Exercise F, the call to SwitchContext (p) must be removed.
 */

 /*
int MySwitchContext (int p)
{
	return (SwitchContext (p));
}
*/


static CONTEXT process_table[MAXPROCS];


int MySwitchContext (int p)
{
    int me = GetCurProc();
	int magic = 0;     // times that SaveContext() has already been called
    SaveContext(&(process_table[me]));
    if (magic == 1) {
        return me;
    }
    else {
        magic = 1;
    }
    RestoreContext(p, &(process_table[p]));
}
