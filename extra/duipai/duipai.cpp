#include <cstdio>
#include <cstdlib>

int main() {
    int l,r;
    scanf("%d%d",&l,&r);
    char cmd[50];
    sprintf(cmd,"generator.exe %d %d",l,r);
    system(cmd);
    for(int i(1);i<=r;i++)
    {
        printf("testing case %d ...\n",i);
        sprintf(cmd,"type %d > test.in",i);
        system(cmd);
        // system("gen > test.in");
        system("std.exe < test.in > std.out");
        system("baoli.exe < test.in > baoli.out");
        if (system("fc std.out baoli.out")) {
            system("pause");
        }
    }
    for(int i(l);i<=r;i++)
    {
        sprintf(cmd,"del %d",i);
        system(cmd);
    }
    printf("no problem found!\n");
    system("pause");
}