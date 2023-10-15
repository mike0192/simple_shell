#include <stdio.h>
#include <unstid.h>

int main(void)
{
int a = 4;
int b = 4;
int mult = a * b;
pid_t ppid;

pid = getppid();

printf("mult is %d\n", mult);
printf("ppid is %u\n", ppid);

return (0);
}
