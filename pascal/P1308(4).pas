var a,b,max,m:longint;
    flg:boolean;
    f,t:array[1..10000] of int64;

procedure dfs(sum:double;dp:longint);
var i,j:int64;
    temp:double;
begin
if dp > max + 1 then exit;
if dp = max + 1 then
 if abs(a/b - sum ) < 1E-8 then
  begin
  if ( t[max] < f[max]) or ( not flg ) then
   begin
   f:=t;
   flg:=true;
   exit;
   end;
  end;
i:=t[dp-1];
while (max-dp)/i <= a/b-sum do inc(i);
 begin
 temp:=sum;
 temp:=temp+1/i;
 t[dp]:=i;
 dfs(temp,dp+1);
 sum:=temp;
 end;
end;

begin
readln(a,b);
flg:=false;
max:=0;
m:=2;
fillchar(f,sizeof(f),0);
while a*m < b do inc(m);
t[0]:=m-1;
while not flg do
 begin
 inc(max);
 dfs(0,1);
 end;
for m:= 1 to max do write(f[m],' ');
writeln;
end.