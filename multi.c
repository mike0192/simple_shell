#include "main.h"

int function2(void)
{
int a = 4;
int b = 4;
int mult = a * b;
pid_t ppid;

ppid = getppid();

printf("mult is %d\n", mult);
printf("ppid is %u\n", ppid);

return (0);
}
