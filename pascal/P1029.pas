const exnumber = 1  ;
      ch:array[1..12,1..2] of integer = ((1,4),(2,5),(3,6),(4,7),(5,8),(6,9),(1,2),(2,3),(4,5),(5,6),(7,8),(8,9));
      ok:array[1..8,1..9] of integer = ((2,7,6,9,5,1,4,3,8),
                                        (2,9,4,7,5,3,6,1,8),
                                        (4,3,8,9,5,1,2,7,6),
                                        (4,9,2,3,5,7,8,1,6),
                                        (6,1,8,7,5,3,2,9,4),
                                        (6,7,2,1,5,9,8,3,4),
                                        (8,1,6,3,5,7,4,9,2),
                                        (8,3,4,1,5,9,6,7,2));

var rednum,k,total,i,j,x,y,top,di,now,ans,fans:longint;
    a:array[1..9] of integer;
    s:array[1..50000,1..9] of longint;
    f:array[1..362880] of boolean;
    step:array[1..50000] of longint;
    use:array[1..9] of boolean;
    flg:boolean;
    q,w,e,r:longint;

begin

for rednum:= 1 to exnumber do
 begin

 //////////INPUT/////////////
 fillchar(f,sizeof(f),true);
 x:=0;
 repeat
 inc(x);
 read(a[x]);
 if x mod 3 = 0 then readln;
 until x = 9 ;
 ////////////////////////////

 ////////////////////////////
 for top:= 1 to 8 do
 begin
  for x:= 1 to 9 do
   s[top,x]:=ok[top,x];

 fillchar(use,sizeof(use),true);
  ans:=1;
  for i:= 1 to 9 do
  begin
  use[s[top,i]]:=false;
  total:=0;
  for j:= 1 to s[top,i] - 1  do
   if use[j] then inc(total);
  k:=1;
  for j:= 1 to s[top,i] - 1 do k:=k*j;
  ans:=ans+k*total;

  f[ans]:=false;
  end;

 end;
 ///////////////////////////

 ///////////////////////////
 for top:= 1 to 8 do
 begin
  for x:= 1 to 9 do write(s[top,x],' ');
  writeln;
 end;
 ///////////////////////////

 /////////////////////////
 fillchar(use,sizeof(use),true);
  ans:=1;
  for i:= 1 to 9 do
  begin
  use[a[i]]:=false;
  total:=0;
  for j:= 1 to a[i] - 1  do
   if use[j] then inc(total);
  k:=1;
  for j:= 1 to a[i] - 1 do k:=k*j;
  ans:=ans+k*total;
  end;
  fans:=ans;
 /////////////////////////

 ////////BFS////////
 if f[fans] = false then writeln(0)
 else
  begin
  top:=8;
  di:=1;
  flg:=false;
  fillchar(step,sizeof(step),0);
  writeln('Begin BFS------>');

  /////////////////
  while not flg do
   begin
   now:=di;
   //////////////////////////////////////////////////////
   for q:= 1 to 12 do
    begin

    inc(top);
    for x:= 1 to 9 do
     s[top,x]:=s[now,x];

    w:=s[top,ch[q,1]];
    s[top,ch[q,1]]:=s[top,ch[q,2]];
    s[top,ch[q,2]]:=w;

    ///////////////HASH///////////////////
    fillchar(use,sizeof(use),true);
    ans:=1;
    for i:= 1 to 9 do
    begin
    use[s[top,i]]:=false;
    total:=0;
    for j:= 1 to s[top,i] - 1  do
    if use[j] then inc(total);
    k:=1;
    for j:= 1 to s[top,i] - 1 do k:=k*j;
    ans:=ans+k*total;

    if f[ans] then
     begin
     step[top]:=step[now]+1;
     if ans = fans then flg:=true;
     f[ans]:=false;
     end
    else dec(top);

    //////////////////////////////////////
    inc(di);
    end;

   ///////////////////////////////////////////////////////////
   end;
  /////////////////


  end;
 ///////////////////

 end;
writeln(step[now]);
end;
end.
