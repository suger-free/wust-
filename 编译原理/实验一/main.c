#include<stdio.h>
#include<string.h>
#include <stdbool.h>  //���벼�����ͣ�stdio.h�ļ���û�в�������


#define lineLength 100  //�̶�ÿ�еĳ���
#define primLength 10   //��ȡ���ַ����ĳ��ȣ���ʶ��֮�ࣩ
#define numLength 20    //��ȡ�ĳ����ĳ���


//�洢������
char mPrimary[14][20]= {"begin","call","const","do","end","if","odd","procedure","read","then","var","while","write","liangding"};//����,���ֲ��ҵ�ǰ�������򣨰���ĸ��˳��


char text[lineLength][lineLength];//�洢����������




void  main()
{


int i=0;
bool flag=false; //�ж������Ƿ�������Լ��Ƿ������ά��������־����.����pl/0���Գ�������Ե������


//����������ά�ַ�������
int t;
for (t = 0; t < 100; t++)
    {
        printf("%d:", t);
        gets(text[t]);
        if (!*text[t])     //������ĸ���Ϊ��ʱ   if����������ִ��break�������ѭ����
        {
            break;
        }
    }


    //�Զ�ά�ַ�������д���
     int mid;
    for(i=0; i<t; i++)
    {
        char prim[primLength];//�½�һ���ַ����������洢�����ֻ��߱�����
        char num[numLength];//�½�һ���ַ����������洢����


        for(mid=0; mid<primLength; mid++) //�������
            prim[mid]='\0';


        for(mid=0; mid<numLength; mid++) //�������
            num[mid]='\0';




        int j;
        for(j=0; text[i][j]!='\0'; j++)
        {
            if(text[i][j]=='.')
            {
                printf(".        ���\n");
                flag=true;
                break;
            }
            else if(text[i][j]==' ')
            {
                continue;
            }
            else if(text[i][j]>='a'&&text[i][j]<='z')
            {
                for(mid=0; (text[i][j]>='a'&&text[i][j]<='z')||(text[i][j]>='0'&&text[i][j]<='9'); j++,mid++) //�����ַ���
                    prim[mid]=text[i][j];
                j--;//������jȥ�ж�ѭ���Ľ������˴���Ҫ����һ���ַ�


                for(mid=0; prim[mid]!='\0'; mid++) //����ַ���
                    printf("%c",prim[mid]);


                int head=0,tail=12;//���ֲ���,�����Ƿ�Ϊ�����֣������ֹ�13��
                int mid2;//�м�Ƚϱ���
                while(head<=tail)
                {
                    mid2=(head+tail)/2;
                    if(strcmp(prim,mPrimary[mid2])<=0)  //�ַ����Ƚ���strcpy��������
                        tail=mid2-1;
                    if(strcmp(prim,mPrimary[mid2])>=0)
                        head=mid2+1;
                }
                if(head-1>tail)//�����ɹ�,ȷ��Ϊ������
                    printf("         ������\n");
                else
                    printf("         ��ʶ��\n");


                for(mid=0; prim[mid]!='\0'; mid++) //������鷽���´ζ���
                    prim[mid]='\0';
            }
            else if(text[i][j]>='0'&&text[i][j]<='9')
            {
                for(mid=0; text[i][j]>='0'&&text[i][j]<='9'; j++,mid++)//��������
                    num[mid]=text[i][j];
                j--;//������jȥ�ж�ѭ���Ľ������˴���Ҫ����һ���ַ�


                for(mid=0; num[mid]!='\0'; mid++) //������֣�������շ����´ζ���
                {
                    printf("%c",num[mid]);
                    num[mid]='\0';
                }
                printf("         ����\n");
            }
            else//����+ - * /,#()�ȡ�
            {
                switch(text[i][j])
                {
                case '<':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c       �����\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c         �����\n",text[i][j]);
                    }
                    break;
                }
                case '>':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c         �����\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c        �����\n",text[i][j]);
                    }
                    break;
                }
                case ':':
                {
                    if(text[i][j+1]=='=')
                    {
                        printf("%c%c        �����\n",text[i][j],text[i][j+1]);
                        j++;
                    }
                    else
                    {
                        printf("%c        �����\n",text[i][j]);
                    }
                    break;
                }
                case '+':
                case '-':
                case '*':
                case '/':
                {
                    printf("%c      �����\n",text[i][j]);
                    break;
                }
                case '(':
                {
                    printf("%c      ���\n",text[i][j]);
                    break;
                }
                case ')':
                {
                    printf("%c      ���\n",text[i][j]);
                    break;
                }
                case ',':
                {
                    printf("%c      ���\n",text[i][j]);
                    break;
                }
                case ';':
                {
                    printf("%c      ���\n",text[i][j]);
                    break;
                }
                default:
                    printf("%c      ��ʶ��\n",text[i][j]);
                }


            }
        }
        if(flag)
            break;
    }




}
