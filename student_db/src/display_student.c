#include <stdio.h>
#include "student.h"

void display_students()
{
    FILE *fp = fopen(FILE_NAME, "r");

    Student s;

    if(fp == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("\nStudent Records\n");
    printf("-------------------------\n");

    while(fscanf(fp, "%d %s %f",
                 &s.id,
                 s.name,
                 &s.marks) != EOF)
    {
        printf("%d\t%s\t%.2f\n",
               s.id,
               s.name,
               s.marks);
    }

    fclose(fp);
}
