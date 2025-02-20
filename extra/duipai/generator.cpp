#include "testlib.h"
#include<cstdio>
#define inc(i,a,b) for(int i(a);i<=b;i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int l = atoi(argv[1]);
    int r = atoi(argv[2]);
    inc(_,l,r)
    {
        startTest(_);
        int testcase;
        testcase = rnd.next(1,10);
        printf("%d\n",testcase);
        inc(__,1,testcase)
        {
            int n=rnd.next(1,50);
            printf("%d\n",n);
            inc(i,1,n)
            {
                printf("%d",rnd.next(1,100000));
                i==n?printf("\n"):printf(" ");
            }
        }
    }  
}