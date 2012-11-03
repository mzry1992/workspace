USES Crt, Graph, Mouse, Chinese;
CONST
TetVer='5.1';
Debug=false;
ItemPer:Array [101..115] Of Byte=(60,40,20,60,40,20,20,20,8,40,20,30,0,0,0);
Change:Array [0..6,0..3,0..7] Of Byte =(((0,1,1,1,2,1,3,1),(1,0,1,1,1,2,1,3),(0,1,1,1,2,1,3,1),(1,0,1,1,1,2,1,3)),
                                        ((1,0,0,1,1,1,1,2),(0,1,1,1,2,1,1,2),(1,0,1,1,1,2,2,1),(1,0,0,1,1,1,2,1)),
                                        ((1,0,2,0,1,1,2,1),(1,0,2,0,1,1,2,1),(1,0,2,0,1,1,2,1),(1,0,2,0,1,1,2,1)),
                                        ((1,0,2,0,0,1,1,1),(0,0,0,1,1,1,1,2),(1,0,2,0,0,1,1,1),(0,0,0,1,1,1,1,2)),
                                        ((0,0,1,0,1,1,2,1),(1,0,0,1,1,1,0,2),(0,0,1,0,1,1,2,1),(1,0,0,1,1,1,0,2)),
                                        ((1,0,2,0,1,1,1,2),(0,0,0,1,1,1,2,1),(1,0,0,2,1,1,1,2),(2,2,0,1,1,1,2,1)),
                                        ((0,2,0,1,1,1,2,1),(2,2,1,0,1,1,1,2),(2,0,0,1,1,1,2,1),(0,0,1,0,1,1,1,2)));
Name:array[0..1]of string[10]=('１Ｐ','２Ｐ');

{Default Palette Value
R0:array[0..15]of byte=(0, 0, 0, 0,42,42,42,42,21,21,21,21,63,63,63,63);
G0:array[0..15]of byte=(0, 0,42,42, 0, 0,21,42,21,21,63,63,21,21,63,63);
B0:array[0..15]of byte=(0,42, 0,42, 0,42, 0,42,21,63,21,63,21,63,21,63);}

TYPE
  {Type of face}
  face=^node;
  node=record
         time:word;
         bitmap:pointer;
         next:face;
       end;
VAR
  Board:Array [0..1,0..11,1..25] Of Byte;
  Nowx,Nowy,Kind,Trans,NKind,NTrans:array [0..1]of Byte;
  Waste:array [0..1]of longint;
  Speed:Array [0..1]of shortint;
  Now,Next:Array [0..1,0..7] Of Byte;
  TKind :Array [0..255]of byte;
  TTrans:Array [0..255]of byte;
  Combo:array[0..1]of byte;
  MsgWaste:Word;
  Point:array [0..1]of byte;
  Keyset:array [1..18]of integer;
  TetP:array[0..8]of pointer;
  ExitGame:boolean;
  p:pointer;
  {Item Var}
  ItemAllow:boolean;
  ItemP:array[100..112]of pointer;
  Item:array[0..1,0..30]of byte;
  NoItem:array[0..1]of byte;
  {AI Var}
  Com:array[0..1]of boolean;
  AIx,AItrans:array[0..1]of byte;
  AIItem,AIUser:array[0..1]of byte;
  AIOK,Itemfirst,ItemOK:array[0..1]of boolean;
  AISpeed,AIWaste:array[0..1]of Word;
  {Face Var}
  FaceP:array[1..7]of face;
  NowFace:array[0..1]of face;
  NowFaceP:array[0..1]of byte;
  CountTime:array[0..1]of word;
  AllowTime:array[0..1]of word;
  FaceX,FaceY:array[0..1]of integer;
  {Mouse Var}
  mousex,mousey,mousekey,t,c:word;
  b:boolean;
  {Bright and Dark Effect}
  red,grn,blu,red0,grn0,blu0 : array[0..255] of byte;
function inttostr(x:integer):string;
  var
    s:string[6];
  begin
    str(x,s);
    inttostr:=s;
  end;
Function Read_Key:integer;
  var
    ch:char;
    i:integer;
  begin
    ch:=Upcase(readkey);
    if ch=#0 then i:=255 else i:=0;
    if ch=#0 then ch:=readkey;
    Read_key:=i+ord(ch);
  end;
Function PressKey:Byte;
  var
    i:byte;
    x:integer;
    t1,t2,t3:word;
  Begin
    x:=0;
    if KeyPressed then x:=Read_key else begin
    UpMouse(LeftKey,t1,c,t2,t3);
    if c>0 then x:=1001;
    UpMouse(RightKey,t1,c,t2,t3);
    if c>0 then x:=1002;
    UpMouse(MidKey,t1,c,t2,t3);
    if c>0 then x:=1004;
    end;
    i:=18;
    while (i>0)and(keyset[i]<>x) do dec(i);
    if x=13 then i:=101;
    if x=27 then i:=102;
    PressKey:=i;
  End;

procedure outportb(pt:word; b:byte);
begin
    asm  mov dx, pt
         mov al, b
         out dx, al
     end;
end;

function inportb(pt:word): byte;
var  k: byte;
begin
    asm  mov dx, pt
         in al, dx
         mov k, al
    end;
    inportb := k;
end;

procedure closescr;  {关闭屏幕}
var   b : byte;
begin
    outportb($3C4,1);
    b := inportb($3C5);
    b := b or $20;
    outportb($3C5,b);
end;

procedure openscr; {打开屏幕}
var   b : byte;
begin
    outportb($3c4,1);
    b := inportb($3c5);
    b := b and $DF;
    outportb($3C5,b);
end;

procedure chgcolor(num,red,grn,blu: byte); {修改DAC寄存器}
begin
    outportb($3C8,num);  {颜色号}
    outportb($3C9,red);
    outportb($3C9,grn);
    outportb($3C9,blu);
end;

procedure dark; {修改DAC寄存器表各值为0}
var i: integer;
begin
   for i:=0 to 255 do
   begin
       outportb($3C7,i);    {设置为读DAC表方式}
       red0[i] := inportb($3C9);
       grn0[i] := inportb($3C9);
       blu0[i] := inportb($3C9);
       red[i] := 0; grn[i]:=0; blu[i] := 0;
       chgcolor(i,0,0,0);
   end;
end;

procedure bright(Delays:word);
var  i,j,flg : integer;
begin
    flg := 1;
    repeat
       flg := 0;
       for i := 0 to 255 do
         begin
             if red[i] <> red0[i] then
                begin
                    flg := 1;   red[i] := red[i] + 1;
                end;
             if grn[i] <> grn0[i] then
                begin
                    flg := 1;   grn[i] := grn[i] + 1;
                end;
             if blu[i] <> blu0[i] then
                begin
                    flg := 1;   blu[i] := blu[i] + 1;
                end;
              chgcolor(i,red[i],grn[i],blu[i]);
         end;
         delay(Delays);
    until flg = 0;
end;

procedure darkout(Delays:word);
var  i,j,flg : integer;
begin
    flg := 1;
    red := red0;  grn := grn0; blu := blu0;
    repeat
       flg := 0;
       for i := 0 to 255 do
         begin
             if red[i] <> 0 then
                begin
                    flg := 1;   red[i] := red[i] - 1;
                end;
             if grn[i] <> 0 then
                begin
                    flg := 1;   grn[i] := grn[i] - 1;
                end;
             if blu[i] <> 0 then
                begin
                    flg := 1;   blu[i] := blu[i] - 1;
                end;
              chgcolor(i,red[i],grn[i],blu[i]);
         end;
         delay(Delays);
    until flg = 0;
end;

FUNCTION BoardHeight(Player:byte):byte;
  var
    i,j:byte;
  Begin
    for i:=1 to 24 do
      for j:=1 to 10 do
        if Board[Player,j,i]>0 then begin
          BoardHeight:=25-i;
          Exit;
        end;
    BoardHeight:=0;
  End;
PROCEDURE DrawTetri(x1,y1,x2,y2:integer);
  var
    col,i:integer;
  Begin
    putimage(x1,y1,tetp[getcolor]^,NormalPut);
  End;
Procedure Frame(Player:byte);
  forward;
Procedure NoMsg;
 Begin
   setfillstyle(1,0);
   Bar(212,108,428,152);
   setcolor(15);
   line(GetMaxX div 2,107,GetMaxX div 2,153);
 end;
Procedure Msg(s1,s2:string;waste:word;Color:byte);
 Begin
   setfillstyle(1,0);
   Bar(212,110,428,150);
   SetColor(Color);
   if s2='' then
     OutChinese((GetMaxX-Length(s1)*8)div 2,122,s1,0)
   else begin
     OutChinese((GetMaxX-Length(s1)*8)div 2,113,s1,0);
     OutChinese((GetMaxX-Length(s2)*8)div 2,131,s2,0);
   end;
   SetColor(15);
   SetLineStyle(DottedLn, 0, NormWidth);
   Rectangle(214,110,426,150);
   SetLineStyle(UserBitLn, $C3, ThickWidth);
   Rectangle(214,110,426,150);
   SetLineStyle(0, 0, NormWidth);
   MsgWaste:=Waste;
 End;

Procedure Shake(Player:byte;Times:integer);
 var
   P,P2: Pointer;
   Size,Size2: Word;
   i,j:integer;
   b:boolean;
 Begin
   Size := ImageSize(7+Player*(GetMaxX-210), 3, 203+Player*(GetMaxX-210), 479);
   GetMem(P, Size);
   GetImage(7+Player*(GetMaxX-210), 3, 203+Player*(GetMaxX-210), 479, P^);
   Size2 := ImageSize(7+Player*(GetMaxX-210), 475, 203+Player*(GetMaxX-210), 480);
   GetMem(P2, Size2);
   GetImage(7+Player*(GetMaxX-210), 474, 203+Player*(GetMaxX-210), 479, P2^);
   b:=true;
   for i:=1 to times do Begin
     if b then Begin if times>=9 then
                       case i of
                         1:setbkcolor(7);
                         3:setbkcolor(8);
                         5:setbkcolor(0);
                       end;{case}
                     PutImage(7+Player*(GetMaxX-210), 6, P^, NormalPut);
                     PutImage(7+Player*(GetMaxX-210), 0, P2^, NormalPut);
               End
       else PutImage(7+Player*(GetMaxX-210), 0, P^, NormalPut);
     NoItem[abs(Player-1)]:=NoItem[abs(Player-1)]+40;
     for j:=1 to 10 do begin
       Frame(abs(Player-1));
       Waste[abs(Player-1)]:=Waste[abs(Player-1)]+1;
       CountTime[0]:=CountTime[0]+1;
       CountTime[1]:=CountTime[1]+1;
       Delay(1);
     end;
     NoItem[abs(Player-1)]:=NoItem[abs(Player-1)]-40;
     b:=not b;
   end;
   PutImage(7+Player*(GetMaxX-210), 0, P2^, NormalPut);
   PutImage(7+Player*(GetMaxX-210), 3, P^, NormalPut);
   FreeMem(P, Size);
   FreeMem(P2, Size2);
 end;
PROCEDURE MovePic(x1,y1,x2,y2:integer;p:pointer);
  CONST
    vt=0;
    t=50;
    d=10;
  VAR
    x,y,sx,sy:real;
    vx,vy,ax,ay:real;
    i,j:integer;
    temp:array[0..1]of byte;
  Begin
    x:=x1;           y:=y1;
    sx:=x2-x1;       sy:=y2-y1;
    vx:=2*sx/t;      vy:=2*sy/t;
    ax:=(vt-vx)/t;   ay:=(vt-vy)/t;
    temp[0]:=NoItem[0];  temp[1]:=NoItem[1];
    NoItem[0]:=0;    NoItem[1]:=0;
    putimage(round(x),round(y),p^,XorPut);
    delay(d);
    putimage(round(x),round(y),p^,XorPut);
    for i:=1 to t do begin
      NoItem[0]:=0;                NoItem[1]:=0;
      x:=x1+(vx*i+ax*i*i/2);       y:=y1+(vy*i+ay*i*i/2);
      putimage(round(x),round(y),p^,XorPut);
      delay(d);
      putimage(round(x),round(y),p^,XorPut);
      NoItem[0]:=NoItem[0]+40;
      NoItem[1]:=NoItem[1]+40;
      for j:=1 to d do begin
        Frame(0);
        Frame(1);
        Waste[0]:=Waste[0]+1;
        Waste[1]:=Waste[1]+1;
        CountTime[0]:=CountTime[0]+1;
        CountTime[1]:=CountTime[1]+1;
      end;
      NoItem[0]:=NoItem[0]-40;
      NoItem[1]:=NoItem[1]-40;
    end;
    NoItem[0]:=temp[0];   NoItem[1]:=temp[1];
  end;

PROCEDURE Furbish(Player:byte);
  VAR B,C:Byte;
  Begin
    For C:=24 downto 2 Do Begin
        For B:=1 To 10 Do
        If Board[Player,B,C]>100 Then
          Putimage(b*19-10+Player*(GetMaxX-209),c*19-13,ItemP[Board[Player,B,C]]^,CopyPut)
        Else Begin
          setcolor(Board[Player,B,C]);
          DrawTetri(b*19-10+Player*(GetMaxX-209),c*19-13,b*19+8+Player*(GetMaxX-209),c*19+5);
        End;
    End;
  End;
FUNCTION Canmove(Player,X,Y:Byte):Boolean;
BEGIN
Canmove:=True;
If Board[Player,X+Now[Player,0],Y+Now[Player,1]]>0 Then Canmove:=False;
If Board[Player,X+Now[Player,2],Y+Now[Player,3]]>0 Then Canmove:=False;
If Board[Player,X+Now[Player,4],Y+Now[Player,5]]>0 Then Canmove:=False;
If Board[Player,X+Now[Player,6],Y+Now[Player,7]]>0 Then Canmove:=False;
If X>11 Then Canmove:=False;
End;

FUNCTION CheckFace(Player:byte):byte;
  Begin
    CheckFace:=1;{Normal}
    Case BoardHeight(Player) of
      16..24:CheckFace:=3;{Danger}
      0..5:if BoardHeight(abs(Player-1))>=10 then CheckFace:=2;{Safety}
    End;
    if BoardHeight(abs(Player-1))-BoardHeight(Player) in [8..24] then
      CheckFace:=2;{Safety}
  End;

PROCEDURE ChangeFace(Player,NewFace:byte;FaceTime:word);
  Begin
    NowFaceP[Player]:=NewFace;
    NowFace[Player]:=FaceP[NewFace];
    PutImage(FaceX[Player],FaceY[Player],NowFace[Player]^.bitmap^,NormalPut);
    CountTime[Player]:=0;
    AllowTime[Player]:=FaceTime;
  End;

PROCEDURE PlayFace(Player:byte);
  Begin
    inc(CountTime[Player]);
    if AllowTime[Player]>1 then dec(AllowTime[Player]);
    if AllowTime[Player]=1 then ChangeFace(Player,CheckFace(Player),0);
    if CountTime[Player]>=NowFace[Player]^.time then begin
      CountTime[Player]:=CountTime[Player]-NowFace[Player]^.time;
      NowFace[Player]:=NowFace[Player]^.next;
      PutImage(FaceX[Player],FaceY[Player],NowFace[Player]^.bitmap^,NormalPut);
    end;
  End;

PROCEDURE Show(Player,color:byte);
  Begin
   setcolor(color);
   DrawTetri((Nowx[Player]+Now[Player,0])*19-10+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,1])*19-13,
     (Nowx[Player]+Now[Player,0])*19+8+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,1])*19+5);
   DrawTetri((Nowx[Player]+Now[Player,2])*19-10+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,3])*19-13,
     (Nowx[Player]+Now[Player,2])*19+8+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,3])*19+5);
   DrawTetri((Nowx[Player]+Now[Player,4])*19-10+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,5])*19-13,
     (Nowx[Player]+Now[Player,4])*19+8+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,5])*19+5);
   DrawTetri((Nowx[Player]+Now[Player,6])*19-10+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,7])*19-13,
     (Nowx[Player]+Now[Player,6])*19+8+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,7])*19+5);
  End;

PROCEDURE NoFlashShow(Player:byte;nx,ny:byte;color:byte);
  VAR
    i,j:byte;
    needput:boolean;
  Begin
    setcolor(color);
    for i:=0 to 3 do begin
      {needput:=true;
      for j:=0 to 3 do
        if (Nowx[Player]+Now[Player,j*2]=Nx+Now[Player,i*2])
             and (Nowy[Player]+Now[Player,j*2+1]=Ny+Now[Player,i*2+1])
          then needput:=false;
      if needput then}
        DrawTetri((nx+Now[Player,i*2])*19-10+Player*(GetMaxX-209),(Ny+Now[Player,i*2+1])*19-13,
          (nx+Now[Player,i*2])*19+8+Player*(GetMaxX-209),(Ny+Now[Player,i*2+1])*19+5);
    end;
    setcolor(0);
    for i:=0 to 3 do begin
      needput:=true;
      for j:=0 to 3 do
        if (Nowx[Player]+Now[Player,i*2]=Nx+Now[Player,j*2])
             and (Nowy[Player]+Now[Player,i*2+1]=Ny+Now[Player,j*2+1])
          then needput:=false;
      if needput then
        DrawTetri((Nowx[Player]+Now[Player,i*2])*19-10+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,i*2+1])*19-13,
          (Nowx[Player]+Now[Player,i*2])*19+8+Player*(GetMaxX-209),(Nowy[Player]+Now[Player,i*2+1])*19+5);
    end;
    Nowx[Player]:=nx;
    Nowy[Player]:=ny;
  End;

PROCEDURE AddLine(Player:byte;n:shortint);
  var
    i,j,k:integer;
    x,y:byte;
  begin
    x:=1; y:=24;
    if n>=0 then y:=y-n else x:=x-n;
    if n>=0 then for i:=x to y do
      for j:=1 to 10 do
        Board[Player,j,i]:=Board[Player,j,i+n]
    else begin
      for i:=y downto x do
        for j:=1 to 10 do
          Board[Player,j,i]:=Board[Player,j,i+n];
      for i:=x downto 1 do
        for j:=1 to 10 do
          Board[Player,j,i]:=0;
    end;
    for k:=24 downto 24-n+1 do begin
      for j:=1 to 10 do Board[Player,j,k]:=8;
        Board[Player,Random(10)+1,k]:=0;
    end;
    if Canmove(Player,Nowx[Player],Nowy[Player]-n)and(Nowy[Player]>n) then Nowy[Player]:=Nowy[Player]-n
      else Nowy[Player]:=1;
      Furbish(Player);
    Show(Player,Kind[Player]+1);
  end;
PROCEDURE ShowItem(Player:Byte);
  forward;
PROCEDURE Clear(Player:byte);
Var
  A,B,C,X,Y,Z:Byte;
  times:integer;
  D:Boolean;
Begin
  times:=0;
  For A:=24 Downto 1 Do
   Begin
    D:=True;
    For B:=1 To 10 Do
     If Board[Player,B,A]=0 Then D:=False;
    If D=True Then
     Begin
       times:=times+1;
       For B:=1 To 10 Do
         If Board[Player,B,A]>100 Then Begin
           X:=0;
           While Item[Player,X]<>0 do inc(X);
           Item[Player,X]:=Board[Player,B,A];
         End;
       For C:=A Downto 2 Do
       For B:=1 To 10 Do
         Board[Player,B,C]:=Board[Player,B,C-1];
       For B:=1 To 10 Do
         Board[Player,B,1]:=0;
       X:=Random(10)+1;
       Y:=101+Random(12);
       if A=24 then Z:=A-1 else Z:=A+1;
       If ItemAllow and(Random<=ItemPer[Y]/100)
         and(Board[Player,X,Z]>0)and(Board[Player,X,Z]<100) Then
           Board[Player,X,Z]:=Y;
       A:=A+1;
     End;
   End;
   if times>0 then Furbish(Player);
   if times>0 then ShowItem(Player);
   if times>=3 then Begin
     Addline(abs(Player-1),times-1);
     setcolor(15);
     settextstyle(0,0,4);
     outtextxy(14+Player*(Getmaxx-210),100,inttostr(times));
     setcolor(10);
     settextstyle(0,0,3);
     outtextxy(196-TextWidth('Lines!')+Player*(Getmaxx-7-196),108,'Lines!');
   end;
   if times>0 then inc(Combo[Player]) else Combo[Player]:=0;
   if Combo[Player]>=3 then begin
     Addline(abs(Player-1),Combo[Player]-2);
     setcolor(15);
     settextstyle(0,0,4);
     outtextxy(14+Player*(Getmaxx-210),134,inttostr(Combo[Player]));
     setcolor(14);
     settextstyle(0,0,3);
     outtextxy(196-TextWidth('Combo!')+Player*(Getmaxx-7-196),142,'Combo!');
   end;
   if (times>=3)or(Combo[Player]>=3) then begin
     if CheckFace(Player)<>3 then ChangeFace(Player,5,2000);
     ChangeFace(abs(Player-1),4,2000);
     shake(Player,ord(times>=3)*(times*2+3)+ord(Combo[Player]>=3)*(4+Combo[Player]));
     Furbish(Player);
   end;
  End;
PROCEDURE ShowNext(Player,color:byte);
Begin
   setcolor(0);
   DrawTetri((10+Now[Player,0])*19+35+Player*115,(2+Now[Player,1])*19-13,
     (10+Now[Player,0])*19+53+Player*115,(2+Now[Player,1])*19+5);
   DrawTetri((10+Now[Player,2])*19+35+Player*115,(2+Now[Player,3])*19-13,
     (10+Now[Player,2])*19+53+Player*115,(2+Now[Player,3])*19+5);
   DrawTetri((10+Now[Player,4])*19+35+Player*115,(2+Now[Player,5])*19-13,
     (10+Now[Player,4])*19+53+Player*115,(2+Now[Player,5])*19+5);
   DrawTetri((10+Now[Player,6])*19+35+Player*115,(2+Now[Player,7])*19-13,
     (10+Now[Player,6])*19+53+Player*115,(2+Now[Player,7])*19+5);

   setcolor(color);
   DrawTetri((10+Next[Player,0])*19+35+Player*115,(2+Next[Player,1])*19-13,
     (10+Next[Player,0])*19+53+Player*115,(2+Next[Player,1])*19+5);
   DrawTetri((10+Next[Player,2])*19+35+Player*115,(2+Next[Player,3])*19-13,
     (10+Next[Player,2])*19+53+Player*115,(2+Next[Player,3])*19+5);
   DrawTetri((10+Next[Player,4])*19+35+Player*115,(2+Next[Player,5])*19-13,
     (10+Next[Player,4])*19+53+Player*115,(2+Next[Player,5])*19+5);
   DrawTetri((10+Next[Player,6])*19+35+Player*115,(2+Next[Player,7])*19-13,
     (10+Next[Player,6])*19+53+Player*115,(2+Next[Player,7])*19+5);
  End;

procedure TurnTetri(Player:byte);
  VAR
    N,I:Shortint;
  Begin
    Show(Player,0);
    Trans[Player]:=Trans[Player]+1;
    If Trans[Player]=4 Then Trans[Player]:=0;
    For N:=0 To 7 Do
      Now[Player,N]:=Change[Kind[Player],Trans[Player],N];
    N:=0;
    While Not(Canmove(Player,Nowx[Player]+N,Nowy[Player])) and (N<=2) do inc(N);
    If N=3 then begin
      N:=0;
      While Not(Canmove(Player,Nowx[Player]+N,Nowy[Player])) and (N>=-2) do Dec(N);
    end;
    If N=-3 Then
      Begin
        Trans[Player]:=Trans[Player]-1;
        If Trans[Player]=255 Then Trans[Player]:=3;
        For I:=0 To 7 Do
          Now[Player,I]:=Change[Kind[Player],Trans[Player],I];
      End
    Else Nowx[Player]:=Nowx[Player]+N;
    Show(Player,Kind[Player]+1);
  End;

procedure FastDown(Player:byte);
  Begin
    Show(Player,0);
    Repeat
      If Canmove(Player,Nowx[Player],Nowy[Player]+1) Then
        {NoFlashShow(Player,Nowx[Player],Nowy[Player]+1,Kind[Player]+1);}
        Nowy[Player]:=Nowy[Player]+1;
    Until Not(Canmove(Player,Nowx[Player],Nowy[Player]+1));
    Show(Player,Kind[Player]+1);
    {Shake(Player,1);}
    Waste[Player]:=(10-Speed[Player])*50
  End;

Procedure ShowItem(Player:byte);
  const
    msgitem:array[101..115]of string[24]=('增加一行方块',
                                          '增加两行方块',
                                          '增加三行方块',
                                          '消去一行方块',
                                          '消去两行方块',
                                          '消去三行方块',
                                          '加快方块下落速度',
                                          '减慢方块下落速度',
                                          '与对手交换游戏',
                                          '偷取对方一个道具',
                                          '方块向下塌方　消除空格',
                                          '向右挤压方块　消除空格',
                                          '',
                                          '',
                                          '');
  var
    i:integer;
  begin
    setcolor(0);
    for i:=0 to 4 do
      if item[Player,i]>100 then
        putimage(214+Player*117+i*19,240,itemp[item[Player,i]]^,NormalPut)
      else
        DrawTetri(214+Player*117+i*19,240,233+Player*117+i*19,259);
    for i:=0 to 4 do
      if item[Player,i+5]>100 then
        putimage(214+Player*117+i*19,265,itemp[item[Player,i+5]]^,NormalPut)
      else
        DrawTetri(214+Player*117+i*19,265,233+Player*117+i*19,284);
    if item[Player,0]<>0 then setcolor(15) else setcolor(0);
    Rectangle(213+Player*117,239,233+Player*117,259);
    setcolor(0);
    for i:=295 to 329 do  {(212,293,311,331);(329,293,428,331);}
      line(214+Player*117, i,309+Player*117, i);
    setcolor(10);
    if item[Player,0]>99 then begin
      if length(msgitem[item[Player,0]])>12 then begin
        outchinese(214+Player*117,295,copy(msgitem[item[Player,0]],1,12),0);
        outchinese(214+Player*117,313,copy(msgitem[item[Player,0]],13,24),0);
      end else
        outchinese(214+Player*117,295,msgitem[item[Player,0]],0);
    end;
  end;

Procedure ChangeItem(Player:byte);
  var
    i,x,t:byte;
  begin
    x:=30;
    while Item[Player,x]=0 do x:=x-1;
    t:=Item[Player,0];
    for i:=0 to x do Item[Player,i]:=Item[Player,i+1];
    Item[Player,x]:=t;
    ShowItem(Player);
  end;

procedure UseItem(User,Player:byte);
  var
    i:byte;
  procedure Item109;
    var
      i,j,temp:Byte;
    begin
      MovePic(214+User*117,240,GetMaxX div 2-250,120,p);
      MovePic(GetMaxX div 2-250,120,GetMaxX div 2+250,120,p);
      for i:=0 to 11 do
        for j:=1 to 25 do
          begin
            temp:=Board[0,i,j];
            Board[0,i,j]:=Board[1,i,j];
            Board[1,i,j]:=temp;
          end;
      Nowy[0]:=1;
      Nowy[1]:=1;
      Furbish(0);
      Furbish(1);
      AIOK[Player]:=False;
    end;
  procedure Item110;
    var
      x,y,z,i:byte;
    begin
      MovePic(214+User*117,240,256+Player*118,261,p);
      if Item[Player,0]=0 then Msg(Name[User]+'对方没有道具可偷。','',2000,4) else begin
        x:=0;
        while (Item[Player,x+1]>0)and(x<=20) do inc(x);
        y:=Random(x+1);
        z:=Item[Player,y];
        for i:=y to x do Item[Player,i]:=Item[Player,i+1];
        x:=0;
        while (Item[User,x]>0)and(x<=30) do inc(x);
        if x<=30 then Item[User,x]:=z;
        ShowItem(Player);
        if Player=1 then ItemOK[Player]:=False;
      end;
    end;
  Procedure Item111;
    var
      i,j,k,X:byte;
      D,S:boolean;
    begin
      MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,300,p);
      for i:=1 to 10 do
        for j:=3 to 24 do
          if (Board[Player,i,j]=0)and(Board[Player,i,j-1]>0)then begin
            if j=3 then Board[Player,i,2]:=0;
            for k:=j downto 3 do
              Board[Player,i,k]:=Board[Player,i,k-1];
          end;
      furbish(Player);
      if canmove(Player,Nowx[Player],Nowy[Player]) then show(Player,kind[Player]+1)
        else begin Nowy[Player]:=1;show(Player,kind[Player]+1) end;
      shake(Player,3);
      S:=False;
      For i:=24 Downto 1 Do
        Begin
         D:=True;
         For j:=1 To 10 Do
          If Board[Player,j,i]=0 Then D:=False;
          If D=True Then
          Begin
            S:=True;
            For j:=1 To 10 Do
              If Board[Player,j,i]>100 Then Begin
                X:=0;
                While Item[Player,X]<>0 do inc(X);
                Item[Player,X]:=Board[Player,j,i];
              End;
            For k:=i Downto 2 Do
            For j:=1 To 10 Do
              Board[Player,j,k]:=Board[Player,j,k-1];
            i:=i+1;
          End;
        End;
      if S then begin
        furbish(Player);
        if canmove(Player,Nowx[Player],Nowy[Player]) then show(Player,kind[Player]+1)
          else begin Nowy[Player]:=1;show(Player,kind[Player]+1) end;
        shake(Player,9);
      end;
      if Player=1 then AIOK[Player]:=False;
    End;
  Procedure Item112;
    var
      i,j,k:byte;
    begin
      MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,300,p);
      for i:=2 to 24 do begin
        for j:=2 to 10 do
          if (Board[Player,j,i]=0)and(Board[Player,j-1,i]>0)then
            for k:=j downto 2 do
              Board[Player,k,i]:=Board[Player,k-1,i];
        Board[Player,1,i]:=0
      end;
      furbish(Player);
      if canmove(Player,Nowx[Player],Nowy[Player]) then show(Player,kind[Player]+1)
        else begin Nowy[Player]:=1;show(Player,kind[Player]+1) end;
      shake(Player,3);
      if Player=1 then AIOK[Player]:=False;
    end;
  begin
    if CheckFace(User)=3 then ChangeFace(User,7,2000)
      else ChangeFace(User,5,2000);
    if Item[User,0]>100 then Msg(Name[User]+'使用道具！','',2000,User+9)
      else Msg(Name[User]+'没有道具。','',2000,4);
    case Item[User,0] of
      101..103:begin
                 MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,420,p);
                 addline(Player,Item[User,0]-100);
               end;
      104..106:begin
                 MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,420,p);
                 addline(Player,0-(Item[User,0]-103));
               end;
      107:begin
            MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,120,p);
            Speed[Player]:=Speed[Player]+3;
          end;
      108:begin
            MovePic(214+User*117,240,GetMaxX div 2-250+Player*500,120,p);
            Speed[Player]:=Speed[Player]-3;
          end;
      109:Item109;
      110:Item110;
      111:Item111;
      112:Item112;
    end;{case}
    for i:=0 to 29 do Item[User,i]:=Item[User,i+1];
    ShowItem(User);
    if User<>Player then ChangeFace(Player,4,2000);
  end;

Procedure AIUseItem(Player:byte);
  var
    x,t:byte;
    bo,ok:boolean;
  Function SearchItem(Which:byte):byte;
    var
      i:byte;
    Begin
      i:=0;
      While (i<=20)and(Item[Player,i]>0)and(Item[Player,i]<>Which)do inc(i);
      if (Item[Player,i]=0)or(i>20) then SearchItem:=100
        else SearchItem:=i;
    End;
  Begin
    ok:=False;
    Itemfirst[Player]:=False;
    {Item109}
    bo:=False;
    For x:=1 to 10 do If Board[Player,x,5]>0 then bo:=True;
    For x:=1 to 10 do If Board[abs(Player-1),x,6]>0 then bo:=False;
    If bo then x:=SearchItem(109) else x:=100;
    if x<>100 then Begin ok:=True;AIItem[Player]:=109;AIUser[Player]:=0;Itemfirst[Player]:=True;End;
    {Item 104-106}
    If not ok then Begin
      bo:=False;
      For x:=1 to 10 do If Board[Player,x,17]>0 then bo:=True;
      If bo then begin
        x:=SearchItem(106);
        if x=100 then x:=SearchItem(105);
        if x=100 then x:=SearchItem(104);
        if x<100 then Begin ok:=True;AIItem[Player]:=Item[Player,x];AIUser[Player]:=Player;End;
      end;
    End;
    {Item 108}
    If not ok then Begin
      x:=SearchItem(108);
      if x<>100 then Begin ok:=True;AIItem[Player]:=108;AIUser[Player]:=Player;End;
    End;
    {Item 107}
    If not ok then Begin
      x:=SearchItem(107);
      if x<>100 then Begin ok:=True;AIItem[Player]:=107;AIUser[Player]:=abs(Player-1);End;
    End;
    {Item 101-103}
    If (not ok)and((Item[Player,4]>0)or(Random<=0.3)) then Begin
      bo:=False;
      For x:=1 to 10 do If Board[abs(Player-1),x,20]>0 then bo:=True;
      If bo then begin
        x:=SearchItem(103);
        if x=100 then x:=SearchItem(102);
        if x=100 then x:=SearchItem(101);
        if x<>100 then Begin ok:=True;AIItem[Player]:=Item[Player,x];AIUser[Player]:=abs(Player-1);End;
      end;
    End;
    {Item 111-112}
    If not ok then Begin
      bo:=False;
      For x:=1 to 10 do If Board[Player,x,12]>0 then bo:=True;
      If bo then begin
        x:=SearchItem(111);
        if x=100 then x:=SearchItem(112);
        if x<100 then Begin ok:=True;AIItem[Player]:=Item[Player,x];AIUser[Player]:=Player;Itemfirst[Player]:=False;End;
      end;
    End;
    {Item 110}
    If (not ok)and(Item[abs(Player-1),2]>0) then begin
      x:=SearchItem(110);
      if x<>100 then Begin ok:=True;AIItem[Player]:=Item[Player,x];AIUser[Player]:=abs(Player-1);End;
    End;
    If not ok then AIItem[Player]:=0;
  End;

Function AI_Try(Player,kind,Trans,x:byte):word;
  const
    score:array[0..6,0..3,0..11]of byte=(
      ((10, 0,50, 0, 0,50, 0, 0,50, 0,10, 50),
       (10,10, 0,10,10, 0,10,10, 0,10,10,160),
       (10, 0,50, 0, 0,50, 0, 0,50, 0,10, 50),
       (10,10, 0,10,10, 0,10,10, 0,10,10,160)),
      (( 0,10, 0,10, 0,60, 0,10, 0, 0,10,60),
       (10, 0,40, 0, 0, 0, 0,10,40, 0, 0,50),
       (10, 0, 0,10, 0, 0,10,60,60, 0,10, 0),
       ( 0, 0, 0,10, 0,40, 0, 0,50, 0,10,40)),
      ((10,10,50,10,10,50,10,10,50,10,10,50),
       ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
       ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
       ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)),
      (( 0, 0, 0, 0,10,50,10, 0,40, 0, 0,40),
       ( 5, 0, 0,10, 0,60, 0,10, 0, 0,10,60),
       ( 0, 0, 0, 0,10,50,10, 0,40, 0, 0,40),
       ( 5, 0, 0,10, 0,60, 0,10, 0, 0,10,60)),
      ((10, 0,50, 0, 0, 0, 0, 0,40, 0,10,40),
       ( 0, 0, 0,10, 0, 0, 0,10,60,10, 0,60),
       (10, 0,50, 0, 0, 0, 0, 0,40, 0,10,40),
       ( 0, 0, 0,10, 0, 0, 0,10,60,10, 0,60)),
      ((10, 0, 0, 0,10,40,10, 0, 0,10,40,40),
       (10, 0, 0,10, 0,40, 0, 0,50, 0,10,40),
       ( 0,10, 0,10, 0,60, 0,10, 0, 0, 0,60),
       (50,10,40,10,40, 0, 0, 0, 0, 0,10, 0)),
      ((10,50,40,10, 0, 0, 0, 0, 0, 0,10,40),
       ( 0,10,60,10, 0, 0,10, 0, 0,10, 0,60),
       ( 0,10, 0,10, 0,40, 0, 0,50, 0,10,40),
       (10, 0,40, 0,10, 0, 0,10, 0,40,10,40))
    );
  var
    y,i,j:byte;
    N2:byte;
    t:word;{Temp Score}
    Tet:array[0..7]of byte;
  FUNCTION Candown:Boolean;
    BEGIN
      candown:=True;
      If Board[Player,x+Tet[0],y+Tet[1]+1]>0 Then candown:=False;
      If Board[Player,x+Tet[2],y+Tet[3]+1]>0 Then candown:=False;
      If Board[Player,x+Tet[4],y+Tet[5]+1]>0 Then candown:=False;
      If Board[Player,x+Tet[6],y+Tet[7]+1]>0 Then candown:=False;
    End;
  Begin
    y:=1; t:=0;
    For N2:=0 To 7 Do
      Tet[N2]:=Change[Kind,Trans,N2];
    While candown do inc(y);
    For i:=0 to 3 do Begin
      if Board[Player,x+Tet[i*2]-1,y+Tet[i*2+1]]>0 Then t:=t+score[kind,trans,i*3];
      if Board[Player,x+Tet[i*2]+1,y+Tet[i*2+1]]>0 Then t:=t+score[kind,trans,i*3+1];
      if Board[Player,x+Tet[i*2],y+Tet[i*2+1]+1]>0 Then t:=t+score[kind,trans,i*3+2];
    End;
    t:=t+y*2;
    AI_Try:=t;
  End;

Procedure AI(Player:byte);
  var
    maxscore,nowscore:word;
    maxx,maxt:byte;
    t,i,i1,i2:shortint;
    tNow:array[0..7]of byte;
  begin
    maxscore:=0;
    For i:=0 to 7 do
      tNow[i]:=Now[Player,i];
    for t:=0 to 3 do begin
      i1:=4;i2:=4;
      For i:=0 To 7 Do
        Now[Player,i]:=Change[Kind[Player],t,i];
      while canmove(Player,i1-1,2) and (i1>0)do dec(i1);
      while canmove(Player,i2+1,2) and (i2<11)do inc(i2);
      for i:=i1 to i2 do begin
        nowscore:=AI_Try(Player,kind[Player],t,i);
        if (nowscore>maxscore)or((nowscore=maxscore)and(Random>=0.5)) then begin
          maxscore:=nowscore;
          maxx:=i;
          maxt:=t;
        end;
      end;
    end;
    For i:=0 to 7 do
      Now[Player,i]:=tNow[i];
    AIx[Player]:=maxx;
    AItrans[Player]:=maxt;
  end;

Procedure TetriOK(N:byte);
  Var
    N2:Byte;
  Begin
   Board[N,Nowx[N]+Now[N,0],Nowy[N]+Now[N,1]]:=Kind[N]+1;
   Board[N,Nowx[N]+Now[N,2],Nowy[N]+Now[N,3]]:=Kind[N]+1;
   Board[N,Nowx[N]+Now[N,4],Nowy[N]+Now[N,5]]:=Kind[N]+1;
   Board[N,Nowx[N]+Now[N,6],Nowy[N]+Now[N,7]]:=Kind[N]+1;
   Clear(N);
   Kind[N]:=NKind[N];      Trans[N]:=NTrans[N];
   Now[N]:=Next[N];
   Point[N]:=Point[N]+1;
   NoItem[N]:=30;
   if TKind[Point[N]]=0 then begin
     if debug then NKind[N]:=0 else NKind[N]:=Random(7);
     NTrans[N]:=Random(4);
     TKind[Point[N]]:=NKind[N]+1;
     TTrans[Point[N]]:=NTrans[N];
   end else begin
     NKind[N]:=TKind[Point[N]]-1;NTrans[N]:=TTrans[Point[N]];
     TKind[Point[N]-1]:=0;
   end;
   Nowx[N]:=4;Nowy[N]:=1;
   For N2:=0 To 7 Do
    Next[N,N2]:=Change[NKind[N],NTrans[N],N2];
   ShowNext(N,NKind[N]+1);
   AIOK[N]:=False; ItemOK[N]:=False;
  end;

Procedure Frame(Player:byte);
  procedure Help(Player:byte);
    var
      n3,n4,nt,nx,mx:byte;
      nn:array [0..7]of byte;
    Begin
      nt:=trans[Player];
      nx:=Nowx[Player];
      for n3:=0 to 7 do nn[n3]:=Now[Player,n3];
      mx:=mousex;
      AI(Player);
      for n4:=1 to 40 do begin
        for n3:=1 to 4 do if trans[Player]<>AItrans[Player] then TurnTetri(Player);
        if trans[Player]<>AItrans[Player] then
          begin trans[Player]:=nt;Nowx[Player]:=nx;AI(Player); end;
      end;
      Show(Player,0);
      if trans[Player]<>AItrans[Player] then
        begin trans[Player]:=nt;Nowx[Player]:=nx;
              Show(Player,kind[Player]+1);
              Msg('帮助失败！','',2000,11);
              Exit end;
      While (Nowx[Player]>AIx[Player])and canmove(Player,Nowx[Player],Nowy[Player]) do
        begin Dec(Nowx[Player]);
              {if Com[abs(Player-1)]or(Player=1)then setmouse(mousex-64,mousey);mousex:=mousex-64;}end;
      While (Nowx[Player]<AIx[Player])and canmove(Player,Nowx[Player],Nowy[Player]) do
        begin inc(Nowx[Player]);
              {if Com[abs(Player-1)]or(Player=1)then setmouse(mousex+64,mousey);mousex:=mousex+64;}end;
      if not canmove(Player,Nowx[Player],Nowy[Player]) then
        begin Nowx[Player]:=nx;
              trans[Player]:=nt;
              for n3:=0 to 7 do Now[Player,n3]:=nn[n3];
              {if Com[abs(Player-1)]or(Player=1)then begin
                mousex:=mx;
                setmouse(mousex,mousey);
              end;}
              Msg('帮助失败！','',2000,11); end;
      if Com[abs(Player-1)]or(Player=1)then setmouse(Nowx[Player]*64+32,mousey);
      Show(Player,kind[Player]+1)
    End;
  begin
   If ExitGame Then Exit;
   if (Not(Canmove(Player,Nowx[Player],Nowy[Player]+1)))and(Waste[Player]>=(10-Speed[Player])*50)
     and(NoItem[Player]>=40)then exit;
   if (Waste[Player]>=(10-Speed[Player])*50)and(Canmove(Player,Nowx[Player],Nowy[Player]+1)) then begin
     NoFlashShow(Player,Nowx[Player],Nowy[Player]+1,Kind[Player]+1);
     Waste[Player]:=Waste[Player]-(10-Speed[Player])*50-1;
   end;{if}
   If (Com[Player]=False)and(Com[abs(Player-1)]) then begin

     Case PressKey Of

           1:If Canmove(Player,Nowx[Player]-1,Nowy[Player]) Then Begin
                 NoFlashShow(Player,Nowx[Player]-1,Nowy[Player],Kind[Player]+1);
                 if b and Com[abs(Player-1)] then setmouse(Nowx[Player]*64+32,mousey);
               End;
           2:If Canmove(Player,Nowx[Player]+1,Nowy[Player]) Then Begin
                 NoFlashShow(Player,Nowx[Player]+1,Nowy[Player],Kind[Player]+1);
                 if b and Com[abs(Player-1)] then setmouse(Nowx[Player]*64+32,mousey);
               End;
           3,12:Waste[Player]:=Waste[Player]+((10-Speed[Player])*50)*3;
           5,14:TurnTetri(Player);

       102:begin ExitGame:=True; Exit; end;
       4,13:FastDown(Player);
       101:Begin
             Msg('已暂停','按任意键继续',1,10);
             Readkey;
           End;
       6,15:If (NoItem[Player] in [1..30]) then begin UseItem(Player,0); Dec(NoItem[Player]) end;
       7,16:If (NoItem[Player] in [1..30]) then begin UseItem(Player,1); Dec(NoItem[Player]) end;
       8,17:ChangeItem(Player);
       9,18:Help(Player);
     End;

     {Mouse Setting}
     if b then begin
     if ((mousex div 64)<Nowx[Player])and canmove(Player,Nowx[Player]-1,Nowy[Player]) then
       begin
         NoFlashShow(Player,Nowx[Player]-1,Nowy[Player],Kind[Player]+1);
       end
     else
     if ((mousex div 64)>Nowx[Player])and canmove(Player,Nowx[Player]+1,Nowy[Player]) then
       begin
         NoFlashShow(Player,Nowx[Player]+1,Nowy[Player],Kind[Player]+1);
       end;
     if mousekey=Keyset[12]-1000 then Waste[Player]:=Waste[Player]+((10-Speed[Player])*50 div 50);
   { UpMouse(LeftKey,mousekey,c,mousex,mousey);
     if c>0 then TurnTetri(Player);
     UpMouse(RightKey,mousekey,c,mousex,mousey);
     if c>0 then FastDown(Player); }
     getmouse(mousekey,mousex,mousey);
     end;{if b}
     end;{if Player}

     If Com[Player] then begin
     {AI}
     if (Item[Player,0]>0)and(not ItemOK[Player]) then AIUseItem(Player) else
       if not ItemOK[Player] then AIItem[Player]:=0;
     if not ItemOK[Player] then ItemOK[Player]:=True;
     if not AIOK[Player] then begin AI(Player);AIOK[Player]:=True;end;
     if AIWaste[Player]>=AISpeed[Player] Then begin
       if (NoItem[Player] in [1..30])and Itemfirst[Player] and(AIItem[Player]<>0)and(AIItem[Player]<>Item[Player,0]) then
         Begin ChangeItem(Player);end else
       if (NoItem[Player] in [1..30])and Itemfirst[Player] and(AIItem[Player]<>0)and(AIItem[Player]=Item[Player,0]) then
         Begin UseItem(Player,AIUser[Player]);AIItem[Player]:=0; end else
       if trans[Player]<>AItrans[Player] then TurnTetri(Player) else
       if (Nowx[Player]>AIx[Player])and canmove(Player,Nowx[Player]-1,Nowy[Player]) Then
         Begin NoFlashShow(Player,Nowx[Player]-1,Nowy[Player],Kind[Player]+1);end else
       if (Nowx[Player]<AIx[Player])and canmove(Player,Nowx[Player]+1,Nowy[Player]) Then
         Begin NoFlashShow(Player,Nowx[Player]+1,Nowy[Player],Kind[Player]+1);end else
       if (NoItem[Player] in [1..30])and(AIItem[Player]>0)and(AIItem[Player]<>Item[Player,0]) then
         Begin ChangeItem(Player);end else
       if (NoItem[Player] in [1..30])and(AIItem[Player]>0)and(AIItem[Player]=Item[Player,0]) then
         Begin AIItem[Player]:=0;UseItem(Player,AIUser[Player]);AIItem[Player]:=0;ItemOK[Player]:=true end else
       FastDown(Player);
       AIWaste[Player]:=0;
     end;
     inc(AIWaste[Player]);
     end;{If Player}

    If (Com[0]=False)and(Com[1]=False) then begin

     Case PressKey Of
           1:If Canmove(0,Nowx[0]-1,Nowy[0]) Then Begin
                 NoFlashShow(0,Nowx[0]-1,Nowy[0],Kind[0]+1);
                 if b and Com[abs(0-1)] then setmouse(Nowx[0]*64+32,mousey);
               End;
           2:If Canmove(0,Nowx[0]+1,Nowy[0]) Then Begin
                 NoFlashShow(0,Nowx[0]+1,Nowy[0],Kind[0]+1);
                 if b and Com[abs(0-1)] then setmouse(Nowx[0]*64+32,mousey);
               End;
           3:Waste[0]:=Waste[0]+((10-Speed[0])*50)*3;
           5:TurnTetri(0);
       102:begin ExitGame:=True; Exit; end;
       4:FastDown(0);
       101:Begin
             Msg('已暂停','按任意键继续',1,10);
             Readkey;
           End;
       6:If (NoItem[0] in [1..30]) then begin UseItem(0,0); Dec(NoItem[0]) end;
       7:If (NoItem[0] in [1..30]) then begin UseItem(0,1); Dec(NoItem[0]) end;
       8:ChangeItem(0);
       9:Help(0);
       12:Waste[1]:=Waste[1]+((10-Speed[1])*50)*3;
       13:FastDown(1);
       14:TurnTetri(1);
       15:If (NoItem[1] in [1..30]) then begin UseItem(1,0); Dec(NoItem[1]) end;
       16:If (NoItem[1] in [1..30]) then begin UseItem(1,1); Dec(NoItem[1]) end;
       17:ChangeItem(1);
       18:Help(1);
     End;

     {Mouse Setting}
     if b then begin
     if ((mousex div 64)<Nowx[1])and canmove(1,Nowx[1]-1,Nowy[1]) then
       begin
         NoFlashShow(1,Nowx[1]-1,Nowy[1],Kind[1]+1);
       end
     else
     if ((mousex div 64)>Nowx[1])and canmove(1,Nowx[1]+1,Nowy[1]) then
       begin
         NoFlashShow(1,Nowx[1]+1,Nowy[1],Kind[1]+1);
       end;
     if mousekey=Keyset[12]-1000 then Waste[1]:=Waste[1]+((10-Speed[1])*50 div 50);
 {   UpMouse(LeftKey,mousekey,c,mousex,mousey);
     if c>0 then TurnTetri(1);
     UpMouse(RightKey,mousekey,c,mousex,mousey);
     if c>0 then FastDown(1);  }
     getmouse(mousekey,mousex,mousey);
     end;{if b}
    End;{if Com False}

    If Com[0] and Com[1] then
      If Keypressed Then
       Case Upcase(Readkey) Of
         #27:begin ExitGame:=True; Exit; end;
         #13:Begin
               Msg('已暂停','按任意键继续',1,10);
               Readkey;
             End;
         '+','=':If AISpeed[1]>0 then AISpeed[1]:=AISpeed[1]-20;
         '-':If AISpeed[1]<200 then AISpeed[1]:=AISpeed[1]+20;
         ']':If AISpeed[0]>0 then AISpeed[0]:=AISpeed[0]-20;
         '[':If AISpeed[0]<200 then AISpeed[0]:=AISpeed[0]+20;
         #32:Begin AISpeed[0]:=100; AISpeed[1]:=100 End;
       End;

     if MsgWaste=1 then NoMsg;
     if MsgWaste>0 then dec(MsgWaste);
     if (CheckFace(Player)<>NowFaceP[Player])and(AllowTime[Player]<=1) then
       ChangeFace(Player,CheckFace(Player),0);
     PlayFace(Player);
     if (Not(Canmove(Player,Nowx[Player],Nowy[Player]+1)))and(Waste[Player]>=(10-Speed[Player])*50)
       and(NoItem[Player]>=40)then exit;
     if (Not(Canmove(Player,Nowx[Player],Nowy[Player]+1)))and(Waste[Player]>=(10-Speed[Player])*50)then TetriOK(Player);
  end;

Procedure Init_Graph;   {Init the Graph Mode}
  var
    grDriver: Integer;
    grMode: Integer;
    ErrCode: Integer;
  Begin
    Clrscr;
    Writeln('Tetris Version '+TetVer);
    Writeln;
    Writeln('Produce by: Ben');
    {Writeln('Zhaoqing Middle School, Guangdong, China');}
    Writeln('(C)Copyright Ben Studio. Aug.2005');
    Writeln;
    Writeln;
    grDriver := Detect;
    InitGraph(grDriver, grMode,'SETTING');
    ErrCode := GraphResult;
    if ErrCode <> grOk then begin
       grDriver := Detect;
       InitGraph(grDriver, grMode,' ');
       ErrCode := GraphResult;
    End;
    if ErrCode <> grOk then Begin
      Writeln('Graphics error:', GraphErrorMsg(ErrCode));
      Halt(1);
    End;
    if ErrCode = grOk then Delay(2000);
  End;

Procedure Init_Mouse; {Init Mouse}
  VAR
    ct:char;
  begin
    initmouse(b,t);
    if b then begin
      HideMouse;
      setmouse(getmaxx div 2,getmaxy div 2);
      getmouse(mousekey,mousex,mousey);
    end {if b} else begin
      RestoreCrtMode;
      Writeln('Mouse Error: Cannot Init Mouse.');
      Writeln('If you don''t install the mouse, you will ');
      Writeln('not be able to play the game successfully.');
      Write('Do you want to continue?(Y/N)');
      ct:=Upcase(Readkey);
      while not (ct in ['Y','N']) do ct:=Upcase(Readkey);
      Writeln;
      Writeln;
      Writeln;
      if ct='Y' then SetGraphMode(GetGraphMode)
      else Begin CloseGraph; Halt(1); End;
    end;{else b}
  end;

procedure Loading(Persent:byte;Page1,Page2:byte);
  var
    i:integer;
  begin
    SetActivePage(Page1);
    SetColor(15);
    Rectangle(268,240,371,257);
    SetColor(10);
    for i:=270 to 270+Persent do
      line(i,242,i,256);
    if Page1<>Page2 then
      SetActivePage(Page2);
  end;

procedure Init_Pic; {BitMap Init}
  var
    i,j:integer;
    x,y:word;
    f:text;
  begin
    cleardevice;
    SetVisualPage(0);
    SetActivePage(0);
    SetTextStyle(DefaultFont, HorizDir, 3);
    Setcolor(10);
    outtextxy(100,200,'Loading...');
    Loading(0,0,1);
    Bright(5);
    for i:=100 to 112 do ItemP[i]:=nil;
    for y:=1 to 12 do begin
      assign(f,'IMAGE\'+inttostr(y)+'.poi');
      reset(f);
      for i:=101 to 119 do begin
        for j:=101 to 119 do begin
          read(f,x);
          putpixel(i,j,x);
        end;
      end;
      getmem(itemp[y+100],imagesize(101,101,119,119));
      getimage(101,101,119,119,itemp[y+100]^);
      close(f);
    end;
    for y:=0 to 8 do begin
      assign(f,'IMAGE\'+inttostr(y)+'t.poi');
      reset(f);
      for i:=101 to 119 do begin
        for j:=101 to 119 do begin
          read(f,x);
          putpixel(i,j,x);
        end;
      end;
      getmem(tetp[y],imagesize(101,101,119,119));
      getimage(101,101,119,119,tetp[y]^);
      close(f);
      Loading(5*y+1,0,1);
    end;
    cleardevice;
    SetVisualPage(0);
    SetActivePage(0);
  end;

Procedure Init_Face;
  var
    i:byte;
    x,y,z:integer;
    tem:word;
    f:text;
    nowf:face;
  begin
    SetVisualPage(0);
    SetActivePage(0);
    SetTextStyle(DefaultFont, HorizDir, 3);
    Setcolor(10);
    outtextxy(100,200,'Loading...');
    Loading(0,0,1);
    for i:=1 to 7 do begin
      assign(f,'FACE\'+inttostr(i)+'.POI');
      reset(f);
      new(FaceP[i]);
      readln(f,FaceP[i]^.time);
      for x:=100 to 197 do begin
        for y:=100 to 197 do begin
          read(f,z);
          putpixel(x,y,z);
        end;
      end;
      GetMem(FaceP[i]^.bitmap,Imagesize(100,100,197,197));
      GetImage(100,100,197,197,FaceP[i]^.bitmap^);
      nowf:=FaceP[i];
      readln(f,tem);
      while tem<>0 do begin
        new(nowf^.next);
        nowf:=nowf^.next;
        with nowf^ do begin
          time:=tem;
          for x:=100 to 197 do begin
            for y:=100 to 197 do begin
              read(f,z);
              putpixel(x,y,z);
            end;
          end;
          GetMem(bitmap,Imagesize(100,100,197,197));
          GetImage(100,100,197,197,bitmap^);
        end;
        readln(f,tem);
      end;
      nowf^.next:=FaceP[i];
      close(f);
      Loading(42+8*i,0,1);
    end;
    faceX[0]:=213;             faceY[0]:=340;
    faceX[1]:=330;             faceY[1]:=340;
    CountTime[0]:=0;           AllowTime[0]:=0;
    CountTime[1]:=0;           AllowTime[1]:=0;
    NowFace[0]:=FaceP[1];      NowFace[1]:=FaceP[1];
    NowFaceP[0]:=1;            NowFaceP[1]:=1;
    ClearDevice;
    SetVisualPage(0);
    SetActivePage(0);
    darkout(5);
    ClearDevice;
  end;

Procedure Init_Var; {Var Init}
  Begin
    Fillchar(Board,Sizeof(Board),0);
    Fillchar(Item,Sizeof(Item),0);
    Randomize;
    Waste[0]:=(10-Speed[0])*50;
    Waste[1]:=(10-Speed[1])*50;
    NoItem[0]:=20;
    NoItem[1]:=20;
    Combo[0]:=0;
    Combo[1]:=0;
    ExitGame:=False;
  End;

Procedure Init_Main;
  Begin
    {SetTextStyle(DefaultFont, HorizDir, 3);
    Delay(1000);
    setcolor(8);
    Rectangle(7,3,203,464);
    Rectangle(GetMaxX-203,3,GetMaxX-7,464);
    line(GetMaxX div 2,0,GetMaxX div 2,464);
    Rectangle(212,238,311,285);
    Rectangle(329,238,428,285);
    SetTextStyle(DefaultFont, HorizDir, 1);
    setcolor(2);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2,GetMaxY-TextHeight('P')-5,'Produce by: ');
    setcolor(10);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2+TextWidth('Produce by: '),GetMaxY-TextHeight('P')-5,'Ben');
    SetTextStyle(DefaultFont, HorizDir, 3);
    Delay(200);
    setcolor(7);
    Rectangle(7,3,203,464);
    Rectangle(GetMaxX-203,3,GetMaxX-7,464);
    line(GetMaxX div 2,0,GetMaxX div 2,464);
    Rectangle(212,238,311,285);
    Rectangle(329,238,428,285);
    SetTextStyle(DefaultFont, HorizDir, 1);
    setcolor(2);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2,GetMaxY-TextHeight('P')-5,'Produce by: ');
    setcolor(10);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2+TextWidth('Produce by: '),GetMaxY-TextHeight('P')-5,'Ben');}
    SetTextStyle(DefaultFont, HorizDir, 3);
    Delay(200);
    setcolor(15);
    Rectangle(7,3,203,464);
    Rectangle(GetMaxX-203,3,GetMaxX-7,464);
    line(GetMaxX div 2,0,GetMaxX div 2,464);
    Rectangle(212,238,311,285);
    Rectangle(329,238,428,285);
    SetTextStyle(DefaultFont, HorizDir, 1);
    setcolor(2);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2,GetMaxY-TextHeight('P')-5,'Produce by: ');
    setcolor(10);
    outtextxy((GetMaxX-TextWidth('Produce by: Ben'))div 2+TextWidth('Produce by: '),GetMaxY-TextHeight('P')-5,'Ben');
    SetTextStyle(DefaultFont, HorizDir, 3);
    PutImage(facex[0],faceY[0],NowFace[0]^.bitmap^,NormalPut);
    PutImage(facex[1],faceY[1],NowFace[1]^.bitmap^,NormalPut);
    Bright(50);
  End;

Procedure Init_TetrisBoard;
  Var
    N:Byte;
  Begin
    For N:=1 To 24 Do
      Board[0,0,N]:=1;
    For N:=1 To 24 Do
      Board[0,11,N]:=1;
    For N:=1 To 10 Do
      Board[0,N,25]:=1;
    For N:=1 To 24 Do
      Board[1,0,N]:=1;
    For N:=1 To 24 Do
      Board[1,11,N]:=1;
    For N:=1 To 10 Do
      Board[1,N,25]:=1;
    if debug then Kind[0]:=0 else Kind[0]:=Random(7);
    Trans[0]:=Random(4);
    if debug then NKind[0]:=0 else NKind[0]:=Random(7);
    NTrans[0]:=Random(4);
    if debug then Kind[1]:=0 else Kind[1]:=Kind[0];
    Trans[1]:=Trans[0];
    if debug then NKind[1]:=0 else NKind[1]:=NKind[0];
    NTrans[1]:=NTrans[0];
    TKind[2]:=NKind[0]+1; TTrans[2]:=NTrans[0];
    Point[0]:=2;          Point[1]:=2;
    Nowx[0]:=4;           Nowy[0]:=1;
    Nowx[1]:=4;           Nowy[1]:=1;
    For N:=0 To 7 Do
      Now[0,N]:=Change[Kind[0],Trans[0],N];
    For N:=0 To 7 Do
      Next[0,N]:=Change[NKind[0],NTrans[0],N];
    For N:=0 To 7 Do
      Now[1,N]:=Change[Kind[1],Trans[1],N];
    For N:=0 To 7 Do
      Next[1,N]:=Change[NKind[1],NTrans[1],N];
  End;

Procedure Count_3_2_1_GO;
  Begin
    Delay(500);
    SetTextStyle(DefaultFont, HorizDir, 5);
    Setcolor(10);
    outtextxy(105-TextWidth('3')div 2,100,'3');
    outtextxy(GetMaxX-105-TextWidth('3')div 2,100,'3');
    Delay(999);
    Setcolor(0);
    outtextxy(105-TextWidth('3')div 2,100,'3');
    outtextxy(GetMaxX-105-TextWidth('3')div 2,100,'3');
    Setcolor(10);
    outtextxy(105-TextWidth('2')div 2,100,'2');
    outtextxy(GetMaxX-105-TextWidth('2')div 2,100,'2');
    Delay(999);
    Setcolor(0);
    outtextxy(105-TextWidth('2')div 2,100,'2');
    outtextxy(GetMaxX-105-TextWidth('2')div 2,100,'2');
    Setcolor(10);
    outtextxy(105-TextWidth('1')div 2,100,'1');
    outtextxy(GetMaxX-105-TextWidth('1')div 2,100,'1');
    Delay(999);
    Setcolor(0);
    outtextxy(105-TextWidth('1')div 2,100,'1');
    outtextxy(GetMaxX-105-TextWidth('1')div 2,100,'1');
    Setcolor(10);
    outtextxy(105-TextWidth('GO!')div 2,100,'GO!');
    outtextxy(GetMaxX-105-TextWidth('GO!')div 2,100,'GO!');
    Delay(300);
    While KeyPressed do Readkey;
  End;

Procedure Main;
  Begin
    Furbish(0);
    Furbish(1);
    ShowNext(0,NKind[0]+1);
    ShowNext(1,NKind[1]+1);
    ShowItem(0);
    ShowItem(1);
    While Canmove(0,Nowx[0],Nowy[0]) and Canmove(1,Nowx[1],Nowy[1]) Do
      Begin
         Frame(0);
         Frame(1);
         If ExitGame Then Exit;
         Delay(1);
         inc(Waste[0]);
         inc(Waste[1]);
      End;{While}
  End;

Procedure Finish;
  Var
    N,N2,N3:Byte;
  Begin
    If ExitGame Then Begin
      Darkout(20);
      Exit;
    End;
    SetTextStyle(DefaultFont, HorizDir, 3);
    if not Canmove(0,Nowx[0],Nowy[0]) then N:=0;
    if not Canmove(1,Nowx[1],Nowy[1]) then N:=1;
    for N2:=0 to 11 do
      for N3:=1 to 25 do
        if Board[N,N2,N3]<>0 then Board[N,N2,N3]:=8;
    Furbish(N);
    Show(N,8);
    SetColor(0);
    for N:=185 to 210+TextHeight('I') do
      line(45,N,GetMaxX div 2-45,N);
    for N:=185 to 210+TextHeight('I') do
      line(GetMaxX div 2+45,N,GetMaxX-45,N);
    SetColor(10);
    Rectangle(50,190,GetMaxX div 2-50,205+TextHeight('I'));
    Rectangle(45,185,GetMaxX div 2-45,210+TextHeight('I'));
    Rectangle(GetMaxX div 2+50,190,GetMaxX-50,205+TextHeight('I'));
    Rectangle(GetMaxX div 2+45,185,GetMaxX-45,210+TextHeight('I'));
    Setcolor(7);
    if not Canmove(0,Nowx[0],Nowy[0]) then N:=0;
    if not Canmove(1,Nowx[1],Nowy[1]) then N:=1;
    if N=0 then
      OutTextXY((GetMaxX div 2-TextWidth('LOSER'))div 2,200,'LOSER')
    else OutTextXY((GetMaxX div 2-TextWidth('WINNER'))div 2,200,'WINNER');
    if N=1 then
      OutTextXY((GetMaxX div 2-TextWidth('LOSER'))div 2+GetMaxX div 2,200,'LOSER')
    else OutTextXY((GetMaxX div 2-TextWidth('WINNER'))div 2+GetMaxX div 2,200,'WINNER');

    While keypressed do readkey;
    ChangeFace(N,6,0);
    ChangeFace(abs(N-1),5,0);
    Repeat
    Repeat
      PlayFace(0);
      PlayFace(1);
      Delay(1);
    Until KeyPressed;
    Until Readkey in [#32,#13,#27];
    Darkout(20);
  End;

Function KeyName(Key:integer):string;
  var
    s:string;
    list:text;
    i:integer;
  begin
    assign(list,'setting\keyname.lst');
    reset(list);
    for i:=1 to key do readln(list,s);
    close(list);
    delete(s,1,4);
    KeyName:=s;
  end;

Procedure Init_Start;
  const
    r=10;
  var
    Title1,Title2,tp:Pointer;
    i,j,maxi1,maxi2,maxj1,maxj2,col:integer;
    b:boolean;
    t:text;
  begin
    setcolor(15);
    for i:=1 to r do begin
      if i=r-2 then setcolor(8)
        else if i=r-4 then setcolor(7);
      circle(100,100,i);
    end;
    getmem(p, imagesize(100-r,100-r,100+r,100+r));
    getimage(100-r,100-r,100+r,100+r,p^);
    ClearDevice;
    SetVisualPage(0);
    SetActivePage(0);
    SetTextStyle(DefaultFont, HorizDir, 3);
    Setcolor(10);
    outtextxy(100,200,'Loading...');
    Loading(0,0,1);
    Bright(5);
    {Draw Title 2}
    assign(t,'face\2title.poi');
    reset(t);
    readln(t,maxi2,maxj2);
    for i:=1 to maxi2 do
      for j:=1 to maxj2 do begin
        read(t,col);
        putpixel(i+330,j+270-maxj2 div 2,col);
        If i mod (maxi2 div 10)=0 then Loading(round(50/maxi2*i),0,1);
      end;
    close(t);
    {Draw Title 1}
    assign(t,'face\1title.poi');
    reset(t);
    readln(t,maxi1,maxj1);
    for i:=1 to maxi1 do
      for j:=1 to maxj1 do begin
        read(t,col);
        putpixel(i+310-maxi1,j+240-maxj1 div 2,col);
        If i mod (maxi1 div 10)=0 then Loading(round(50+50/maxi1*i),0,1);
      end;
    close(t);

    Getmem(Title1,imagesize(0,240-maxj1 div 2,320,240+maxj1 div 2));
    Getmem(tp,imagesize(0,240-maxj1 div 2,320,240+maxj1 div 2));
    Getmem(Title2,imagesize(330,270-maxj2 div 2,630,270+maxj2 div 2));
    Getimage(310-maxi1,240-maxj1 div 2,320,240+maxj1 div 2,tp^);
    Getimage(330,270-maxj2 div 2,630,270+maxj2 div 2,Title2^);
    SetActivePage(0);
    ClearDevice;
    Delay(500);
    for i:=1 to 10 do begin
      SetActivePage(1);
      Putimage(310-maxi1,240-maxj1 div 2,tp^,NormalPut);
      Getimage(310-i*31,240-maxj1 div 2,310,240+maxj1 div 2,Title1^);
      SetActivePage(0);
      Putimage(0,240-maxj1 div 2,Title1^,NormalPut);
      Putimage(640-i*32,270-maxj1 div 2,Title2^,NormalPut);
      Delay(1);
    end;
    Freemem(Title1,imagesize(0,220,310,252));
    Freemem(Title2,imagesize(320,228,630,252));
    Freemem(tp,imagesize(0,240-maxj1 div 2,320,240+maxj1 div 2));
    for i:=1 to 3 do begin
      Setbkcolor(15);
      Delay(100);
      Setbkcolor(0);
      Delay(100);
    end;
    Getmem(Title1,imagesize(0,240-maxj1 div 2,630,240+maxj1 div 2));
    Getimage(0,240-maxj1 div 2,630,240+maxj1 div 2,Title1^);
    for i:=240-maxj1 div 2 downto 70 do
      if ((i-70)mod 5)=(70 mod 5) then
        Putimage(0,i,Title1^,NormalPut);
    Freemem(Title1,imagesize(0,220,630,256));
    SetTextStyle(DefaultFont, HorizDir, 2);
    SetTextJustify(CenterText,CenterText);
    Moveto(320,240);
    While KeyPressed do Readkey;
    b:=False;
    Repeat
      Setcolor(10);
      Outtext('- Press any key -');
      for i:=1 to 300 do begin
        if not b then Delay(1) else break;
        if keypressed then b:=true;
      end;
      Setcolor(0);
      Outtext('- Press any key -');
      for i:=1 to 300 do begin
        if not b then Delay(1) else break;
        if keypressed then b:=true;
      end;
    Until b;
    SetTextJustify(LeftText,TopText);
    Readkey;
  end;
Procedure Load_var;
  var
    t:text;
    i:byte;
  begin
    assign(t,'setting\config.cfg');
    reset(t);
    readln(t,i);
    if i=0 then Com[0]:=false else Com[0]:=true;
    readln(t,i);
    if i=0 then Com[1]:=false else Com[1]:=true;
    readln(t,i);
    if i=0 then ItemAllow:=false else ItemAllow:=true;
    readln(t,AISpeed[0]);
    readln(t,AISpeed[1]);
    readln(t,Speed[0]);
    Speed[1]:=Speed[0];
    close(t);
    assign(t,'setting\control.cfg');
    reset(t);
    for i:=1 to 18 do readln(t,keyset[i]);
    close(t);
  end;
Procedure Save_var;
  var
    t:text;
    i:byte;
  begin
    assign(t,'setting\config.cfg');
    rewrite(t);
    writeln(t,ord(Com[0]));
    writeln(t,ord(Com[1]));
    writeln(t,ord(ItemAllow));
    writeln(t,AISpeed[0]);
    writeln(t,AISpeed[1]);
    writeln(t,Speed[0]);
    close(t);
    assign(t,'setting\control.cfg');
    rewrite(t);
    for i:=1 to 18 do writeln(t,keyset[i]);
    close(t);
  end;
Procedure Controller;
  const
    lab:array[1..8]of string[16]=('左移','右移','快速下落','直接下落',
                                  '旋转','对玩家一使用道具','对玩家二使用道具','切换道具顺序');
    lab2:array[6..7]of string[16]=('恢复为默认值','返回');
    lab3:array[0..1]of string[6]=('玩家一','玩家二');
    lab5:array[0..1]of string[10]=('下一页','上一页');
    x1=100; y1=240;
    x2=320; x3=200; y2=y1+8;
    xl=x2-24;
  var
    player:shortint;
    sel:byte;
    page:shortint;
    ch:char;
    i:integer;
  procedure F_Key(player,sel:byte);
    var
      s:string;
      c:byte;
    begin
      bar(x2-56+player*x3,y2+sel*25-8,x2+56+player*x3,y2+sel*25+8);
      if (page=0)and(player=1)and(sel<=2) then begin
        c:=getcolor;
        setcolor(4);
        outchinese(x2+x3-32,y1+25*sel,'使用鼠标',0);
        setcolor(c);
      end else
      case keyset[sel+page*4+player*9] of
        1001:outchinese(x2-32+player*x3,y2+sel*25-8,'鼠标左键',0);
        1002:outchinese(x2-32+player*x3,y2+sel*25-8,'鼠标右键',0);
        1004:outchinese(x2-32+player*x3,y2+sel*25-8,'鼠标中键',0);
      else begin
        s:=KeyName(keyset[sel+page*4+player*9]);
        outtextxy(x2+player*x3,y2+sel*25,s);
      end
      end;
    end;
  procedure ReFresh;
    var
      i:integer;
    begin
      bar(0,237,639,240+25*6);
      setcolor(7);
      for i:=1 to 4 do
        outchinese(x1,y1+i*25,lab[i+page*4],0);
      outchinese(x1,y1+5*25,lab5[page],0);
      setcolor(6);
      for i:=0 to 1 do
        outchinese(xl+i*x3,y1,lab3[i],0);
      setcolor(2);
      for i:=1 to 4 do
        F_Key(0,i);
      for i:=1 to 4 do
        F_Key(1,i);
    end;
  procedure default;
    begin
      keyset[1]:=330;
      keyset[2]:=332;
      keyset[3]:=335;
      keyset[4]:=32;
      keyset[5]:=327;
      keyset[6]:=90;
      keyset[7]:=88;
      keyset[8]:=67;
      keyset[12]:=48;
      keyset[13]:=1002;
      keyset[14]:=1001;
      keyset[15]:=42;
      keyset[16]:=45;
      keyset[17]:=43;
      refresh;
    end;
  begin
    player:=0;
    sel:=1;
    page:=0;
    settextjustify(CenterText,CenterText);
    settextstyle(0,0,1);
    setfillstyle(1,0);
    bar(0,237,639,400);
    ReFresh;
    setcolor(7);
    for i:=6 to 7 do
      outchinese(x1,y1+i*25,lab2[i],0);
    repeat
      putimage(x1-30,y1+sel*25-2,p^,NormalPut);
      setcolor(15);
      if sel<5 then outchinese(x1,y1+sel*25,lab[sel+page*4],0)
            else if sel=5 then outchinese(x1,y1+sel*25,lab5[page],0) else
              outchinese(x1,y1+sel*25,lab2[sel],0);
      setcolor(11);
      if sel<5 then rectangle(x2-80+player*x3,y2+sel*25-12,x2+80+player*x3,y2+sel*25+12);
      setcolor(10);
      if sel<5 then F_key(player,sel);
      setcolor(14);
      outchinese(xl+player*x3,y1,lab3[player],0);
      ch:=Upcase(readkey);
        if (ch in [#72,#80]) then begin
          putimage(x1-30,y1+sel*25-2,p^,XORPut);
          setcolor(7);
          if sel<5 then outchinese(x1,y1+sel*25,lab[sel+page*4],0)
            else if sel=5 then outchinese(x1,y1+sel*25,lab5[page],0) else
              outchinese(x1,y1+sel*25,lab2[sel],0);
          setcolor(0);
          if sel<5 then rectangle(x2-80+player*x3,y2+sel*25-12,x2+80+player*x3,y2+sel*25+12);
          setcolor(2);
          if sel<5 then F_key(player,sel);
        end;
        if (ch in [#75,#77])and(sel<5)then begin
          setcolor(2);
          F_key(player,sel);
          setcolor(6);
          outchinese(xl+player*x3,y1,lab3[player],0);
          setcolor(0);
          rectangle(x2-80+player*x3,y2+sel*25-12,x2+80+player*x3,y2+sel*25+12);
        end;
        case ch of
          #80:if sel<7 then inc(sel) else sel:=1;
          #72:if sel>1 then dec(sel) else sel:=7;
          #75,#77:if sel<5 then player:=abs(player-1);
          #13,#32:if sel=6 then default else
                  if sel=5 then begin
                    page:=abs(page-1); refresh;
                  end else
                  if (sel<5)and(not((page=0)and(player=1)and(sel<=2))) then begin
                    setcolor(12);
                    bar(x2-79+player*x3,y2+sel*25-11,x2+79+player*x3,y2+sel*25+11);
                    outtextxy(x2+player*x3,y2+sel*25,'Press a key');
                    setcolor(10);
                    i:=0;
                    while i=0 do begin
                      if keypressed then i:=Read_Key else begin
                      UpMouse(LeftKey,mousekey,c,mousex,mousey);
                      if c>0 then i:=1001;
                      UpMouse(RightKey,mousekey,c,mousex,mousey);
                      if c>0 then i:=1002;
                      if t>2 then begin
                        UpMouse(MidKey,mousekey,c,mousex,mousey);
                        if c>0 then i:=1004;
                      end;
                      end;
                    end;
                    if not (i in [13,27])then
                      keyset[sel+page*4+player*9]:=i;
                    F_Key(player,sel);
                  end;
        end;
    until ((ch in [#13,#32])and(sel=7))or(ch=#27);
    settextjustify(LeftText,TopText);
  end;
Procedure Options;
  label
    1;
  const
    lev:array[1..9]of string[6]=(' 最慢 ','非常慢',' 很慢 ','  慢  ',' 正常 ',
                                 '  快  ',' 很快 ','非常快',' 最快 ');
    lab:array[0..4]of string[16]=('玩家一电脑敏捷度','玩家二电脑敏捷度','方块下落速度'
                                   ,'控制设定','返回');
    maxlab=4;
    maxs:array[0..2]of byte=(9,9,9);
    x1=100; y1=240;
    x2=342;
  var
    sel:byte;
    ais:array[0..2]of integer;
    ch:char;
    i:integer;
  Procedure Fresh(P:byte);
    const
      y:array[0..2]of integer=(240,270,300);
    begin
      setfillstyle(1,0);
      bar(x2,y[p],x2+48,y[p]+16);
      outchinese(x2,y[p],lev[ais[p]],0);
    end;
  begin
    ais[0]:=(300-AISpeed[0])div 30;
    ais[1]:=(300-AISpeed[1])div 30;
    ais[2]:=Speed[0]+5;
    sel:=0;
  1:settextstyle(0,0,1);
    setcolor(7);
    setfillstyle(1,0);
    bar(0,237,639,440);
    for i:=0 to maxlab do
      outchinese(x1,y1+i*30,lab[i],0);
    setcolor(2);
    for i:=0 to maxlab-2 do Fresh(i);
    repeat
      putimage(x1-30,y1+sel*30-2,p^,NormalPut);
      setcolor(15);
      outchinese(x1,y1+sel*30,lab[sel],0);
      if sel<=maxlab-2 then
        if ais[sel]=1 then outtextxy(x2-8,y1+5+sel*30,'       >') else
        if ais[sel]=maxs[sel] then outtextxy(x2-8,y1+5+sel*30,'<')
          else outtextxy(x2-8,y1+5+sel*30,'<      >');
      setcolor(10);
      if sel<=maxlab-2 then Fresh(sel);
      ch:=Upcase(readkey);
        if (ch in [#72,#80,#13,#32]) then begin
          putimage(x1-30,y1+sel*30-2,p^,XORPut);
          setcolor(7);
          outchinese(x1,y1+sel*30,lab[sel],0);
          setcolor(0);
          if sel<=maxlab-2 then outtextxy(x2-8,y1+5+sel*30,'<      >');
          setcolor(2);
          if sel<=maxlab-2 then Fresh(sel);
        end;
        case ch of
          #80:if sel<maxlab then inc(sel) else sel:=0;
          #72:if sel>0 then dec(sel) else sel:=maxlab;
          #75:if sel<=maxlab-2 then begin
                case sel of
                  0,1,2:if ais[sel]>1 then dec(ais[sel]);
                end;
                Fresh(sel);
              end;
          #77:if sel<=maxlab-2 then begin
                case sel of
                  0,1,2:if ais[sel]<maxs[sel] then inc(ais[sel]);
                end;
                Fresh(sel);
              end;
          #13,#32:if sel=maxlab-1 then begin
                    controller;
                    goto 1;
                  end else
                  if sel<=maxlab-2 then begin
                    sel:=maxlab;
                    ch:=#1;
                  end;
        end;
    until ((ch in [#13,#32])and(sel=maxlab))or(ch=#27);
    AISpeed[0]:=300-ais[0]*30;
    AISpeed[1]:=300-ais[1]*30;
    Speed[0]:=ais[2]-5;
    Speed[1]:=Speed[0];
    Save_var;
  end;
function NextSelect:boolean;
  const
    maxlab=3;
    lab:array[0..3]of string[10]=('玩家一','玩家二','使用道具','开始游戏');
    x1=240;
    y1=240;
    x2=x1+16*8;
  var
    sel:integer;
    i:integer;
    ch:char;
  Procedure Fresh(P:byte);
    const
      lab:array[0..1]of string[4]=('人脑','电脑');
      lab2:array[0..1]of string[4]=('禁止','允许');
    begin
      setfillstyle(1,0);
      bar(x2+8,y1+p*30,x2+40,y1+p*30+16);
      if p=2 then outchinese(x2+8,y1+p*30,lab2[ ord(ItemAllow) ],0)
        else outchinese(x2+8,y1+p*30,lab[ ord(Com[p]) ],0);
    end;
  begin
    sel:=3;
    settextstyle(0,0,1);
    setfillstyle(1,0);
    bar(x1-50,y1-50,x1+260,y1+150);
    setcolor(7);
    for i:=0 to maxlab do outchinese(x1,y1+i*30,lab[i],0);
    setcolor(2);
    for i:=0 to maxlab-1 do Fresh(i);
    repeat
      putimage(x1-30,y1+sel*30-2,p^,NormalPut);
      setcolor(15);
      outchinese(x1,y1+sel*30,lab[sel],0);
      if sel<>3 then outtextxy(x2-8,y1+5+sel*30,'<      >');
      setcolor(10);
      if sel<>3 then Fresh(sel);
      ch:=Upcase(readkey);
        if (ch in [#72,#80,#13,#32]) then begin
          putimage(x1-30,y1+sel*30-2,p^,XORPut);
          setcolor(7);
          outchinese(x1,y1+sel*30,lab[sel],0);
          setcolor(0);
          if sel<>3 then outtextxy(x2-8,y1+5+sel*30,'<      >');
          setcolor(2);
          if sel<>3 then Fresh(sel);
        end;
        case ch of
          #80:if sel<maxlab then inc(sel) else sel:=0;
          #72:if sel>0 then dec(sel) else sel:=maxlab;
          #75,#77:if sel<>3 then begin
                    case sel of
                      0,1:com[sel]:=not com[sel];
                      2:ItemAllow:=not ItemAllow;
                    end;
                    Fresh(sel);
                  end;
          #13,#32:if sel<>3 then begin
                    sel:=3;
                    ch:=#1;
                  end;
          #27:begin nextselect:=false;exit end;
        end;
    until (ch in [#13,#32])and(sel=3);
    nextselect:=true;
    Save_var;
    Darkout(20);
  end;
Procedure MainSelect;
  label
    1;
  const
    maxlab=2;
    lab:array[0..2]of string[8]=('进入游戏','游戏设定','离开游戏');
    x1=320;
    y1=240;
  var
    sel:integer;
    i:integer;
    ch:char;
  begin
    sel:=0;
  1:setfillstyle(1,0);
    bar(0,237,639,400);
    setcolor(7);
    for i:=0 to maxlab do outchinese(x1,y1+i*30,lab[i],0);
    repeat
      putimage(x1-30,y1+sel*30-2,p^,NormalPut);
      setcolor(15);
      outchinese(x1,y1+sel*30,lab[sel],0);
      ch:=Upcase(readkey);
      if ch=#0 then begin
        ch:=readkey;
        if ch in [#72,#80] then begin
          putimage(x1-30,y1+sel*30-2,p^,XORPut);
          setcolor(7);
          outchinese(x1,y1+sel*30,lab[sel],0);
        end;
        case ch of
          #80:if sel<maxlab then inc(sel) else sel:=0;
          #72:if sel>0 then dec(sel) else sel:=maxlab;
        end;
      end;
    until ch in [#13,#32];
    case sel of
      0:if not nextselect then goto 1;
      1:begin Options; goto 1; end;
      2:begin Save_var; Darkout(50); Delay(500); CloseGraph; halt; end;
    end;
  end;

Procedure Free_mem;
  Const
    r=10;
  Var
    i:integer;
    nowf:face;
  Procedure dfs(p:face;x:integer);
    begin
      if p<>FaceP[i] then dfs(p^.next,x);
      Freemem(p^.bitmap,Imagesize(100,100,197,197));
      dispose(p);
    end;
  Begin
    for i:=100 to 112 do
      if itemP[i]<>nil then Freemem(itemp[i],imagesize(101,101,119,119));
    for i:=0 to 8 do Freemem(tetp[i],imagesize(101,101,119,119));
    for i:=1 to 7 do
      dfs(FaceP[i]^.next,i);
    Freemem(p, imagesize(100-r,100-r,100+r,100+r));
  End;

Procedure PlayGame;
  BEGIN
    Init_Var;
    Init_Pic;
    Init_Face;
    Init_Main;
    Init_TetrisBoard;
    Count_3_2_1_GO;
    Main;
    Finish;
    Free_mem;
  END;

BEGIN
Init_Graph;
Init_Mouse;
Dark;
repeat
  Load_Var;
  Init_Start;
  MainSelect;
  PlayGame;
  ClearDevice;
until false;
END.
