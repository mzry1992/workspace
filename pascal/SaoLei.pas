program cm;
uses crt;
const
maxn=100;
mt=-127;
mo=16383;
dx:array [1..8] of shortint=(-1,-1,-1,0,0,1,1,1);
dy:array [1..8] of shortint=(-1,0,1,-1,1,-1,0,1);
type
td=record
  x,y:longint;
end;
var
x:char;
nx,ny,n,i,j,code,mines,minen:longint;
b,g:array [0..maxn,0..maxn] of shortint;

function max(a,b:longint):longint;
begin
if a>b then exit(a) else exit(b);
end;

function min(a,b:longint):longint;
begin
if a>b then exit(b) else exit(a);
end;

function isok(x:longint):boolean;
begin
exit((x>=1) and (x<=n));
end;

procedure prt(x:string;y:longint);
begin
textcolor(y);
write(x);
textcolor(7);
end;

function ch(x:longint):longint;
begin
case x of
  1:exit(11);
  2:exit(2);
  3:exit(4);
  4:exit(13);
  5:exit(6);
  6:exit(10);
  7:exit(5);
  8:exit(12);
end;
end;

procedure prepare;
var
x,y,i,j,k,count:longint;
begin
fillchar(b,sizeof(b),0);
fillchar(g,sizeof(g),0);
for i:=1 to mines do
  begin
   repeat
    x:=random(n)+1;
    y:=random(n)+1;
   until g[x,y]=0;
   g[x,y]:=-1;
  end;
for i:=1 to n do for j:=1 to n do if g[i,j]=0 then
  begin
   count:=0;
   for k:=1 to 8 do if g[i+dx[k],j+dy[k]]=-1 then inc(count);
   g[i,j]:=count;
  end;
for i:=0 to n do
  begin
   g[0,i]:=mt;
   g[i,0]:=mt;
   g[n+1,i]:=mt;
   g[i,n+1]:=mt;
  end;
nx:=n>>1+1;
ny:=n>>1+1;
end;

procedure printf;
var
i,j:longint;
begin
prt('W',4);prt('in',15);prt('M',4);prt('ine ',15);prt('B',4);prt('y ',15);prt('Z',4);prt('bwmqlw',15);
writeln;
for i:=1 to n<<1+3 do write('=');
writeln;
writeln('Mine:',minen,'/',mines);
for i:=1 to n<<1+3 do if i=1 then write(chr(201)) else if i=n<<1+3 then write(chr(187))
else write(chr(205));
writeln;
for i:=1 to n do
  begin
   write(chr(186));
   for j:=1 to n do
    begin
     if (nx=i) and (ny=j) then write('>') else if (nx=i) and (ny=j-1) then write('<') else write(' ');
     case b[i,j] of
      0:write('.');
      1:case g[i,j] of
         -1:prt('X',15);
         0:write(' ');
         1..8:prt(chr(g[i,j]+48),ch(g[i,j]));
        end;
      2:prt(chr(12),15);
     end;
    end;
   if (nx=i) and (ny=n) then write('<') else write(' ');
   writeln(chr(186));
  end;
for i:=1 to n<<1+3 do if i=1 then write(chr(200)) else if i=n<<1+3 then write(chr(188))
else write(chr(205));
writeln;
writeln('W/A/S/D for direction ,J for digging ,K for symboling ,Q for quit.');
end;

procedure bfs(x,y:longint);
var
q:array [0..mo] of td;
s,t,i:longint;
begin
s:=0;t:=1;
q[1].x:=x;
q[1].y:=y;
repeat
  s:=succ(s) and mo;
  x:=q[s].x;
  y:=q[s].y;
  if g[x,y]=0 then for i:=1 to 8 do if isok(x+dx[i]) and isok(y+dy[i]) then if (b[x+dx[i],y+dy[i]]=0) and (g[x+dx[i],y+dy[i]]>=0) then
   begin
    t:=succ(t) and mo;
    q[t].x:=x+dx[i];
    q[t].y:=y+dy[i];
    b[q[t].x,q[t].y]:=1;
   end;
until s=t;
end;

function check:boolean;
var
i,j:longint;
begin
for i:=1 to n do for j:=1 to n do if (g[i,j]<>-1) and (b[i,j]<>1) then exit(false);
exit(true);
end;

begin
randomize;
clrscr;
write('Input size:');
read(n);
write('Input the number of mines:');
read(mines);
prepare;
repeat
  clrscr;
  printf;
  if (x='j') and (g[nx,ny]=-1) then
   begin
    clrscr;
    for i:=1 to n do for j:=1 to n do if g[i,j]=-1 then b[i,j]:=2 else b[i,j]:=1;
    b[nx,ny]:=1;
    printf;
    prt('You Lose !',15);
    readln;
    readln;
    halt;
   end;
  x:=readkey;
  case x of
   'q':halt;
   'w':nx:=max(nx-1,1);
   's':nx:=min(nx+1,n);
   'a':ny:=max(ny-1,1);
   'd':ny:=min(ny+1,n);
   'j':begin
        if b[nx,ny]=2 then dec(minen);
        b[nx,ny]:=1;
        if g[nx,ny]=0 then bfs(nx,ny);
       end;
   'k':if b[nx,ny]=0 then begin
        b[nx,ny]:=2;
        inc(minen);
       end else if b[nx,ny]=2 then begin
        b[nx,ny]:=0;
        dec(minen);
       end;
  end;
until check;
clrscr;
printf;
prt('You Win !',15);
readln;
readln;
end.