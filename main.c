#include <stdio.h>

void cat(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE* fp;

    if (argc == 1)
        cat(stdin, stdout);
    else {
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                cat(fp, stdout);
                fclose(fp);
            }
    }

    return 0;
}

void cat(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}