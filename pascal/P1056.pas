var n,i,j,x,y:longint;
    c,k:array[1..200] of longint;
    z:array[1..100,1..8] of longint;

procedure qsort1(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l; j:=r; m:=x[(i+j) div 2];
repeat
while x[i] < m do inc(i);
while x[j] > m do dec(j);
if i <= j then
begin
temp:=x[i]; x[i]:=x[j]; x[j]:=temp;
inc(i); dec(j);
end;
until i > j ;
if i < r then qsort1(i,r);
if j > l then qsort1(l,j);
end;

procedure qsort2(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l; j:=r; m:=y[(i+j) div 2];
repeat
while y[i] < m do inc(i);
while y[j] > m do dec(j);
if i <= j then
begin
temp:=y[i]; y[i]:=y[j]; y[j]:=temp;
inc(i); dec(j);
end;
until i > j ;
if i < r then qsort2(i,r);
if j > l then qsort2(l,j);
end;

begin
readln(n);
for i:= 1 to n do
begin
readln(z[i,1],z[i,2],z[i,3],z[i,4]);
c[2*i-1]:=z[i,1]; c[2*i]:=z[i,3];
k[2*i-1]:=z[i,2]; k[2*i]:=z[i,4];
z[i,5]:=c[2*i-1]; z[i,6]:=k[2*i-1];
z[i,7]:=c[2*i]; z[i,8]:=k[2*i];
end;
end.

end.
