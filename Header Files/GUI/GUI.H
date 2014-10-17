// 651 lines - last updated 29th nov 2000.

/* NOTE : This is only an include file and can't be executed.

   GUIADDON.CPP :  34 functions and 1 class for making GUI softwares easy.
   ~~~~~~~~~~
   By Ankit Rohatgi
   ~~~~~~~~~~~~~~~~
   www.ankitrohatgi.com
   ~~~~~~~~~~~~~~~~~~~~
   REPORT ERRORS TO : ankit@ankitrohatgi.com
   ~~~~~~~~~~~~~~~~~

IMPORTANT :
~~~~~~~~~~
Please copy & paste this before including this file :

  void search(int);

And this function at the end of your file:

  void search(int no)
  {
    //handler code
  }

WINDOW CLOSE BUTTON FORMULA:
	x2-15,y1+2,x2-3,y1+15

*/

// GENERAL INCLUDE FILES. DO NOT INCLUDE THESE IN YOUR PROGRAM
// AS THEY HAVE ALREADY BEEN INCLUDED.

#include<fstream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
extern int x=0,y=0,button=0,loopmain=1;
union REGS i,o;
struct SREGS s;
void initmouse();
void showmouse();
void hidemouse();
void pointer(int pt=1);
int inkey();
void getmouse(int &button,int &x,int &y);
void restrictmouse(int,int,int,int);
void mouseptr(int mark[50],int xstart,int ystart);
void getclick(int,int,int [][5]);
int getlink(int,int,int [][5]);
void invertcolors(int,int,int,int);
void activate(int,int,int,int,int,int [][5],int);
void back(int x1=0,int y1=0,int x2=0,int y2=0,int mode=0,char *file="tempfl.dat");
void sel(int,int,int,int,int);
void say(char *text="",char *title="");
int confirm(char *text="",char *title="");
char* intext(int,int);
void openwindow(int x1=1,int y1=1,int x2=638,int y2=478,char text[]="",int fillst=1,int titlecolor=1,int darkshade=8,int lightshade=15,int normalshade=7);
void buttonon(int,int,int,int,char *,int);
void image(int,int,int,int,char *);
void iconbtn(int,int,int,int,char *,int,int [][5],int);
void cmdbtn(int,int,int,int,char *,int,int,int [][5],int);
void buttoneffect(int,int,int,int);
void buttonclick(int,int,int,int);
void initaddons(char *dir="");
void textfield(int,int,int);
void checkbox(int,int,int);
void progressbar(int,int,int,int);
void menu(int,int,char*,int,int);
int activemenu(int,int,char *,int,int);
void marquee(char *,int,int,int,int);
void pressbtn(int,int [][5]);
void liftbtn(int,int [][5]);
void endgui();

void openwindow(int x1,int y1,int x2,int y2,char text[],int fillst,int titlecolor,int darkshade,int lightshade,int normalshade)
{  hidemouse();
   setfillstyle(fillst,normalshade);
   bar(x1,y1,x2,y2);
   setfillstyle(1,titlecolor);
   bar(x1+1,y1+1,x2-1,y1+15);
   setfillstyle(1,normalshade);
   bar(x2-13,y1+3,x2-3,y1+12);
   settextstyle(2,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(x1+2,y1+2,text);
   setcolor(lightshade);
   line(x1,y1,x2,y1);
   line(x1,y1,x1,y2);
   setcolor(darkshade);
   line(x2,y1,x2,y2);
   line(x2,y2,x1,y2);
   buttonon(x2-15,y1+2,x2-3,y1+15,"X",3);
   showmouse();
}

void buttonon(int x1,int y1,int x2,int y2,char text[],int spc)
{ hidemouse();
  setfillstyle(1,7);
  bar(x1,y1,x2,y2);
  setcolor(0);
  settextstyle(2,HORIZ_DIR,4);
  outtextxy(x1+1+spc,y1+1,text);
  buttoneffect(x1,y1,x2,y2);
  showmouse();
}

void buttoneffect(int x1,int y1,int x2,int y2)
{ setcolor(15);
  line(x1,y1,x2,y1);
  line(x1,y1,x1,y2);
  setcolor(8);
  line(x2,y1,x2,y2);
  line(x1,y2,x2,y2);
}

void initaddons(char dir[])
{
  int gd=VGA,gm=VGAHI;
  initgraph(&gd,&gm,dir);
  initmouse();
  showmouse();
}

void buttonclick(int x1,int y1,int x2,int y2)
{ hidemouse();
  setcolor(0);
  line(x1,y1,x2,y1);
  line(x1,y1,x1,y2);
  setcolor(15);
  line(x2,y1,x2,y2);
  line(x1,y2,x2,y2);
  showmouse();
}

void textfield(int x1,int y1,int length)
{  setfillstyle(1,15);
   bar(x1,y1,(x1+(8*length)),y1+15);
   buttonclick(x1,y1,(x1+(8*length)),y1+15);
}

void checkbox(int x1,int y1,int status)
{ setfillstyle(1,15);
  bar(x1,y1,x1+8,y1+10);
  buttonclick(x1,y1,x1+8,y1+10);
  if(status==1)
  { setfillstyle(1,0);
    bar(x1+2,y1+2,x1+6,y1+8);
  }
  if(status==0)
  { setfillstyle(1,15);
    bar(x1+2,y1+2,x1+6,y1+8);
  }
}

void progressbar(int x1,int y1,int status,int display)
{
  if(display==1)        //make
  {
   setfillstyle(1,7);
   bar(x1,y1,x1+50,y1+10);
   buttonclick(x1,y1,x1+54,y1+10);
   setfillstyle(1,2);
   bar(x1+2,y1+2,(x1+(status/2)),y1+8);
  }
  else if(display==0)         //operate
  { setfillstyle(1,2);
    bar(x1+2,y1+2,(x1+(status/2)),y1+8);
  }
}

void menu(int xcol,int ycol,char *list[],int height,int width)
{ int h=(height*15)+10;
  int w=width*8;
  setfillstyle(1,7);
  bar(xcol,ycol,xcol+w,ycol+h);
  buttoneffect(xcol,ycol,xcol+w,ycol+h);
  settextstyle(2,HORIZ_DIR,4);
  setcolor(0);
  for(int a=0;a<height;a++)
  { outtextxy(xcol+3,(ycol+2+(a*15)),list[a]);
  }
}


void marquee(char text[],int x1,int y1,int x2,int dir)
{ int c=getcolor(),d,e=0;
  float *backgr;
  backgr=new float[100];
  for(int col=x2;col>=x1;col--)
  { if(col>x2+200)
    { e=x2-col;
    }
    else
    { e=200;
    }
    getimage(col-1,y1,(col-1)+textwidth(text),y1+textheight(text)+10,backgr);
    outtextxy(col,y1,text);
    delay(20);
    putimage(col-1,y1,backgr,COPY_PUT);
  }
  delete backgr;
}

// Mouse
void initmouse()
{
   i.x.ax=0;
   int86(0x33,&i,&o);
}

void showmouse()
     {
       i.x.ax=1;
       int86(0x33,&i,&o);
     }

void hidemouse()
     {
       i.x.ax=2;
       int86(0x33,&i,&o);
     }

void getmouse(int& button,int& x,int& y)
     {
       i.x.ax=3;
       int86(0x33,&i,&o);
       button= o.x.bx;
       x=o.x.cx;
       y=o.x.dx;
     }

void restrictmouse(int x1,int y1,int x2,int y2)
     {
      i.x.ax=7;
      i.x.cx=x1;
      i.x.dx=x2;
      int86(0x33,&i,&o);
      i.x.ax=8;
      i.x.cx=y1;
      i.x.dx=y2;
      int86(0x33,&i,&o);
     }
void mouseptr(int mark[50],int xstart,int ystart)
     {
      i.x.ax=9;
      i.x.bx=xstart;
      i.x.cx=ystart;
      i.x.dx=(int)mark;
      segread(&s);
      s.es=s.ds;
      int86x(0x33,&i,&i,&s);

     }


void getclick(int bta,int btb,int link[][5])
{ while(loopmain!=0)
  { getmouse(button,x,y);
    for(int bd=bta;bd<=btb;bd++)
    { getmouse(button,x,y);

      if((x>link[bd][0])&&(y>link[bd][1])&&(x<link[bd][2])&&(y<link[bd][3])&&(button==link[bd][4]))
      { search(bd);
      }
    }
  }
}

int getlink(int bta,int btb,int link[][5])
{ while(loopmain!=0)
  { getmouse(button,x,y);
    for(int bd=bta;bd<=btb;bd++)
    { getmouse(button,x,y);
      if((x>link[bd][0])&&(y>link[bd][1])&&(x<link[bd][2])&&(y<link[bd][3])&&(button==link[bd][4]))
      { return(bd);
      }
    }
  }
  return(0);
}


void activate(int x1,int y1,int x2,int y2,int n,int link[][5],int forbtn)
{ link[n][0]=x1;
  link[n][1]=y1;
  link[n][2]=x2;
  link[n][3]=y2;
  link[n][4]=forbtn;
}

void pressbtn(int no,int link[][5])
{ hidemouse();
  buttonclick(link[no][0],link[no][1],link[no][2],link[no][3]);
  showmouse();
}

void liftbtn(int no,int link [][5])
{ hidemouse();
  buttoneffect(link[no][0],link[no][1],link[no][2],link[no][3]);
  showmouse();
}

void endgui()
{ closegraph();restorecrtmode();exit(1);
}

int activemenu(int xc1,int yc1,char *list[],int rows,int cols)
{ hidemouse();
  /*back(xc1,yc1,xc1+(rows*15)+10,yc1+(cols*8)+10,0);*/
  /*menu(xc1,yc1,test,rows,cols);*/
  int h=((rows*15)+10);
  int w=((cols*8)+10);
  setfillstyle(1,7);
  float *bck;
  float sz=imagesize(xc1,yc1,xc1+w,yc1+h);
  bck=new float[sz];
  getimage(xc1,yc1,xc1+w,yc1+h,bck);
  bar(xc1,yc1,xc1+w,yc1+h);
  buttoneffect(xc1,yc1,xc1+w,yc1+h);
  settextstyle(2,HORIZ_DIR,4);
  setcolor(0);
  for(int a=0;a<rows;a++)
  { outtextxy(xc1+3,(yc1+2+(a*15)),list[a]);
  }
  showmouse();
  getmouse(button,x,y);
  int lc=1,fnc=0,over=-1;
  delay(50);
  while(lc==1)
  { getmouse(button,x,y);
    for(int b=0;b<rows;b++)
    { if(button==1)
      { if((x>xc1+w)||(x<xc1)||(y>yc1+h)||(y<yc1))
	  { fnc=0;lc=0;
	  }
	else if((y>(yc1+(15*b)))&&(y<(yc1+(15*b)+15)))
	  { fnc=b+1;
	    lc=0;
	  }

      }
      if(button==0)
      { if((y>(yc1+(15*b)))&&(y<(yc1+(15*b)+15)))
	{ if((b!=over)||(over==-1))
	  { if(over!=-1)
	     {invertcolors(xc1+2,yc1+(15*over)+1,xc1+w-2,yc1+(15*over)+13);}
	    invertcolors(xc1+2,yc1+(15*b)+1,xc1+w-2,yc1+(15*b)+13);over=b;
	  }
	  over=b;
	}
      }
    }
  }
    hidemouse();
    putimage(xc1,yc1,bck,COPY_PUT);
    showmouse();
    delete bck;
    return(fnc);

}

void back(int x1,int y1,int x2,int y2,int mode,char *file)
{  int ch;char c2;
   if(mode==0)
   {
     float sts=4;
     ofstream outfile(file);
     for(int b=y1;b<=y2;b++)
     { for(int a=x1;a<=x2;a++)
       { ch=getpixel(a,b);
	 outfile<<(char)(ch+28);
       }
       sts+=(((a-x1)/(x2-x1))*100);
     }
     outfile.close();
   }
   else if(mode==1)
   {
     ifstream infile(file);
     for(int b=y1;b<=y2;b++)
     { for(int a=x1;a<=x2;a++)
       { infile.get(c2);ch=(int)c2;
	 putpixel(a,b,ch-28);
       }
     }
     infile.close();

   }
}

void say(char text[],char title[])
{ hidemouse();
  settextstyle(2,0,4);
  int width=textwidth(text)+20;
  int height=60;
  int xcol1=320-(width/2),xcol2=320+(width/2);
  int ycol1=240-(height/2),ycol2=240+(height/2);
/*  float sz=imagesize(xcol1,ycol1,xcol2,ycol2);
  float *bk;
  bk=new float[sz];
  getimage(xcol1,ycol1,xcol2,ycol2,bk);*/
  back(xcol1,ycol1,xcol2,ycol2,0);
  openwindow(xcol1,ycol1,xcol2,ycol2,title);
  setcolor(0);
  buttonon(310,ycol2-17,330,ycol2-2,"OK",3);
  setcolor(0);
  outtextxy(xcol1+10,ycol1+20,text);
  showmouse();
  int lc=1;               //x2-15,y1+2,x2-3,y1+15
  while(lc==1)
  { getmouse(button,x,y);
    if((x>310)&&(x<330)&&(y>ycol2-17)&&(y<ycol2-2)&&(button==1))
    { buttonclick(310,ycol2-17,330,ycol2-2);delay(50);
      lc=0;
    }
    if((x>xcol2-15)&&(y>ycol1+2)&&(x<xcol2-3)&&(y<ycol1+15)&&(button==1))
    { buttonclick(xcol2-15,ycol1+2,xcol2-3,ycol1+15);delay(50);
      lc=0;
    }
    if(inkey()==13)
    { lc=0; }
  }
  hidemouse();
 back(xcol1,ycol1,xcol2,ycol2,1);
/*  putimage(xcol1,ycol1,bk,COPY_PUT);
  delete bk;*/
  showmouse();
  delay(90);
}

char* intext(int x1,int y1)   //intext
{ setcolor(0);
  settextstyle(2,0,4);
  int xcn=0;int in2=0;
  char in[2];
  char *yotext;
  in[1]='\0';
  while(*in!=(char)13)
  { st:
    in[0]=getch();
    if(in[0]==(char)13)
     { break;
     }
    else if(in[0]==(char)8) {in2-=6;xcn--;setfillstyle(1,15);bar(x1+in2,y1,x1+in2+textwidth("W"),y1+textheight("Wg"));goto st;}
    setfillstyle(1,15);bar(x1+in2,y1,x1+in2+textwidth(in),y1+textheight(in));
    outtextxy(x1+in2,y1,in);
    in2+=6;
    yotext[xcn]=in[0];
    xcn++;
  }
  yotext[xcn]='\0';
  return(yotext);
}

int confirm(char text[],char title[])
{
  hidemouse();
  settextstyle(2,0,4);
  int width=textwidth(text)+20;
  int height=60;
  int xcol1=320-(width/2),xcol2=320+(width/2);
  int ycol1=240-(height/2),ycol2=240+(height/2);
  /*float sz=imagesize(xcol1,ycol1,xcol2,ycol2);
  float *bk;
  bk=new float[sz];
  getimage(xcol1,ycol1,xcol2,ycol2,bk);*/
  back(xcol1,ycol1,xcol2,ycol2,0);
  openwindow(xcol1,ycol1,xcol2,ycol2,title);
  setcolor(0);
  buttonon(320-31,ycol2-17,320-1,ycol2-2,"OK",6);
  buttonon(320+1,ycol2-17,320+41,ycol2-2,"Cancel",3);
  sel(320+1,ycol2-17,320+41,ycol2-3,1);
  setcolor(0);
  outtextxy(xcol1+10,ycol1+20,text);
  showmouse();
  int lc=1,ans=0,opt=2,in;               //x2-15,y1+2,x2-3,y1+15
  while(lc==1)
  { getmouse(button,x,y);
    in=inkey();
    if((x>320-31)&&(x<320-1)&&(y>ycol2-17)&&(y<ycol2-2)&&(button==1))
    { buttonclick(320-31,ycol2-17,320-1,ycol2-2);delay(50);ans=1;
      lc=0;
    }
    if((x>xcol2-15)&&(y>ycol1+2)&&(x<xcol2-3)&&(y<ycol1+15)&&(button==1))
    { buttonclick(xcol2-15,ycol1+2,xcol2-3,ycol1+15);delay(50);
      lc=0;
    }
     if((x>320+1)&&(x<320+41)&&(y>ycol2-17)&&(y<ycol2-2)&&(button==1))
     { buttonclick(320+1,ycol2-17,320+41,ycol2-2);delay(50);ans=0;
       lc=0;
     }

     if(in==13)
     { if(opt==1) {ans=1;}
       else if(opt==2) {ans=0;}
       lc=0;
     }
     if(in==75)
     { opt=1;
       sel(320-31,ycol2-17,320-1,ycol2-3,1);
       sel(320+1,ycol2-17,320+41,ycol2-3,0);
     }
     if(in==77)
     { opt=2;
       sel(320-31,ycol2-17,320-1,ycol2-3,0);
       sel(320+1,ycol2-17,320+41,ycol2-3,1);
     }

  }
  hidemouse();
  back(xcol1,ycol1,xcol2,ycol2,1);
  /*putimage(xcol1,ycol1,bk,COPY_PUT);
  delete bk;*/
  showmouse();
  delay(90);
  return(ans);
}

void cmdbtn(int x1,int y1,int x2,int y2,char text[],int no,int link[][5],int forbtn)
{ buttonon(x1,y1,x2,y2,text,3);
  activate(x1,y1,x2,y2,no,link,forbtn);
}
void iconbtn(int x1,int y1,int x2,int y2,char text[],int no,int link[][5],int forbtn)
{ buttonon(x1,y1,x2,y2,"",3);
  activate(x1,y1,x2,y2,no,link,forbtn);
  image(x1+3,y1+3,x2-3,y2-3,text);
}

void image(int x1,int y1,int x2,int y2,char filename[])
{
     char c2;int width,height,ch;
     ifstream infile(filename);
     if(infile)
     {	infile>>width>>height;
	setviewport(x1,y1,x2,y2,1);
	hidemouse();
	for(int a=0;a<=width;a++)
	{ for(int b=0;b<=height;b++)
	  { infile.get(c2);ch=(int)c2;
	    putpixel(a,b,ch-28);
	  }
	}
	setviewport(0,0,639,479,1);
	showmouse();
     }
     infile.close();
}


class windows
{ private:
   int xcol1,ycol1,xcol2,ycol2;
   char *titleofwindow;
  public:
   void newwindow(int x1,int y1,int x2,int y2,char tit[])
    { xcol1=x1;ycol1=y1;xcol2=x2;ycol2=y2;
      titleofwindow=tit;
      hidemouse();
      back(xcol1,ycol1,xcol2,ycol2,0,tit);
      openwindow(xcol1,ycol1,xcol2,ycol2,tit);
      showmouse();
    }
   void setcolors(int titlecol,int darkshade,int lightshade,int normalfill,int fillstyle)
    { openwindow(xcol1,ycol1,xcol2,ycol2,titleofwindow,fillstyle,titlecol,darkshade,lightshade,normalfill);
    }
   void closewindow()
    { hidemouse();
      back(xcol1,ycol1,xcol2,ycol2,1,titleofwindow);
      showmouse();
      remove(titleofwindow);
    }
};

class textbox
{ private:
    char *textfill;
    int x1,y1,len;
    int *bck;
  public:
  void make(int xc1,int yc1,int leng)
  { bck=new int[imagesize(xc1,yc1,xc1+(8*leng),yc1+15)];
    getimage(xc1,yc1,xc1+(8*leng),yc1+15,bck);
    x1=xc1; y1=yc1; len=leng;
    textfield(xc1,yc1,leng);
  }
  void text(char tex[])
  { setfillstyle(1,15);
    bar(x1+2,y1+2,x1+textwidth(tex),y1+13);
    settextstyle(2,HORIZ_DIR,4);
    setcolor(0);
    outtextxy(x1+2,y1+2,tex);
    textfill=strcpy(textfill,tex);
  }
  char *qtext()
  { return(textfill);}
  void clear()
  { putimage(x1,y1,bck,COPY_PUT); }
};

class check
{ private:
   int x1,y1;
  public:
   int stat;
   void make(int xc1,int yc1)
   { checkbox(xc1,yc1,0);
     x1=xc1; y1=yc1; stat=0;
   }
   void on()
   { checkbox(x1,y1,1); stat=1; }
   void off()
   { checkbox(x1,y1,0); stat=0; }

};

void pointer(int pt)
{
 int arrow[32]={ 0x9fff,0x8fff,0x87ff,0x83ff,0x81ff,0x80ff,0x807f,0x803f,0x801f,0x800f,0x80ff,
	       0x887f,0x987f,0xfc3f,0xfc3f,0xfe3f,0x0000,0x2000,0x3000,0x3800,0x3c00,0x3e00,
	       0x3f00,0x3f80,0x3fc0,0x3e00,0x3600,0x2300,0x0300,0x0180,0x0180,0x0000
	    };
int ibeam[32]={ 0xe187,0xe007,0xfc3f,0xfc3f,0xfc3f,0xfc3f,0xfc3f,0xfc3f,0xfc3f,0xfc3f,0xfc3f,
	      0xfc3f,0xfc3f,0xfc3f,0xe007,0xe187,0x0000,0x0e70,0x0180,0x0180,0x0180,0x0180,
	      0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0e70,0x0000
	    };
int cursor[32]={ 0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,
		   0x0080,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,0xff7f,
		   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
		   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
		    };
int wait[32]={ 0x8001,0xc003,0xc003,0xc003,0xc003,0xe007,0xf00f,0xf81f,0xf81f,0xf00f,0xe007,
	       0xc003,0xc003,0xc003,0xc003,0x8001,0x7ffe,0x2004,0x2004,0x2004,0x2664,0x13c8,
	       0x0990,0x0420,0x0420,0x0990,0x13c8,0x27e4,0x2ff4,0x2ff4,0x2004,0x7ffe
	      };
int icon[32]={ 0xffff,0xffff,0xc003,0xc003,0xc003,0xc003,0xc003,0xc003,0xc003,0xc003,0xc003,
	       0xc003,0xc003,0xc003,0xffff,0xffff,0x0000,0x0000,0x3ffc,0x3ffc,0x300c,0x300c,
	       0x33cc,0x33cc,0x33cc,0x33cc,0x300c,0x300c,0x3ffc,0x3ffc,0x0000,0x0000
	      };



hidemouse();
switch(pt)
{ case 1: mouseptr(arrow,1,1);break;
  case 2: mouseptr(ibeam,1,1);break;
  case 3: mouseptr(wait,1,5);break;
  case 4: mouseptr(icon,8,8);break;
  default:break;
}
showmouse();
}

int inkey()
{ char k;
  if(kbhit())
  { k=getch();
    if(k==0)
    { k=getch();
      return((int)k);
    }
    else{ return((int)k);}
  }
  return(0);
}

void sel(int x1,int y1,int x2,int y2,int md)
{ hidemouse();
  if(md==1)  // select
  { setcolor(4);
    rectangle(x1-1,y1-1,x2+1,y2+2);
  }
  else
  { setcolor(7);
    rectangle(x1-1,y1-1,x2+1,y2+2);
  }
  showmouse();
}

void invertcolors(int x1,int y1,int x2,int y2)
{  int cl;
   hidemouse();
   for(int a=x1;a<=x2;a++)
   { for(int b=y1;b<=y2;b++)
     { cl=getpixel(a,b);
       putpixel(a,b,15-cl);
     }
   }
   showmouse();
}
