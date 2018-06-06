#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <windows.h> 
using namespace std; 
const int LIE = 9;
const int HANG = 10;
void display0();
static int step = 1;

class Chess
{
    public :
        virtual void show()=0;
        virtual void shift(Chess *chess[11][10],int,int,int,int)=0;
        virtual void inflag(int)=0;
        virtual int outflag()=0;
        virtual int getjiangjun()=0;
};
void take1(Chess *chess[11][10],int x1,int y1,int x2,int y2);
void take2(Chess *chess[11][10],int x1,int y1,int x2,int y2);

class Che : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Che::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    //�� 
    if(chess[x1][y1]->outflag()==1)
    {
        //�ж�ֱ������ 
        if(x2==x1||y2==y1)
        {
            //�жϿո����� 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�ж�ֱ������ 
        if(x2==x1||y2==x1)
        {
            //�жϿո����� 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }    
}
void Che::show(){
        if(flag==1)
            cout << "R��  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Ma : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Ma::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    //��
    if(chess[x1][y1]->outflag()==1)
    {
        //�ж��������� 
        if((fabs(x2-x1)==1&&fabs(y2-y1)==2)||(fabs(x2-x1)==2&&fabs(y2-y1)==1))
        {
            //�жϱ��� 
            if(fabs(x2-x1)==1&&chess[x1][(y1+y2)/2]->outflag()!=0)
                cout << "error!�����\n";
            else if(fabs(y2-y1)==1&&chess[(x1+x2)/2][y1]->outflag()!=0)
                cout << "error!�����\n";
            //�жϿո����� 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�ж��������� 
        if(fabs(x2-x1)==1&&fabs(y2-y1)==2||fabs(x2-x1)==2&&fabs(y2-y1)==1)
        {
            //�жϱ��� 
            if(fabs(x2-x1)==1&&chess[x1][(y1+y2)/2]->outflag()!=0)
                cout << "error!�����\n";
            else if(fabs(y2-y1)==1&&chess[(x1+x2)/2][y1]->outflag()!=0)
                cout << "error!�����\n";
            //�жϿո����� 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Ma::show(){
        if(flag==1)
            cout << "R��  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Xiang : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Xiang::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
     //��
    if(chess[x1][y1]->outflag()==1)
    {
        //�ж��������� 
        if(fabs(x2-x1)==2&&fabs(y2-y1)==2)
        {
            //�ж�����
            if(chess[(x1+x2)/2][(y1+y2)/2]->outflag()!=0)
                cout << "error!"; 
            //�жϿո����� 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�ж��������� 
        if(fabs(x2-x1)==2&&fabs(y2-y1)==2)
        {
            //�ж�����
            if(chess[(x1+x2)/2][(y1+y2)/2]->outflag()!=0)
                cout << "error!"; 
            //�жϿո����� 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Xiang::show(){
        if(flag==1)
            cout << "R��  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Shi : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Shi::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    //�� 
    if(chess[x1][y1]->outflag()==1)
    {
        //�޶����߷�Χ
        if(y2<4||y2>6||x2>3)
            cout << "error!\n"; 
        //�ж�б������ 
        else if(fabs(x2-x1)==1&&fabs(y2-y1)==1)
        {
            //�жϿո����� 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�޶����߷�Χ
        if(y2<4||y2>6||x2<8)
            cout << "error!\n"; 
        //�ж�б������ 
        else if(fabs(x2-x1)==1&&fabs(y2-y1)==1)
        {
            //�жϿո����� 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Shi::show(){
        if(flag==1)
            cout << "Rʿ  ";
        else if(flag==-1)
            cout << "Bʿ  ";
        else if(flag==0)
             cout << "     ";
}
class Pao : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Pao::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    int count = 0;
    int k;
    //�� 
    if(chess[x1][y1]->outflag()==1)
    {
        //�ж�ֱ������ 
        if(x2==x1||y2==y1)
        {
            //x����
            if(x2==x1)
            {
                //y2>y1
                if(y2>y1)
                {
                    for(k=y1+1;k<y2;k++)
                        if(chess[x1][k]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take1(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";
                }
                //y2<y1
                else  
                {
                     for(k=y2+1;k<y1;k++)
                        if(chess[x1][k]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take1(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n" ;                         
                } 
             }
             //��y���� 
            else
            {
                //x2>x1
                if(x2>x1)
                {
                    for(k=x1+1;k<x2;k++)
                        if(chess[k][y1]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take1(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";
                }
                //x2<x1
                else  
                {
                     for(k=x2+1;k<x1;k++)
                        if(chess[k][y2]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take1(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";                          
                } 
            //����y�����ϵ��ж� 
            }
            //����ֱ�������ж�    
        } 
        else 
           cout << "error!\n";
       //���������ж�      
    }
       
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�ж�ֱ������ 
        if(x2==x1||y2==y1)
        {
            //x����
            if(x2==x1)
            {
                //y2>y1
                if(y2>y1)
                {
                    for(k=y1+1;k<y2;k++)
                        if(chess[x1][k]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take2(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";
                }
                //y2<y1
                else  
                {
                     for(k=y2+1;k<y1;k++)
                        if(chess[x1][k]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take2(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n" ;                         
                } 
             }
             //��y���� 
            else
            {
                //x2>x1
                if(x2>x1)
                {
                    for(k=x1+1;k<x2;k++)
                        if(chess[k][y1]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take2(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";
                }
                //x2<x1
                else  
                {
                     for(k=x2+1;k<x1;k++)
                        if(chess[k][y2]->outflag()!=0)
                            count++;
                    if(count==1||count==0) 
                    {
                        //�жϿո�����
                        take2(chess,x1,y1,x2,y2);
                    }
                    //������ֹһ��ʱ���� 
                    else
                        cout << "error!\n";                          
                } 
            //����y�����ϵ��ж� 
            }
            //����ֱ�������ж�    
        } 
        else 
           cout << "error!\n";
       //���������ж�      
    }
}
void Pao::show(){
        if(flag==1)
            cout << "R��  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Jiang : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
        int getjiangjun();
};
int Jiang::getjiangjun(){
    return 8;
}
void Jiang::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    //�� 
    if(chess[x1][y1]->outflag()==1)
    {
         //�޶����߷�Χ
        if(y2<4||y2>6||x2>3)
            cout << "error!\n";
         //�ж�ֱ������ 
        else if(x2==x1||y2==y1)
        {
            //�жϿո����� 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //�޶����߷�Χ
        if(y2<4||y2>6||x2<8)
            cout << "error!\n";
        //�ж�ֱ������ 
        else if(x2==x1||y2==y1)
        {
            //�жϿո����� 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Jiang::show(){
        if(flag==1)
            cout << "R˧  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Zu : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show();
        void shift(Chess *chess[11][10],int,int,int,int);
};
void Zu::shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    //�� 
    if(chess[x1][y1]->outflag()==1)
    {
        //û���� 
        if(x2<=5)
        {
        //�ж���һ�� 
            if(y2==y1&&x2-x1==1)
            {
                //�жϿո����� 
                take1(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
       }
       //���Ӻ�
       if(x2>=6) 
       {
               //�ж���һ�� 
            if(y2==y1&&x2-x1==1)
            {
                //�жϿո����� 
                take1(chess,x1,y1,x2,y2);
            }
            else if(x2==x1&&fabs(y2-y1)==1)
            {
                //�жϿո����� 
                take1(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
        }
    }
    //���� 
    if(chess[x1][y1]->outflag()==-1)
    {
        //û���� 
        if(x2>=6)
        {
        //�ж���һ�� 
            if(y2==y1&&x1-x2==1)
            {
                //�жϿո����� 
                take2(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
       }
       //���Ӻ�
       if(x2<=5) 
       {
               //�ж���һ�� 
            if(y2==y1&&x1-x2==1)
            {
                //�жϿո����� 
                take2(chess,x1,y1,x2,y2);
            }
            else if(x2==x1&&fabs(y2-y1)==1)
            {
                //�жϿո����� 
                take2(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
        }
    }
}
void Zu::show(){
        if(flag==1)
            cout << "R��  ";
        else if(flag==-1)
            cout << "B��  ";
        else if(flag==0)
             cout << "     ";
}
class Kong : public Chess
{
    private :
        int flag;
    public :
        void inflag(int a){ flag = a;}
        int outflag(){ return flag; }
        int getjiangjun(){ return flag;}
        void show(){ cout << "     ";}     
        void shift(Chess *chess[11][10],int x1,int y1,int x2,int y2){
        }; 
};
int main(){
    Chess* chess[11][10];
    //�� 
    Che R_che1,R_che2,B_che1,B_che2;
    R_che1.inflag(1);               R_che2.inflag(1);
    B_che1.inflag(-1);              B_che2.inflag(-1);
    //�� 
    Ma R_ma1,R_ma2,B_ma1,B_ma2;
    R_ma1.inflag(1);                R_ma2.inflag(1);
    B_ma1.inflag(-1);               B_ma2.inflag(-1);
    //�� 
    Pao R_pao1,R_pao2,B_pao1,B_pao2;
    R_pao1.inflag(1);               R_pao2.inflag(1);
    B_pao1.inflag(-1);              B_pao2.inflag(-1);
    //�� 
    Xiang R_xiang1,R_xiang2,B_xiang1,B_xiang2;
    R_xiang1.inflag(1);             R_xiang2.inflag(1);
    B_xiang1.inflag(-1);            B_xiang2.inflag(-1);
    //ʿ 
    Shi R_shi1,R_shi2,B_shi1,B_shi2;
    R_shi1.inflag(1);               R_shi2.inflag(1);
    B_shi1.inflag(-1);              B_shi2.inflag(-1);
    //�� 
    Jiang R_jiang,B_jiang;
    R_jiang.inflag(1);                                
    B_jiang.inflag(-1);            
    //�� 
    Zu R_zu1,R_zu2,R_zu3,R_zu4,R_zu5;
    Zu B_zu1,B_zu2,B_zu3,B_zu4,B_zu5;
    R_zu1.inflag(1);                B_zu1.inflag(-1);
    R_zu2.inflag(1);                B_zu2.inflag(-1);
    R_zu3.inflag(1);                B_zu3.inflag(-1);
    R_zu4.inflag(1);                B_zu4.inflag(-1);
    R_zu5.inflag(1);                B_zu5.inflag(-1);
    //��
    Kong kong;
    kong.inflag(0);
    //��Ϸ��ʼ
    int i,j,k;
    for(i=1;i<=HANG;i++)
    {
        //��һ�� 
        if(i==1)
        {
            chess[i][1] = &R_che1;
            chess[i][2] = &R_ma1;
            chess[i][3] = &R_xiang1;
            chess[i][4] = &R_shi1;
            chess[i][5] = &R_jiang;
            chess[i][6] = &R_shi2;
            chess[i][7] = &R_xiang2;
            chess[i][8] = &R_ma2;
            chess[i][9] = &R_che2;
        }   
        //�ڶ���&�ھ��� 
        else if(i==2||i==9)
        {
            for(j=1;j<=LIE;j++)
            chess[i][j] = &kong;
        } 
        //������ 
        else if(i==3)
        {
            for(j=1;j<=LIE;j++)
            {
                if(j==2)
                    chess[i][j] = &R_pao1;
                else if(j==8)
                    chess[i][j] = &R_pao2;
                else 
                    chess[i][j] = &kong;
            }
        }
        //������ 
        else if(i==4)
        {
            for(j=1;j<=LIE;j++)
            {
                if(j==1)
                    chess[i][j] = &R_zu1;
                else if(j==3)
                    chess[i][j] = &R_zu2;
                else if(j==5)
                    chess[i][j] = &R_zu3;
                else if(j==7)
                    chess[i][j] = &R_zu4;
                else if(j==9)
                    chess[i][j] = &R_zu5;
                else
                    chess[i][j] = &kong;
            }
        }
        //������&������ 
        else if(i==5||i==6)
        {
            for(j=1;j<=LIE;j++)
            chess[i][j] = &kong;
        }
        //������ 
        else if(i==7)
        {
            for(j=1;j<=LIE;j++)
            {
                if(j==1)
                    chess[i][j] = &B_zu1;
                else if(j==3)
                    chess[i][j] = &B_zu2;
                else if(j==5)
                    chess[i][j] = &B_zu3;
                else if(j==7)
                    chess[i][j] = &B_zu4;
                else if(j==9)
                    chess[i][j] = &B_zu5;
                else
                    chess[i][j] = &kong;
            }
        }
        //�ڰ��� 
        else if(i==8)
        {
            for(j=1;j<=LIE;j++)
            {
                if(j==2)
                    chess[i][j] = &B_pao1;
                else if(j==8)
                    chess[i][j] = &B_pao2;      
                else 
                    chess[i][j] = &kong;
            }
        }
        //��ʮ�� 
        else if(i==10)
        {
            chess[i][1] = &B_che1;
            chess[i][2] = &B_ma1;
            chess[i][3] = &B_xiang1;
            chess[i][4] = &B_shi1;
            chess[i][5] = &B_jiang;
            chess[i][6] = &B_shi2;
            chess[i][7] = &B_xiang2;
            chess[i][8] = &B_ma2;
            chess[i][9] = &B_che2; 
        }
    }
    
    //��ʼ���
    do
    {
        display0() ;
        cout << "\n";
        for(i=1;i<=HANG;i++)
        {
            if(i==10)
                cout << i <<"   ";
            else
                cout << i <<"    ";
            for(j=1;j<=LIE;j++) 
            {
                chess[i][j]->show();
            }
            cout << endl;
        }
        //˵������ 
        if(step==1)
            cout << "�����й�������򣬺���\n";
        else if(step!=1&&step%2!=0)
            cout << "������\n";
        else if(step%2==0)
            cout << "������\n";
        cout <<"�������ʼ����:\n";
        //��ʼλ��
        int x1,y1;
        cin >> x1 >> y1;
        //�ж������Ƿ���ȷ 
        while(step==1&&(chess[x1][y1]->outflag()==-1||chess[x1][y1]->outflag()==0))
        {
            cout << "�뱣������ǫ�ã��ú�������\n";
            cin >> x1 >> y1;
        }
        while(step%2==0&&(chess[x1][y1]->outflag()==1||chess[x1][y1]->outflag()==0))
        {
            cout << "��ѡ�����\n";
            cin >> x1 >> y1;
        }
        while(step%2!=0&&(chess[x1][y1]->outflag()==-1||chess[x1][y1]->outflag()==0))
        {
            cout << "��ѡ�����\n";
            cin >> x1 >> y1;
        }
        cout << "���ƶ�������\n";
        int x2,y2;
        cin >> x2 >> y2;
        if(x1<1||x1>10||x2<1||x2>10||y1<1||y1>9||y2<1||y2>9)
        {
            cout << "error!\n";
            cout <<"�������ʼ����:\n";
            cin >> x1 >> y1;
            cout << "���ƶ�������\n";
            cin >> x2 >> y2;
        }
        chess[x1][y1]->shift(chess,x1,y1,x2,y2);
        if(step==0)
            break;
        Sleep(100);
        system("CLS");
    }while(1);
    cout << "Game over!\n";
    return 0;
     
}
void display0(){
    int i;
    cout << "     ";
    for(i=1;i<=LIE;i++)
        cout << i<<"    ";
}
//�жϿո�ͺ��� 
void take1(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    if(chess[x2][y2]->outflag()==0||chess[x2][y2]->outflag()==-1)
            {
                Chess *temp;
                    if(fabs(chess[x2][x2]->getjiangjun()-8)<1e-6)
                        step = -1;
                    temp = chess[x1][y1];
                    chess[x1][y1] = chess[x2][y2];
                    chess[x2][y2] = temp;
                    chess[x1][y1]->inflag(0);
                    step++;
            }
            else if(chess[x2][y2]->outflag()==1)
                cout << "error!\n";
}
//�жϿո�ͺ��� 
void take2(Chess *chess[11][10],int x1,int y1,int x2,int y2){
    if(chess[x2][y2]->outflag()==1||chess[x2][y2]->outflag()==0)
                {
                Chess *temp;
                if(fabs(chess[x2][x2]->getjiangjun()-8)<1e-6)
                        step = -1;
                    temp = chess[x1][y1];
                    chess[x1][y1] = chess[x2][y2];
                    chess[x2][y2] = temp;
                    chess[x1][y1]->inflag(0);
                    step++;
                }
                //���� 
                else if(chess[x2][y2]->outflag()==-1)
                    cout << "error!\n";
}

