#include <stdio.h>
#include <string.h>

void cat(FILE *, FILE *, int);

int main(int argc, char *argv[])
{
    FILE* fp;

/* print command line arguments */
    for (int i=0; i < argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);

    if (argc == 1)
        cat(stdin, stdout);
    else {
        for (int i=1; i < argc; ++i) {
            /* standard input */
            if (strcmp(argv[i], "-") == 0)
                cat(stdin, stdout, 0);
            else if (strcmp(argv[i], "-b") == 0)
            /* cannot read file */
            else if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("cat: can't open %s\n", argv[i]);
                return 1;
            /* read file */
            } else {
                cat(fp, stdout);
                fclose(fp);
            }
        }
    }

    return 0;
}

void cat(FILE *ifp, FILE *ofp, int opt)
{
    static int num; // number output lines
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}