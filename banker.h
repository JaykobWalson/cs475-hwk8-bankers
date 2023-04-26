extern int num_resources;//Total number of resources
extern int num_threads;//Total number of threads

extern int *available;//Amount of available vectors
extern int **max;//max demand matrix
extern int **allocation;//# of allocated resources
extern int **need;//A thread's total needs

int isSafe(int *availableMat, int **allocMat, int **needMat);
