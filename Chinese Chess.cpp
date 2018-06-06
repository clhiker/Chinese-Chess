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
    //红 
    if(chess[x1][y1]->outflag()==1)
    {
        //判断直线行走 
        if(x2==x1||y2==y1)
        {
            //判断空格或黑子 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //判断直线行走 
        if(x2==x1||y2==x1)
        {
            //判断空格或红子 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }    
}
void Che::show(){
        if(flag==1)
            cout << "R车  ";
        else if(flag==-1)
            cout << "B车  ";
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
    //红
    if(chess[x1][y1]->outflag()==1)
    {
        //判断日字行走 
        if((fabs(x2-x1)==1&&fabs(y2-y1)==2)||(fabs(x2-x1)==2&&fabs(y2-y1)==1))
        {
            //判断别腿 
            if(fabs(x2-x1)==1&&chess[x1][(y1+y2)/2]->outflag()!=0)
                cout << "error!马别腿\n";
            else if(fabs(y2-y1)==1&&chess[(x1+x2)/2][y1]->outflag()!=0)
                cout << "error!马别腿\n";
            //判断空格或黑子 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //判断日字行走 
        if(fabs(x2-x1)==1&&fabs(y2-y1)==2||fabs(x2-x1)==2&&fabs(y2-y1)==1)
        {
            //判断别腿 
            if(fabs(x2-x1)==1&&chess[x1][(y1+y2)/2]->outflag()!=0)
                cout << "error!马别腿\n";
            else if(fabs(y2-y1)==1&&chess[(x1+x2)/2][y1]->outflag()!=0)
                cout << "error!马别腿\n";
            //判断空格或红子 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Ma::show(){
        if(flag==1)
            cout << "R马  ";
        else if(flag==-1)
            cout << "B马  ";
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
     //红
    if(chess[x1][y1]->outflag()==1)
    {
        //判断田字行走 
        if(fabs(x2-x1)==2&&fabs(y2-y1)==2)
        {
            //判断象眼
            if(chess[(x1+x2)/2][(y1+y2)/2]->outflag()!=0)
                cout << "error!"; 
            //判断空格或黑子 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //判断田字行走 
        if(fabs(x2-x1)==2&&fabs(y2-y1)==2)
        {
            //判断象眼
            if(chess[(x1+x2)/2][(y1+y2)/2]->outflag()!=0)
                cout << "error!"; 
            //判断空格或红子 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Xiang::show(){
        if(flag==1)
            cout << "R象  ";
        else if(flag==-1)
            cout << "B象  ";
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
    //红 
    if(chess[x1][y1]->outflag()==1)
    {
        //限定行走范围
        if(y2<4||y2>6||x2>3)
            cout << "error!\n"; 
        //判断斜线行走 
        else if(fabs(x2-x1)==1&&fabs(y2-y1)==1)
        {
            //判断空格或黑子 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //限定行走范围
        if(y2<4||y2>6||x2<8)
            cout << "error!\n"; 
        //判断斜线行走 
        else if(fabs(x2-x1)==1&&fabs(y2-y1)==1)
        {
            //判断空格或红子 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Shi::show(){
        if(flag==1)
            cout << "R士  ";
        else if(flag==-1)
            cout << "B士  ";
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
    //红 
    if(chess[x1][y1]->outflag()==1)
    {
        //判断直线行走 
        if(x2==x1||y2==y1)
        {
            //x向开炮
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
                        //判断空格或黑子
                        take1(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
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
                        //判断空格或黑子
                        take1(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
                    else
                        cout << "error!\n" ;                         
                } 
             }
             //向y向开炮 
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
                        //判断空格或黑子
                        take1(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
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
                        //判断空格或黑子
                        take1(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
                    else
                        cout << "error!\n";                          
                } 
            //结束y方向上的判断 
            }
            //结束直线行走判断    
        } 
        else 
           cout << "error!\n";
       //结束红子判断      
    }
       
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //判断直线行走 
        if(x2==x1||y2==y1)
        {
            //x向开炮
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
                        //判断空格或红子
                        take2(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
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
                        //判断空格或红子
                        take2(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
                    else
                        cout << "error!\n" ;                         
                } 
             }
             //向y向开炮 
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
                        //判断空格或红子
                        take2(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
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
                        //判断空格或红子
                        take2(chess,x1,y1,x2,y2);
                    }
                    //跳过不止一个时报错 
                    else
                        cout << "error!\n";                          
                } 
            //结束y方向上的判断 
            }
            //结束直线行走判断    
        } 
        else 
           cout << "error!\n";
       //结束红子判断      
    }
}
void Pao::show(){
        if(flag==1)
            cout << "R炮  ";
        else if(flag==-1)
            cout << "B炮  ";
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
    //红 
    if(chess[x1][y1]->outflag()==1)
    {
         //限定行走范围
        if(y2<4||y2>6||x2>3)
            cout << "error!\n";
         //判断直线行走 
        else if(x2==x1||y2==y1)
        {
            //判断空格或黑子 
            take1(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //限定行走范围
        if(y2<4||y2>6||x2<8)
            cout << "error!\n";
        //判断直线行走 
        else if(x2==x1||y2==y1)
        {
            //判断空格或红子 
            take2(chess,x1,y1,x2,y2);
        }
        else 
            cout << "error!\n";
    }
}
void Jiang::show(){
        if(flag==1)
            cout << "R帅  ";
        else if(flag==-1)
            cout << "B将  ";
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
    //红 
    if(chess[x1][y1]->outflag()==1)
    {
        //没过河 
        if(x2<=5)
        {
        //判断走一格 
            if(y2==y1&&x2-x1==1)
            {
                //判断空格或黑子 
                take1(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
       }
       //过河后
       if(x2>=6) 
       {
               //判断走一格 
            if(y2==y1&&x2-x1==1)
            {
                //判断空格或黑子 
                take1(chess,x1,y1,x2,y2);
            }
            else if(x2==x1&&fabs(y2-y1)==1)
            {
                //判断空格或黑子 
                take1(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
        }
    }
    //黑子 
    if(chess[x1][y1]->outflag()==-1)
    {
        //没过河 
        if(x2>=6)
        {
        //判断走一格 
            if(y2==y1&&x1-x2==1)
            {
                //判断空格或红子 
                take2(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
       }
       //过河后
       if(x2<=5) 
       {
               //判断走一格 
            if(y2==y1&&x1-x2==1)
            {
                //判断空格或红子 
                take2(chess,x1,y1,x2,y2);
            }
            else if(x2==x1&&fabs(y2-y1)==1)
            {
                //判断空格或红子 
                take2(chess,x1,y1,x2,y2);
            }
            else 
                cout << "error!\n";
        }
    }
}
void Zu::show(){
        if(flag==1)
            cout << "R兵  ";
        else if(flag==-1)
            cout << "B卒  ";
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
    //车 
    Che R_che1,R_che2,B_che1,B_che2;
    R_che1.inflag(1);               R_che2.inflag(1);
    B_che1.inflag(-1);              B_che2.inflag(-1);
    //马 
    Ma R_ma1,R_ma2,B_ma1,B_ma2;
    R_ma1.inflag(1);                R_ma2.inflag(1);
    B_ma1.inflag(-1);               B_ma2.inflag(-1);
    //炮 
    Pao R_pao1,R_pao2,B_pao1,B_pao2;
    R_pao1.inflag(1);               R_pao2.inflag(1);
    B_pao1.inflag(-1);              B_pao2.inflag(-1);
    //象 
    Xiang R_xiang1,R_xiang2,B_xiang1,B_xiang2;
    R_xiang1.inflag(1);             R_xiang2.inflag(1);
    B_xiang1.inflag(-1);            B_xiang2.inflag(-1);
    //士 
    Shi R_shi1,R_shi2,B_shi1,B_shi2;
    R_shi1.inflag(1);               R_shi2.inflag(1);
    B_shi1.inflag(-1);              B_shi2.inflag(-1);
    //将 
    Jiang R_jiang,B_jiang;
    R_jiang.inflag(1);                                
    B_jiang.inflag(-1);            
    //卒 
    Zu R_zu1,R_zu2,R_zu3,R_zu4,R_zu5;
    Zu B_zu1,B_zu2,B_zu3,B_zu4,B_zu5;
    R_zu1.inflag(1);                B_zu1.inflag(-1);
    R_zu2.inflag(1);                B_zu2.inflag(-1);
    R_zu3.inflag(1);                B_zu3.inflag(-1);
    R_zu4.inflag(1);                B_zu4.inflag(-1);
    R_zu5.inflag(1);                B_zu5.inflag(-1);
    //空
    Kong kong;
    kong.inflag(0);
    //游戏开始
    int i,j,k;
    for(i=1;i<=HANG;i++)
    {
        //第一行 
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
        //第二行&第九行 
        else if(i==2||i==9)
        {
            for(j=1;j<=LIE;j++)
            chess[i][j] = &kong;
        } 
        //第三行 
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
        //第四行 
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
        //第五行&第六行 
        else if(i==5||i==6)
        {
            for(j=1;j<=LIE;j++)
            chess[i][j] = &kong;
        }
        //第七行 
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
        //第八行 
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
        //第十行 
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
    
    //初始输出
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
        //说明落子 
        if(step==1)
            cout << "根据中国象棋规则，红先\n";
        else if(step!=1&&step%2!=0)
            cout << "红子落\n";
        else if(step%2==0)
            cout << "黑子落\n";
        cout <<"请输入初始坐标:\n";
        //开始位移
        int x1,y1;
        cin >> x1 >> y1;
        //判断落子是否正确 
        while(step==1&&(chess[x1][y1]->outflag()==-1||chess[x1][y1]->outflag()==0))
        {
            cout << "请保持礼仪谦让，让红子现行\n";
            cin >> x1 >> y1;
        }
        while(step%2==0&&(chess[x1][y1]->outflag()==1||chess[x1][y1]->outflag()==0))
        {
            cout << "请选择黑子\n";
            cin >> x1 >> y1;
        }
        while(step%2!=0&&(chess[x1][y1]->outflag()==-1||chess[x1][y1]->outflag()==0))
        {
            cout << "请选择红子\n";
            cin >> x1 >> y1;
        }
        cout << "及移动后坐标\n";
        int x2,y2;
        cin >> x2 >> y2;
        if(x1<1||x1>10||x2<1||x2>10||y1<1||y1>9||y2<1||y2>9)
        {
            cout << "error!\n";
            cout <<"请输入初始坐标:\n";
            cin >> x1 >> y1;
            cout << "及移动后坐标\n";
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
//判断空格和黑子 
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
//判断空格和红子 
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
                //黑子 
                else if(chess[x2][y2]->outflag()==-1)
                    cout << "error!\n";
}

