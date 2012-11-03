var st:ansistring;
    m,n,i,j,min,mink,max,maxk:integer;
    shu:array[1..1000] of integer;
    y:array[1..1000,1..1000] of integer;
procedure f(sh,w,k,p:integer);
var p1:integer;
begin
if w>n then
     begin
     p1:=(p*y[sh,n]) mod m;
     if p1<min then begin min:=p1; mink:=k; end
              else if (p1=min) and (k<mink) then mink:=k;
     if p1>max then begin max:=p1; maxk:=k; end
              else if (p1=max) and (k<maxk) then maxk:=k;
     end
      else
 begin
 if (min=0) and (max=m-1) then if (k>=mink) and (k>=maxk) then exit;
 f(sh,w+1,k,p);
 f(w,w+1,k+1,(p*y[sh,w-1]) mod m);
 end;
end;
begin

        assign(input,'P1455.in');
        reset(input);
        assign(output,'P1455.out');
        rewrite(output);
readln(st);  n:=length(st);
readln(m);
for i:=1 to n do shu[i]:=ord(st[i])-48;
for i:=1 to n do y[i,i]:=shu[i] mod m;
for i:=1 to n-1 do
 for j:=i+1 to n do y[i,j]:=(y[i,j-1]*10+shu[j]) mod m;
for i:=1 to n do shu[i]:=shu[i] mod m;
min:=y[1,n]; mink:=0; max:=y[1,n]; maxk:=0;
f(1,2,0,1);
writeln(min,' ',mink,' ',max,' ',maxk);

        close(input);
        close(output);
end.
