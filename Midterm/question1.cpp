#include <iostream>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
 if (n == 1) //the base case
 {
 printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
 return;
 }
 towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
 printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
 towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main()
{
 int n = 5; // Number of disks
 towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
 return 0;
}

/*
The base case for the towerofHanoi solution is when n==1. n represents the
number of disks and each time you move a disk (with each recursive call). The
problem is becoming smaller at every step because of this property in the solution,
or the n-1 parameter passed in to recursive calls until reaching that n==1 base case.
*/

/*
The computational complexity of this towers of hanoi solution is exponential. We need to move the disks a minimum of 2^n-1 times in order
to solve the solution or move a set of disks from one rod to another while following the rules, and this solution does just that.
*/