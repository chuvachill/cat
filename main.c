#include <stdio.h>
#include <string.h>

void copyfile(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE* fp;

/* print command line arguments */
    for (int i=0; i < argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);

    if (argc == 1)
        copyfile(stdin, stdout);
    else {
        for (int i=1; i < argc; ++i) {
            /* standard input */
            if (strcmp(argv[i], "-") == 0)
                copyfile(stdin, stdout);
            /* cannot read file */
            else if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("cat: can't open %s\n", argv[i]);
                return 1;
            /* read file */
            } else {
                copyfile(fp, stdout);
                fclose(fp);
            }
        }
    }

    return 0;
}

void copyfile(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}