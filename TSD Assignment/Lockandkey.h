
typedef struct
{
	char L[50];
	char K[50];

} locksAndKeys;
/*
	Cracks the lock.
*/
char Lock_Cracker(locksAndKeys store[20], int * num_key, int * num_locks);
/*
	Reads the lock and key file.
*/
char Read(int * num_locks, int * num_key,locksAndKeys store[20]);

