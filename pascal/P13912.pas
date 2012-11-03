const
 t=2000;
var
 map:array[0..t,0..t] of longint;
 v:array[0..t] of boolean;
 dis:array[0..t] of longint;
 n,a,b,i,m:integer;
 r:longint;
//=======================================================================
 function min(x,y:longint):longint;
 begin
    if x>y then exit(y);
    exit(x);
 end;
//=======================================================================
 procedure dist;
 var i,j,w,max,xx:longint;
 begin
    for i:=1 to n do
    dis[i]:=map[1,i];
    for i:=1 to n-1 do
    begin
      max:=0;
      for j:=1 to n do
      if not(v[j])and(dis[j]>max)
      then begin
           max:=dis[j];
           w:=j;
           end;
      v[w]:=true;
      for j:=1 to n do
      begin
        xx:=min(dis[w],map[w,j]);
        if not(v[j])and(map[w,j]>0)and(xx>dis[j])
        then dis[j]:=xx;
      end;
    end;
 end;

//=======================================================================
 procedure init;
 begin
    fillchar(map,sizeof(map),0); fillchar(v,sizeof(v),false);
    readln(n);
    repeat
    readln(a,b,r); map[a,b]:=r
    until (a=0)and(b=0)and(r=0);
 end;
//=======================================================================
 procedure print;
 var i,j:longint;
 begin
    for i:=2 to n do
      writeln(dis[i]);
 end;
//=======================================================================
begin
assign(input,'in.txt');assign(output,'out1.txt');
reset(input);rewrite(output);
 init;
 dist;
 print;
close(input);close(output);
end.