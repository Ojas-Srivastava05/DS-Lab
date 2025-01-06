#include<stdio.h>
struct student
{
    int roll;
    float marks;
    char str[100];
};
    void main()
{
    printf("ENTER THE NUMBER OF STUDENTS ");
    int n;
    scanf("%d",&n);
    struct student aih[n];
    for(int i=0;i<n;i++)
    {
        printf("\n Enter the student roll no \n");
        scanf("%d",&aih[i].roll);
        printf("\n Enter the student marks \n");
        scanf("%f", &aih[i].marks);
        printf("\n Enter the student name \n");
        scanf("%s", &aih[i].str);
    }
    printf("\n STUDENT INFORMATION");
    for(int i=0;i<n;i++)
    {
        printf("\n  roll no %d\n",aih[i].roll);
        printf("\n  marks %f\n",aih[i].marks);
        printf("\n  name %s\n",aih[i].str);
    }

}