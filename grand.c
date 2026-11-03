#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
char nam[55];
int sco,cnt;
typedef struct{
    char name[55];
    int score;
}Student;
Student students[55];
void swap(int x,int y)
{
    Student tmp = students[y];
    students[y] = students[x];
    students[x] = tmp; 
}
void sort()
{
    for(int i=cnt;i>1;i--)
    {
        if(students[i].score>students[i-1].score)
            swap(i,i-1);
    }
}
int main()
{
    int n;
    bool tru = true;
    while(tru)
    {
        printf("\n请输入数字，选择你的操作：\n"
            "1.录入/修改学生x成绩y\n"
            "2.查询学生x成绩\n"
            "3.查询学生x成绩排名\n"
            "4.查询第x名学生姓名与成绩\n"
            "5.输出所有学生成绩\n"
            "6.查询绩点等级\n"
            "7.退出\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                printf("请输入学生成绩：");
                scanf("%d", &sco);
                int found = 0;
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        students[i].score = sco;
                        found = 1;
                        break;
                    }
                }
                if(!found)
                {
                    strcpy(students[++cnt].name, nam);
                    students[cnt].score = sco;
                }
                sort();
                break;
            }
            case 2:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                int found = 1;
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        printf("学生 %s 的成绩为：%d\n", students[i].name, students[i].score);
                        found = 0;
                        break;
                    }
                }
                if(found)printf("该学生成绩尚未录入\n");
                break;
            }
            case 3:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        printf("学生 %d 的排名为：%d\n", students[i].name, i);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                printf("请输入排名：");
                int rank;
                scanf("%d", &rank);
                if(rank < 0)printf("无效排名，请确认操作。\n");
                else if(rank > cnt)printf("当前共有 %d 名学生，最后一名学生为：\n 姓名：%s 成绩：%d\n", cnt, students[cnt].name,students[cnt].score);
                else printf("%s : %d\n",students[rank].name,students[rank].score);
                break;
            }
            case 5:
            {
                for(int i = 1; i <= cnt; i++)
                    printf("排名：%d 姓名：%s 分数：%d\n", i, students[i].name, students[i].score);
                break;
            }
            case 6:
            {
                printf("请输入学生姓名：");
                scanf("%s", nam);
                for(int i = 1; i <= cnt; i++)
                {
                    if(strcmp(students[i].name, nam) == 0)
                    {
                        int score = students[i].score;
                        char grade;
                        if(score >= 90) grade = 'A';
                        else if(score >= 80) grade = 'B';
                        else if(score >= 70) grade = 'C';
                        else if(score >= 60) grade = 'D';
                        else grade = 'F';
                        printf("学生 %s 的绩点等级为：%c\n", students[i].name, grade);
                        break;
                    }
                }
            }                
            case 7:
            {
                tru = false;
                break;
            }
            default:
                printf("请重新输入。\n");
            
        }//闭合switch循环
    }//闭合while循环
    system("pause");
    return 0;
}