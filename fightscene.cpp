#include "fightscene.h"
#include <QPainter>
#include <QIcon>
#include <QPixmap>
#include "mypushbutton.h"
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QFrame>
#include "choosescene.h"
#include "chesspushbutton.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include <QDebug>
#include <QPropertyAnimation>
#include "widget.h"
fightscene::fightscene(QWidget *parent) : QWidget(parent)
{
      static int row = 0;
      static int col = 0;
      static int num = 60;
      static int eating = 0;
      pix0.load(":/image/qipan2.jpg");
      pix15.load(":/image/red.png");
      pix16.load(":/image/black.png");
      pix17.load(":/image/redwin.png");
      pix18.load(":/image/blackwin.png");
      pix19.load(":/image/heqi.png");
      //载入阴影图片
      pix1.load(":/image/BBchange0.jpg");
      pix2.load(":/image/BSchange0.jpg");
      pix3.load(":/image/BXchange0.jpg");
      pix4.load(":/image/BCchange0.jpg");
      pix5.load(":/image/BHchange0.jpg");
      pix6.load(":/image/BPchange0.jpg");
      pix7.load(":/image/BZchange0.jpg");
      pix8.load(":/image/Hshuaichange0.jpg");
      pix9.load(":/image/HSchange0.jpg");
      pix10.load(":/image/HXchange0.jpg");
      pix11.load(":/image/HCchange0.jpg");
      pix12.load(":/image/HMchange0.jpg");
      pix13.load(":/image/HPchange0.jpg");
      pix14.load(":/image/HBchange0.jpg");
      //标题设置
      setFixedSize(1250,1000);
      setWindowTitle("玩家对战");
      setWindowIcon(QIcon(":/image/table.jpg"));

      //help按钮的设置
      QPixmap pix;
      QPushButton *help = new QPushButton(this);
      pix.load(":/image/help2.jfif");
      help->setFixedSize(pix.width(),pix.height());
      help->setStyleSheet("QPushButton{border:0px}");
      help->setIcon(pix);
      help->setIconSize(QSize(pix.width(),pix.height()));

      //计时器的设置
      QTimer *timer = new QTimer(this);
      timer->start(1000);
      QLabel * time1 = new QLabel(this);
      time1->move(1050,510);
      time1->setFrameShape(QFrame::WinPanel);
      time1->setFrameShadow(QFrame::Sunken);
      time1->resize(160,80);
      time1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//居中设置

      //60秒循环设置
      connect(timer,&QTimer::timeout,[=](){
          time1->setText(QString::number(num--));
          if(num == 0)
          {
              num = 60;
              for(int a=0;a<4;a++)
              {
                  for(int b=0;b<8;b++)
                  {
                          if(btn[a][b]->cheakable)
                              btn[a][b]->cheakable = false;
                          else if(btn[a][b]->cheakable == false)
                              btn[a][b]->cheakable = true;

                          btn[a][b]->changefinish();
                          btn[a][b]->eat = false;
                  }
              }
              if(which)
                  which = false;
              else
                  which = true;

              if(which)
                  turn->setPixmap(pix15);
              else
                  turn->setPixmap(pix16);

          }
      });

      //返回按钮的设置
      b2.setParent(this);
      b2.setText("关闭");
      b2.resize(150,75);
      b2.move(1050,800);

      //回合方的判断，开局默认为红方
      turn = new QLabel;
      turn->setParent(this);
      turn->move(1020,150);
      turn->setFixedSize(200,150);
      pix15 = pix15.scaled(turn->width(),turn->height());
      pix16 = pix16.scaled(turn->width(),turn->height());
      turn->setPixmap(pix15);

      //红方胜利的图片设置
      redwin = new QLabel;
      redwin->setParent(this);
      redwin->setFixedSize(500,250);
      redwin->move(this->width()*0.5-redwin->width()*0.5,-redwin->height());
      pix17 = pix17.scaled(redwin->width(),redwin->height());
      redwin->setPixmap(pix17);

      //黑方胜利的图片设置
      blackwin = new QLabel;
      blackwin->setParent(this);
      blackwin->setFixedSize(500,250);
      blackwin->move(this->width()*0.5-blackwin->width()*0.5,-blackwin->height());
      pix18 = pix18.scaled(blackwin->width(),blackwin->height());
      blackwin->setPixmap(pix18);

      //和棋的图片设置
      heqi = new QLabel;
      heqi->setParent(this);
      heqi->setFixedSize(500,250);
      heqi->move(this->width()*0.5-heqi->width()*0.5,-heqi->height());
      pix19 = pix19.scaled(heqi->width(),heqi->height());
      heqi->setPixmap(pix19);



      //构建一个32个象棋的数组
      int numblack1 = 7;
      int numblack2 = 6;
      int numblack3 = 6;
      int numblack4 = 5;
      int numblack5 = 5;
      int numblack6 = 4;
      int numblack7 = 4;
      int numblack8 = 3;
      int numblack9 = 3;
      int numblack10 = 2;
      int numblack11 = 2;
      int numblack12 = 1;
      int numblack13 = 1;
      int numblack14 = 1;
      int numblack15 = 1;
      int numblack16 = 1;
      int numred1 = 17;
      int numred2 = 16;
      int numred3 = 16;
      int numred4 = 15;
      int numred5 = 15;
      int numred6 = 14;
      int numred7 = 14;
      int numred8 = 13;
      int numred9 = 13;
      int numred10 = 12;
      int numred11 = 12;
      int numred12 = 11;
      int numred13 = 11;
      int numred14 = 11;
      int numred15 = 11;
      int numred16 = 11;

      int a[32]={numred1,numred3,numred2,numred4,numred5,numred6,numred7,numred8,numred9,numred10,numred11,numred12,numred13,numred14,numred15,numred16,
      numblack1,numblack2,numblack3,numblack5,numblack6,numblack7,numblack8,numblack4,numblack9,numblack10,numblack11,numblack12,numblack13,numblack14,numblack15,numblack16};
      //随机排列
      int temp,index,i;
      srand( time (NULL));
      for(i = 0;i<32;i++)
      {
          index = rand()%(32-i)+i;
          if(index != i)
          {
              temp=a[i];
              a[i]=a[index];
              a[index]=temp;
          }
      }

      //象棋棋子的排列与保存
      for(int i=0;i<4;i++)
      {
          for(int j=0;j<8;j++)
          {
              ChessPushButton * button = new ChessPushButton(a[i*8+j]);
              button->setParent(this);
              button->move(153+j*99,87+i*100);
              button->x = j;
              button->y = i;
              button->exist = true;//构建成功，为存在
              btn[i][j]=button;              //维持住象棋棋子
          }
      }

      //墓地棋子的排列与保存
      for(int  i=0;i<4;i++)
      {
          for(int j=0;j<8;j++)
          {
              QLabel *dead = new QLabel;
              dead->setParent(this);
              dead->move(160+j*99,577+i*100);
              mudi[i][j] = dead;

          }
      }

      //棋子功能的实现
      for(int i=0;i<4;i++)
      {
          for(int j=0;j<8;j++)
          {
              //左键按下选中棋子
              connect(btn[i][j],&ChessPushButton::event1,[=]()
              {
                  bool judge1 = true;
                  //判断是否已经有棋子被选中
                  for(int x=0;x<4;x++)
                  {
                      for(int y=0;y<8;y++)
                      {
                          if(btn[x][y]->choose)
                              judge1 = false;
                      }
                  }
                          if(judge1&&(btn[i][j]->num != 0))//无棋子被选中且自身大小不为0(自身不是空格)
                          {
                              //更改图片
                              btn[i][j]->changeIcon();
                              btn[i][j]->choose = true;
                              QPixmap pix;

                        //判断下侧的棋子大小
                              if(i<3)//下侧是否有棋子
                              {
                                  if(btn[i][j]->num>10)//判断黑红，为红时
                                  {
                                      //将自身的棋子编号载入X中
                                      x = btn[i][j]->num-10;
                                      if(x == 2)//判断是否为红炮
                                      {
                                          if(i<2)//判断是否可以隔子吃子
                                              {
                                                  bool out = false;
                                                  for(int p=1;i+p<=2;p++)//保证在数组中
                                                  {
                                                      if(btn[i+p][j]->exist)//判断是否有子可以垫炮
                                                      {
                                                          for(int q=1;i+p+q<=3;q++)
                                                          {
                                                              if((btn[i+q+p][j]->keshi)&&(btn[i+q+p][j]->num != 0))//判断是否有子可以吃
                                                              {
                                                                  if(btn[i+q+p][j]->num<10)//判断谁是否为黑棋
                                                                  {
                                                                      if(btn[i+q+p][j]->num!=3)
                                                                      {
                                                                          pix=judge(btn[i+p+q][j]->num);
                                                                          btn[i+q+p][j]->change(pix);
                                                                          btn[i+q+p][j]->eat = true;
                                                                      }
                                                                  }
                                                                  out = true;
                                                                  break;
                                                              }
                                                          }
                                                      }
                                                      if(out)
                                                      {
                                                         break;
                                                      }
                                                  }
                                              }
                                      }
                                      if((btn[i+1][j]->keshi)&&(btn[i+1][j]->num != 0))//判断是否可视
                                      {
                                          if(btn[i+1][j]->num<10)//判断右侧棋子黑红,大于10为红
                                          {
                                              //将下侧棋子的编号载入Y中
                                              y = btn[i+1][j]->num;
                                              if(x == 1)//判断是否为红兵
                                              {
                                                  if(y == 7)//判断是否为黑将
                                                    {
                                                      pix=pix1;
                                                      btn[i+1][j]->change(pix);//变色，视为可以吃子
                                                      btn[i+1][j]->eat = true;
                                                    }
                                              }
                                              else if(x == 7)//判断是否为红帅
                                              {
                                                  if(y != 1)//判断是否为黑卒
                                                  {
                                                      pix=judge(btn[i+1][j]->num);
                                                      btn[i+1][j]->change(pix);
                                                      btn[i+1][j]->eat = true;
                                                  }
                                              }
                                              else if (x == 3)
                                              {
                                                 if(x>y)
                                                 {
                                                     pix=judge(btn[i+1][j]->num);
                                                     btn[i+1][j]->change(pix);
                                                     btn[i+1][j]->eat = true;
                                                 }
                                              }
                                              else if(( x>=y ) && (x!=7) && (x!=2) && (x!=1)&&(x != 3))//如果大于，则图标颜色改变，表示可以吃掉,且不是红炮，不是红帅的时候
                                              {
                                                  pix=judge(btn[i+1][j]->num);
                                                  btn[i+1][j]->change(pix);
                                                  btn[i+1][j]->eat = true;
                                              }
                                          }
                                      }
                                  }
                                  if(btn[i][j]->num<10)//判断黑红  为黑时
                                  {
                                      //将自身的棋子编号载入X中
                                      x = btn[i][j]->num;
                                      if(x == 2)//判断是否为黑炮
                                      {
                                          if(i<2)//判断是否可以隔子吃子
                                          {
                                              bool out = false;
                                              for(int p=1;i+p<=2;p++)//保证在数组中
                                              {
                                                  if(btn[i+p][j]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;q+i+p<=3;q++)
                                                      {
                                                          if((btn[i+q+p][j]->keshi)&&(btn[i+q+p][j]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i+q+p][j]->num>10)
                                                              {
                                                                  if(btn[i+q+p][j]->num!=13)
                                                                  {
                                                                      pix=judge(btn[i+p+q][j]->num);
                                                                      btn[i+p+q][j]->change(pix);
                                                                      btn[i+q+p][j]->eat = true;
                                                                  }
                                                              }
                                                              out = true;
                                                              break;
                                                          }
                                                      }
                                                  }
                                                  if(out)
                                                  break;
                                              }
                                          }
                                      }
                                  if((btn[i+1][j]->keshi)&&(btn[i+1][j]->num != 0))
                                  {
                                      if(btn[i+1][j]->num>10)//判断下侧棋子黑红，小于10为黑
                                      {
                                          //将下侧棋子的编号载入Y中
                                          y = btn[i+1][j]->num-10;
                                          if(x == 1)//判断是否为黑卒
                                          {
                                              if(y == 7)//判断是否为红帅
                                                {
                                                  pix=pix8;
                                                  btn[i+1][j]->change(pix);
                                                  btn[i+1][j]->eat = true;
                                                }
                                          }
                                          else if(x == 7)//判断是否为黑将
                                          {
                                              if(y != 1)//判断是否为红兵
                                              {
                                                  pix=judge(btn[i+1][j]->num);
                                                  btn[i+1][j]->change(pix);
                                                  btn[i+1][j]->eat = true;
                                              }
                                          }
                                          else if (x == 3)
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i+1][j]->num);
                                                 btn[i+1][j]->change(pix);
                                                 btn[i+1][j]->eat = true;
                                             }
                                          }
                                          else if((x>=y) && (x != 7)&&(x != 2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i+1][j]->num);
                                              btn[i+1][j]->change(pix);
                                              btn[i+1][j]->eat = true;
                                          }
                                      }
                                  }
                                  }

                              }

                        //判断上侧的棋子大小
                              if(i>0)//上侧是否有棋子
                              {
                                  if(btn[i][j]->num>10)//判断黑红 为红时
                                  {
                                      x = btn[i][j]->num-10;
                                      if(x == 2)//判断是否为红炮
                                      {
                                          if(i>1)//判断是否可以隔子吃子
                                          {
                                              bool out = false;
                                              for(int p=1;i-p>=1;p++)//保证在数组中
                                              {
                                                  if(btn[i-p][j]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;i-p-q>=0;q++)
                                                      {
                                                          if((btn[i-p-q][j]->keshi)&&(btn[i-p-q][j]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i-q-p][j]->num<10)
                                                              {
                                                                  if(btn[i-q-p][j]->num!=3)
                                                                  {
                                                                      pix=judge(btn[i-p-q][j]->num);
                                                                      btn[i-p-q][j]->change(pix);
                                                                      btn[i-p-q][j]->eat = true;
                                                                  }
                                                              }
                                                              out = true;
                                                              break;
                                                          }
                                                       }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                           }
                                      }
                                      if((btn[i-1][j]->keshi)&&(btn[i-1][j]->num != 0))
                                      {
                                      if(btn[i-1][j]->num<10)//判断上侧棋子颜色，为黑时
                                      {
                                          y = btn[i-1][j]->num;
                                          if(x == 1)//判断是否为红兵
                                          {
                                              if(y == 7)//判断是否为黑将
                                                {
                                                  pix=pix1;
                                                  btn[i-1][j]->change(pix);
                                                  btn[i-1][j]->eat = true;
                                                }
                                          }
                                          if(x == 7)//判断是否为红帅
                                          {
                                              if(y != 1)//判断是否为黑卒
                                              {
                                                  pix=judge(btn[i-1][j]->num);
                                                  btn[i-1][j]->change(pix);
                                                  btn[i-1][j]->eat = true;
                                              }
                                          }
                                          else if (x == 3)//判断是否为马
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i-1][j]->num);
                                                 btn[i-1][j]->change(pix);
                                                 btn[i-1][j]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x != 2)&&(x != 1)&&(x != 3))//其他情况
                                          {
                                              pix=judge(btn[i-1][j]->num);
                                              btn[i-1][j]->change(pix);
                                              btn[i-1][j]->eat = true;
                                          }
                                      }
                                      }
                                  }
                                  if(btn[i][j]->num<10)//判断黑红  为黑时
                                  {
                                      //将自身的棋子编号载入X中
                                      x = btn[i][j]->num;
                                      if(x == 2)//判断是否为黑炮
                                      {
                                          if(i>1)//判断是否可以隔子吃子
                                          {
                                              bool out = false;
                                              for(int p=1;i-p>=1;p++)//保证在数组中
                                              {
                                                  if(btn[i-p][j]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;i-q-p>=0;q++)
                                                      {
                                                          if((btn[i-p-q][j]->keshi)&&(btn[i-p-q][j]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i-q-p][j]->num>10)
                                                              {
                                                                  if(btn[i-q-p][j]->num!=13)
                                                                  {
                                                                      pix=judge(btn[i-p-q][j]->num);
                                                                      btn[i-p-q][j]->change(pix);
                                                                      btn[i-p-q][j]->eat = true;
                                                                  }
                                                              }
                                                              out = true;
                                                              break;
                                                          }
                                                      }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                          }
                                      }
                                      if((btn[i-1][j]->keshi)&&(btn[i-1][j]->num != 0))
                                      {
                                      if(btn[i-1][j]->num>10)//判断右侧棋子黑红，小于10为黑
                                      {
                                          //将右侧棋子的编号载入Y中
                                          y = btn[i-1][j]->num-10;
                                          if(x == 1)//判断是否为黑卒
                                          {
                                              if(y == 7)//判断是否为红帅
                                                {
                                                  pix=pix8;
                                                  btn[i-1][j]->change(pix);
                                                  btn[i-1][j]->eat = true;
                                                }
                                          }
                                          if(x == 7)//判断是否为黑将
                                          {
                                              if(y != 1)//判断是否为红兵
                                              {
                                                  pix=judge(btn[i-1][j]->num);
                                                  btn[i-1][j]->change(pix);
                                                  btn[i-1][j]->eat = true;
                                              }
                                          }
                                          else if (x == 3)//判断是否为黑马
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i-1][j]->num);
                                                 btn[i-1][j]->change(pix);
                                                 btn[i-1][j]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x !=2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i-1][j]->num);
                                              btn[i-1][j]->change(pix);
                                              btn[i-1][j]->eat = true;
                                          }
                                      }
                                      }
                                   }
                              }

                        //判断左侧棋子的大小
                              if(j>0)//左侧是否有棋子
                              {
                                  //将自身的棋子编号载入X中
                                  if(btn[i][j]->num>10)//判断黑红，为红时
                                  {
                                      x = btn[i][j]->num-10;
                                      if(x == 2)//判断是否为红炮
                                      {
                                          if(j>1)//判断是否可以隔子吃子
                                          {
                                              bool out = false;//为跳出第一个循环做准备
                                              for(int p=1;j-p>=1;p++)//保证在数组中
                                              {
                                                  if(btn[i][j-p]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;j-q-p>=0;q++)
                                                      {
                                                          if((btn[i][j-p-q]->keshi)&&(btn[i][j-p-q]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i][j-p-q]->num<10)
                                                              {
                                                                  if(btn[i][j-p-q]->num!=3)
                                                                  {
                                                                      pix=judge(btn[i][j-p-q]->num);
                                                                      btn[i][j-p-q]->change(pix);
                                                                      btn[i][j-p-q]->eat = true;
                                                                  }
                                                              }
                                                              out=true;
                                                              break;
                                                          }
                                                      }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                          }
                                      }
                                      if((btn[i][j-1]->keshi)&&(btn[i][j-1]->num != 0))
                                      {
                                      if(btn[i][j-1]->num<10)//判断左侧棋子黑红，为黑时
                                      {
                                          y = btn[i][j-1]->num;
                                          if(x == 1)//判断是否为红兵
                                          {
                                              if(y == 7)
                                              {
                                                pix=pix1;
                                                btn[i][j-1]->change(pix);
                                                btn[i][j-1]->eat = true;
                                              }
                                          }
                                          if(x == 7)//判断是否为红帅
                                          {
                                              if(y != 1)//判断是否为黑卒
                                              {
                                                  pix=judge(btn[i][j-1]->num);
                                                  btn[i][j-1]->change(pix);
                                                  btn[i][j-1]->eat = true;
                                              }
                                          }
                                          else if (x == 3)
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i][j-1]->num);
                                                 btn[i][j-1]->change(pix);
                                                 btn[i][j-1]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x != 2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i][j-1]->num);
                                              btn[i][j-1]->change(pix);
                                              btn[i][j-1]->eat = true;
                                          }
                                      }
                                      }
                                  }
                                  if(btn[i][j]->num<10)//判断黑红  为黑时
                                  {
                                      //将自身的棋子编号载入X中
                                      x = btn[i][j]->num;
                                      if(x == 2)//判断是否为黑炮
                                      {
                                          if(j>1)//判断是否可以隔子吃子
                                          {
                                              bool out = false;
                                              for(int p=1;j-p>=1;p++)//保证在数组中
                                              {
                                                  if(btn[i][j-p]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;j-q-p>=0;q++)
                                                      {
                                                          if((btn[i][j-p-q]->keshi)&&(btn[i][j-p-q]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i][j-p-q]->num>10)
                                                              {
                                                                  if(btn[i][j-p-q]->num!=13)
                                                                  {
                                                                      pix=judge(btn[i][j-p-q]->num);
                                                                      btn[i][j-p-q]->change(pix);
                                                                      btn[i][j-p-q]->eat = true;
                                                                  }
                                                              }
                                                              out = true;
                                                              break;
                                                          }
                                                      }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                          }
                                      }
                                      if((btn[i][j-1]->keshi)&&(btn[i][j-1]->num != 0))
                                      {
                                      if(btn[i][j-1]->num>10)//判断左侧棋子黑红，小于10为黑
                                      {
                                          //将右侧棋子的编号载入Y中
                                          y = btn[i][j-1]->num-10;
                                          if(x == 1)//判断是否为黑卒
                                          {
                                              if(y == 7)//判断是否为红帅
                                                {
                                                  pix=pix8;
                                                  btn[i][j-1]->change(pix);
                                                  btn[i][j-1]->eat = true;
                                                }
                                          }
                                          if(x == 7)//判断是否为黑将
                                          {
                                              if(y != 1)//判断是否为红兵
                                              {
                                                  pix=judge(btn[i][j-1]->num);
                                                  btn[i][j-1]->change(pix);
                                                  btn[i][j-1]->eat = true;
                                              }
                                          }
                                          else if (x == 3)
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i][j-1]->num);
                                                 btn[i][j-1]->change(pix);
                                                 btn[i][j-1]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x != 2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i][j-1]->num);
                                              btn[i][j-1]->change(pix);
                                              btn[i][j-1]->eat = true;
                                          }
                                      }
                                       }
                                   }
                              }

                        //判断右侧棋子的大小
                              if(j<7)//右侧是否有棋子
                              {
                                  //将自身的棋子编号载入X中
                                  if(btn[i][j]->num>10)//判断黑红，为红时
                                  {
                                      x = btn[i][j]->num-10;
                                      if(x == 2)//判断是否为红炮
                                      {
                                          if(j<6)//判断是否可以隔子吃子
                                          {
                                              bool out=false;//判断是否已经可以吃子了
                                              for(int p=1;j+p<=6;p++)//保证在数组中
                                              {
                                                  if(btn[i][j+p]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;j+p+q<=7;q++)
                                                      {
                                                          if((btn[i][j+p+q]->keshi)&&(btn[i][j+p+q]->num != 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i][j+p+q]->num<10)
                                                              {
                                                                  if(btn[i][j+p+q]->num!=3)//不是马
                                                                  {
                                                                      pix=judge(btn[i][j+p+q]->num);
                                                                      btn[i][j+p+q]->change(pix);
                                                                      btn[i][j+p+q]->eat = true;
                                                                  }
                                                              }
                                                              out = true;
                                                              break;
                                                          }
                                                      }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                          }
                                      }
                                      if((btn[i][j+1]->keshi)&&(btn[i][j+1]->num != 0))
                                      {
                                      if(btn[i][j+1]->num<10)//判断下右侧棋子黑红，为黑时
                                      {
                                          y = btn[i][j+1]->num;
                                          if(x == 1)//判断是否为红兵
                                          {
                                              if(y == 7)//判断是否为黑将
                                              {
                                                  pix=pix1;
                                                  btn[i][j+1]->change(pix);
                                                  btn[i][j+1]->eat = true;
                                              }
                                          }
                                          else if(x == 7)//判断是否为红帅
                                          {
                                              if(y != 1)//判断是否为黑卒
                                              {
                                                  pix=judge(btn[i][j+1]->num);
                                                  btn[i][j+1]->change(pix);
                                                  btn[i][j+1]->eat = true;
                                              }
                                          }
                                          else if(x == 3)
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i][j+1]->num);
                                                 btn[i][j+1]->change(pix);
                                                 btn[i][j+1]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x != 2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i][j+1]->num);
                                              btn[i][j+1]->change(pix);
                                              btn[i][j+1]->eat = true;
                                          }
                                      }
                                      }
                                  }
                                  if(btn[i][j]->num<10)//判断黑红  为黑时
                                  {
                                      //将自身的棋子编号载入X中
                                      x = btn[i][j]->num;
                                      if(x == 2)//判断是否为黑炮
                                      {
                                          if(j<6)//判断是否可以隔子吃子
                                          {
                                              bool out=false;
                                              for(int p=1;j+p<=6;p++)//保证在数组中
                                              {
                                                  if(btn[i][j+p]->exist)//判断是否有子可以垫炮
                                                  {
                                                      for(int q=1;j+p+q<=7;q++)
                                                      {
                                                          if((btn[i][j+p+q]->keshi)&&(btn[i][j+p+q]->num!= 0))//判断是否有子可以吃
                                                          {
                                                              if(btn[i][j+p+q]->num>10)
                                                              {
                                                                  if(btn[i][j+p+q]->num!=13)
                                                                  {
                                                                      pix=judge(btn[i][j+p+q]->num);
                                                                      btn[i][j+p+q]->change(pix);
                                                                      btn[i][j+p+q]->eat = true;
                                                                  }
                                                              }
                                                              out=true;
                                                              break;
                                                           }
                                                      }
                                                  }
                                                  if(out)
                                                      break;
                                              }
                                          }
                                      }
                                      if((btn[i][j+1]->keshi)&&(btn[i][j+1]->num != 0))
                                      {
                                      if(btn[i][j+1]->num>10)//判断右侧棋子黑红，小于10为黑
                                      {
                                          //将右侧棋子的编号载入Y中
                                          y = btn[i][j+1]->num-10;
                                          if(x == 1)//判断是否为黑卒
                                          {
                                              if(y == 7)//判断是否为红帅
                                                {
                                                  pix=pix8;
                                                  btn[i][j+1]->change(pix);
                                                  btn[i][j+1]->eat = true;
                                                }
                                          }
                                          if(x == 7)//判断是否为黑将
                                          {
                                              if(y != 1)//判断是否为红兵
                                              {
                                                  pix=judge(btn[i][j+1]->num);
                                                  btn[i][j+1]->change(pix);
                                                  btn[i][j+1]->eat = true;
                                              }
                                          }
                                          else if (x == 3)
                                          {
                                             if(x>y)
                                             {
                                                 pix=judge(btn[i][j+1]->num);
                                                 btn[i][j+1]->change(pix);
                                                 btn[i][j+1]->eat = true;
                                             }
                                          }
                                          if((x>=y)&&(x != 7)&&(x != 2)&&(x != 1)&&(x != 3))
                                          {
                                              pix=judge(btn[i][j+1]->num);
                                              btn[i][j+1]->change(pix);
                                              btn[i][j+1]->eat = true;
                                          }
                                      }
                          }
                                  }
                              }
                          }
              });

              //右键按下重置全部棋子
              connect(btn[i][j],&ChessPushButton::event2,[=]()
              {
                  if(btn[i][j]->choose)
                  {
                      btn[i][j]->choose = false;
                     for(int i=0;i<4;i++)
                     {
                         for(int j=0;j<8;j++)
                         {
                             btn[i][j]->changefinish();
                             btn[i][j]->eat = false;
                         }
                     }
                  }
              });

              //实现吃子和移动
              connect(btn[i][j],&ChessPushButton::event3,[=]()
              {
                 QPixmap change1;//保存被选中棋子的图片
                 if((btn[i][j]->eat)||(btn[i][j]->num == 0))//棋子可以被吃或者无棋子
                 {
                     for(int p=0;p<4;p++)
                    {
                        for(int q=0;q<8;q++)
                        {
                            if(btn[p][q]->choose)//找到被的选中的棋子
                            {
                                if(btn[i][j]->eat)
                                {
                                    eating = 0;
                                    if(col == 8)
                                    {
                                        row++;
                                        col = 0;
                                    }
                                    //墓地中被吃子的添加
                                    mudi[row][col]->setPixmap(btn[i][j]->pixmap);
                                    mudi[row][col]->setFixedSize(btn[i][j]->width(),btn[i][j]->height());
                                    col++;

                                    change1 = btn[p][q]->pix;
                                    btn[i][j]->change(change1);//替换成被选中棋子的图片
                                    btn[i][j]->num = btn[p][q]->num;//替换成被选中棋子的编号
                                    btn[i][j]->pix = change1;
                                    btn[i][j]->pixmap = btn[p][q]->pixmap;
                                    btn[i][j]->cheakable = btn[p][q]->cheakable;
                                    btn[i][j]->exist = btn[p][q]->exist;

                                    btn[p][q]->num = 0;//原位置置零
                                    btn[p][q]->choose = false;
                                    btn[p][q]->exist = false;
                                    QPixmap pix;
                                    pix = pix0.scaled(btn[p][q]->width(),btn[p][q]->height());
                                    btn[p][q]->setIcon(pix);
                                    btn[p][q]->setStyleSheet("QPushbutton{border:0px}");
                                    btn[p][q]->setIconSize(QSize(pix.width(),pix.height()));
                                    btn[p][q]->pix = pix;
                                    btn[p][q]->pixmap = pix;

                                    for(int a=0;a<4;a++)
                                    {
                                        for(int b=0;b<8;b++)
                                        {

                                            if(btn[a][b]->cheakable)
                                                btn[a][b]->cheakable = false;
                                            else if(btn[a][b]->cheakable == false)
                                                btn[a][b]->cheakable = true;
                                        }
                                    }

                                    if(which)
                                        which = false;
                                    else
                                        which = true;

                                    if(which)
                                        turn->setPixmap(pix15);
                                    else
                                        turn->setPixmap(pix16);

                                    num = 60;
                                    //重置全部棋子
                                    for(int x=0;x<4;x++)
                                    {
                                        for(int y = 0;y<8;y++)
                                        {
                                               btn[x][y]->changefinish();
                                               btn[x][y]->eat = false;
                                        }
                                    }
                                }
                                else if(btn[i][j]->num == 0)
                                {
                                    if(abs(i-p)+abs(j-q)==1)//此空格与被选中棋子距离为1
                                    {
                                        eating++;
                                        change1 = btn[p][q]->pix;
                                        btn[i][j]->change(change1);//替换成被选中棋子的图片
                                        btn[i][j]->num = btn[p][q]->num;//替换成被选中棋子的编号
                                        btn[i][j]->pix = change1;
                                        btn[i][j]->pixmap = btn[p][q]->pixmap;
                                        btn[i][j]->cheakable = btn[p][q]->cheakable;
                                        btn[i][j]->exist = btn[p][q]->exist;

                                        btn[p][q]->num = 0;//原位置置零
                                        btn[p][q]->choose = false;
                                        btn[p][q]->exist = false;
                                        QPixmap pix;
                                        pix = pix0.scaled(btn[p][q]->width(),btn[p][q]->height());
                                        btn[p][q]->setIcon(pix);
                                        btn[p][q]->setStyleSheet("QPushbutton{border:0px}");
                                        btn[p][q]->setIconSize(QSize(pix.width(),pix.height()));
                                        btn[p][q]->pix = pix;
                                        btn[p][q]->pixmap = pix;

                                        for(int a=0;a<4;a++)
                                        {
                                            for(int b=0;b<8;b++)
                                            {

                                                if(btn[a][b]->cheakable)
                                                    btn[a][b]->cheakable = false;
                                                else if(btn[a][b]->cheakable == false)
                                                    btn[a][b]->cheakable = true;
                                            }
                                        }

                                        if(which)
                                            which = false;
                                        else
                                            which = true;

                                        if(which)
                                            turn->setPixmap(pix15);
                                        else
                                            turn->setPixmap(pix16);

                                        num = 60;
                                        //重置全部棋子
                                        for(int x=0;x<4;x++)
                                        {
                                            for(int y = 0;y<8;y++)
                                            {
                                                   btn[x][y]->changefinish();
                                                   btn[x][y]->eat = false;
                                            }
                                        }

                                    }
                                }

                                bool redwin1 = true;
                                bool blackwin1 = true;

                                for(int i=0;i<4;i++)
                                {
                                    for(int j=0;j<8;j++)
                                    {
                                        if(btn[i][j]->num>10)
                                            blackwin1 = false;
                                        if((btn[i][j]->num<10)&&(btn[i][j]->num>0))
                                            redwin1 = false;
                                    }

                                }

                                if(redwin1)
                                {
                                    QPropertyAnimation *animation = new QPropertyAnimation(redwin,"geometry");
                                    animation->setStartValue(QRect(redwin->x(),redwin->y(),redwin->width(),redwin->height()));
                                    animation->setEndValue(QRect(redwin->x(),redwin->y()+600,redwin->width(),redwin->height()));
                                    animation->start();
                                }
                                if(blackwin1)
                                {
                                    QPropertyAnimation *animation = new QPropertyAnimation(blackwin,"geometry");
                                    animation->setStartValue(QRect(blackwin->x(),blackwin->y(),blackwin->width(),blackwin->height()));
                                    animation->setEndValue(QRect(blackwin->x(),blackwin->y()+600,blackwin->width(),blackwin->height()));
                                    animation->start();
                                }

                                if(eating == 20)
                                {
                                    QPropertyAnimation *animation = new QPropertyAnimation(heqi,"geometry");
                                    animation->setStartValue(QRect(heqi->x(),heqi->y(),heqi->width(),heqi->height()));
                                    animation->setEndValue(QRect(heqi->x(),heqi->y()+600,heqi->width(),heqi->height()));
                                    animation->start();
                                }

                            }
                        }
                     }
                 }
              });

         }
      }

      //覆盖物的建立
      for(int i = 0;i < 4;i++)
      {
          for(int j = 0;j < 8;j++)
          {
              QPushButton *coverybutton = new QPushButton;
              coverybutton->setParent(this);
              pix.load(":/image/white.jpg");
              pix=pix.scaled(pix.width()*1.3,pix.height()*1.3);
              coverybutton->setIcon(pix);
              coverybutton->setStyleSheet("QPushButton{border:0px}");
              coverybutton->setFixedSize(pix.width(),pix.height());
              coverybutton->setIconSize(QSize(pix.width(),pix.height()));
              coverybutton->move(153+j*99,87+i*100);
              btncovery[i][j] = coverybutton;
          }
      }

      //隐藏覆盖面，其对应置为可视
      for(int i = 0;i<4;i++)
      {
          for(int j = 0;j<8;j++)
          {
               connect(btncovery[i][j],&QPushButton::clicked,[=](){

               //如果有棋子被选中，则其他棋子无法被翻面
               bool judge = true;
               for(int i = 0;i<4;i++)
               {
                   for(int j = 0;j<8;j++)
                   {
                       if(btn[i][j]->choose)
                           judge = false;
                   }
               }

               if(judge)
               {
                  btncovery[i][j]->hide();
                  btn[i][j]->keshi = true;

                  num = 60;

                  for(int a=0;a<4;a++)
                  {
                      for(int b=0;b<8;b++)
                      {
                              if(btn[a][b]->cheakable)
                                  btn[a][b]->cheakable = false;
                              else if(btn[a][b]->cheakable == false)
                                  btn[a][b]->cheakable = true;
                      }
                  }

                  if(which)
                      which = false;
                  else
                      which = true;

                  if(which)
                      turn->setPixmap(pix15);
                  else
                      turn->setPixmap(pix16);
               }

              });
          }
      }

      //帮助内容的实现
      QLabel * help1= new QLabel(this);
      pix.load(":/image/neirong.png");
      pix = pix.scaled(pix.width()*0.8,pix.height()*0.8);
      help1->setPixmap(pix);
      help1->move(310,0);
      help1->hide();

      connect(help,&QPushButton::pressed,[=](){
          help1->show();
      });
      connect(help,&QPushButton::released,[=](){
          help1->hide();
      });

      connect(&b2,&QPushButton::clicked,[=](){
         this->close();
      });

      redwin->raise();
      blackwin->raise();
      heqi->raise();

}
//背景的布置
void fightscene::paintEvent(QPaintEvent *)
{
     QPainter painter(this);
     QPixmap pix;
     pix.load(":/image/background1.jpg");
     painter.drawPixmap(0,0,this->width(),this->height(),pix);
     pix.load(":/image/qipan1.jfif");
     pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
     painter.drawPixmap(100,50,pix);
     pix.load(":/image/white.png");
     pix=pix.scaled(pix.width()*0.8,pix.height()*0.7);
     painter.drawPixmap(1050,510,pix);
}

//棋子图片的切换判断
QPixmap fightscene::judge(int x)
{
    int y = x;
    if(y == 1)
        return pix7;
    if(y == 2)
        return pix6;
    if(y == 3)
        return pix5;
    if(y == 4)
        return pix4;
    if(y == 5)
        return pix3;
    if(y == 6)
        return pix2;
    if(y == 7)
        return pix1;
    if(y == 11)
        return pix14;
    if(y == 12)
        return pix13;
    if(y == 13)
        return pix12;
    if(y == 14)
        return pix11;
    if(y == 15)
        return pix10;
    if(y == 16)
        return pix9;
    if(y == 17)
        return pix8;
}


