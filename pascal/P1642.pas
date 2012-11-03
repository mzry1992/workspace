var n,m,i,j,x,top,di,now,max:longint;
    s,v,tp,g,step,f:array[1..1000] of longint;
    hs:array[1..1000] of boolean;
    flg:boolean;

begin
fillchar(tp,sizeof(tp),0);
readln(n,m);
for i:= 1 to n do
begin
readln(v[i],tp[i]);
if tp[i] > 0 then
begin
for j:= 1 to tp[i] do
 read(g[j]);
readln;
end;
end;
max:=v[1];
fillchar(hs,sizeof(hs),false);
top:=1; di:=1; s[1]:=1; hs[1]:=true; step[1]:=0; flg:=true; f[1]:=v[1];
while flg do
begin
now:=di;
if tp[s[now]] > 0 then
for i:= 1 to tp[s[now]] do
 if not hs[g[i]]  then
  begin
  hs[g[i]]:=true;
  inc(top);
  s[top]:=g[i];
  step[top]:=step[now]+1;
  f[top]:=f[now]+v[g[i]];
  if step[top] = m then
   if f[top] > max then max:=f[top];
  if step[top] = m+1 then flg:=false;
  end;
inc(di);
if di > top then flg:=true;
end;
writeln(max);
end.