#include <stdio.h>

//这是一个深圳大学平均GPA计算程序，不包含附加题情况

int main(){
    int class[50];//课程数组
    int k = 0;//计数器
    int boole = 1;//菜单判断值
    int end = 0;//课程数记录值 
    float GPA[50];//绩点分数数组
    float credit[50];//学分记录数组
    float sum_credit = 0;//总学分
    float sum_GPA = 0;//加权GPA
    float score = 0;//最终分数
    int temp1;//修改目标课程号
    int temp2;//修改后分数
    float temp3;//修改后学分

while (1)
{
    printf("请输入课程总数：");
    scanf("%d",&end);
    if (end <= 0 )
    {
        printf("您的课程输入不规范，请重新输入!\n\n");
    }
    else if (end >50)
    {
        printf("你学的太多了，我罢工了！");
        return 0;
    }
    else
    printf("输入正确！\n\n");
    break;
}
    

    while (k <= end - 1)//输入分数、学分
    {
    printf("请输入课程%d的分数、学分（用空格隔开!）：\n",k);
    scanf("%d %f",&class[k],&credit[k]);
        if(class[k] < 0 || class[k] > 100)
        {
            printf("您的分数输入不规范，请重新输入!\n\n");
            k--;
        }
    k++;
    }


        //允许修改输入
    while(1)
    {
        printf("\n\n请你确认分数\n如果需要修改输入1 确认无误输入2\n");
        scanf("%d",&boole);

        if(boole == 1)
        {
            printf("请输入需要修改的课程号");
            scanf("%d",&temp1);
            printf("\n已查询课程%d\n分数：%d  学分：%f",temp1,class[temp1],credit[temp1]);

            printf("\n请分别输入课程%d修改后的分数、学分（用空格隔开！）:\n",temp1);
            scanf("%d %f",&temp2,&temp3);

            class[temp1] = temp2;
            credit[temp1] = temp3;

            printf("修改后分数%d 修改后学分%f",temp2,temp3);
        }

        else
        break;
    }



    k = 0;//重置计数器
    //计算绩点
    while (k <= end - 1 )//读取数组
    {
        if (class[k] < 60)//F
        {
            printf("课程%d  绩点：0.0  等级：F 已挂科，请重修！\n",k);
            GPA[k] = 0;
        }
        else if (class[k] <= 64)//D
        {
            printf("课程%d  绩点：1.0  等级：D\n",k);
            GPA[k] = 1.0;
        }
        else if (class[k] <= 69)//C
        {
            printf("课程%d  绩点：2.0  等级：C\n",k);
            GPA[k] = 2.0;
        }
        else if (class[k] <= 74)//C+
        {
            printf("课程%d  绩点：2.5  等级：C+\n",k);
            GPA[k] = 2.5;
        }
        else if (class[k] <= 79)//B
        {
            printf("课程%d  绩点：3.0  等级：B\n",k);
            GPA[k] = 3.0;
        }
        else if (class[k] <= 84)//B+
        {
            printf("课程%d  绩点：3.5  等级：B+\n",k);
            GPA[k] = 3.5;
        }
        else if (class[k] <= 92)//A
        {
            printf("课程%d  绩点：4.0  等级：A\n",k);
            GPA[k] = 4.0;
        }
        else if (class[k] <= 100)//A+
        {
            printf("课程%d  绩点：4.5  等级：A+\n",k);
            GPA[k] = 4.5;
        }

        k++;
    }


    k = 0;//重置计数器
    //计算总学分
    while (k <= end)
    {
        sum_credit = sum_credit + credit[k];//累加学分
        sum_GPA = sum_GPA + (GPA[k] * credit[k]);//累加加权GPA
        k++;
    }

    score = sum_GPA / sum_credit;

    printf("总学分：%f\n",sum_credit);
    printf("\n您的成绩是：%f",score);

    return 0;
}