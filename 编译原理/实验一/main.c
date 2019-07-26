#include<stdio.h>
#include<string.h>
#include <stdbool.h>  //引入布尔类型，stdio.h文件中没有布尔类型


#define lineLength 100  //固定每行的长度
#define primLength 10   //读取的字符串的长度（标识符之类）
#define numLength 20    //读取的常量的长度


//存储基本字
char mPrimary[14][20]= {"begin","call","const","do","end","if","odd","procedure","read","then","var","while","write","liangding"};//有序,二分查找的前提是有序（按字母表顺序）


char text[lineLength][lineLength];//存储读到的内容




void  main()
{


int i=0;
bool flag=false; //判断输入是否结束，以及是否读到二维数组最后标志符（.），pl/0语言程序最后以点结束。


//将输入读入二维字符数组中
int t;
for (t = 0; t < 100; t++)
    {
        printf("%d:", t);
        gets(text[t]);
        if (!*text[t])     //当输入的该行为空时   if条件成立，执行break语句跳出循环。
        {
            break;
        }
    }


    //对二维字符数组进行处理，
     int mid;
    for(i=0; i<t; i++)
    {
        char prim[primLength];//新建一个字符数组用来存储基本字或者变量名
        char num[numLength];//新建一个字符数组用来存储常量


        for(mid=0; mid<primLength; mid++) //清空数组
            prim[mid]='\0';


        for(mid=0; mid<numLength; mid++) //清空数组
            num[mid]='\0';




        int j;
        for(j=0; text[i][j]!='\0'; j++)
        {
            if(text[i][j]=='.')
            {
                printf(".        界符\n");
                flag=true;
                break;
            }
            else if(text[i][j]==' ')
            {
                continue;
            }
            else if(text[i][j]>='a'&&text[i][j]<='z')
            {
                for(mid=0; (text[i][j]>='a'&&text[i][j]<='z')||(text[i][j]>='0'&&text[i][j]<='9'); j++,mid++) //读入字符串
                    prim[mid]=text[i][j];
                j--;//由于用j去判断循环的结束，此处需要回退一个字符


                for(mid=0; prim[mid]!='\0'; mid++) //输出字符串
                    printf("%c",prim[mid]);


                int head=0,tail=12;//二分查找,查找是否为基本字，保留字共13个
                int mid2;//中间比较变量
                while(head<=tail)
                {
                    mid2=(head+tail)/2;
                    if(strcmp(prim,mPrimary[mid2])<=0)  //字符串比较用strcpy（）函数
                        tail=mid2-1;
                    if(strcmp(prim,mPrimary[mid2])>=0)
                        head=mid2+1;
                }
                if(head-1>tail)//搜索成功,确定为基本字
                    printf("         基本字\n");
                else
                    printf("         标识符\n");


                for(mid=0; prim[mid]!='\0'; mid++) //清空数组方便下次读入
                    prim[mid]='\0';
            }
            else if(text[i][j]>='0'&&text[i][j]<='9')
            {
                for(mid=0; text[i][j]>='0'&&text[i][j]<='9'; j++,mid++)//读入数字
                    num[mid]=text[i][j];
                j--;//由于用j去判断循环的结束，此处需要回退一个字符


                for(mid=0; num[mid]!='\0'; mid++) //输出数字，并且清空方便下次读入
                {
                    printf("%c",num[mid]);
                    num[mid]='\0';
                }
                printf("         常数\n");
            }
            else//处理“+ - * /,#()等”
            {
                switch(text[i][j])
                {
                case '<':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c       运算符\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c         运算符\n",text[i][j]);
                    }
                    break;
                }
                case '>':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c         运算符\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c        运算符\n",text[i][j]);
                    }
                    break;
                }
                case ':':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c        运算符\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c        运算符\n",text[i][j]);
                    }
                    break;
                }
                case '+':
                case '-':
                case '*':
                case '/':
                {
                    printf("%c      运算符\n",text[i][j]);
                    break;
                }
                case '(':
                {
                    printf("%c      界符\n",text[i][j]);
                    break;
                }
                case ')':
                {
                    printf("%c      界符\n",text[i][j]);
                    break;
                }
                case ',':
                {
                    printf("%c      界符\n",text[i][j]);
                    break;
                }
                case ';':
                {
                    printf("%c      界符\n",text[i][j]);
                    break;
                }
                default:
                    printf("%c      标识符\n",text[i][j]);
                }


            }
        }
        if(flag)
            break;
    }




}
