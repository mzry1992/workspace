var n,m,i,min,a,b,ta,tb,now:longint;
    l,r,w:array[1..3000] of longint;
    mp:array[1..5000] of boolean;

procedure qsort(ll,rr:longint);
var i,j,k,temp:longint;
begin
i:=ll;
j:=rr;
k:=l[(i+j) div 2];
repeat
while l[i] < k do inc(i);
while l[j] > k do dec(j);
if i <= j then
 begin
 temp:=l[i]; l[i]:=l[j]; l[j]:=temp;
 temp:=r[i]; r[i]:=r[j]; r[j]:=temp;
 temp:=w[i]; w[i]:=w[j]; w[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if ll < j then qsort(ll,j);
if i < rr then qsort(i,rr);
end;

begin
readln(n,m);
fillchar(mp,sizeof(mp),true);
for i:= 1 to m do readln(l[i],r[i],w[i]);
qsort(1,m);
ta:=l[1]; tb:=r[1]; now:=1;

end.