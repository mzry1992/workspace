const kk = 'wo jia de hua!';
var
        f:array[0..10,0..10,1..301]of integer;
        a:array[1..310]of integer;
        i,t1,t2,n:integer;ch:char;

function min(a,b:integer):integer;
begin
        if a<b then exit(a) else exit(b);
end;

function dfs(x,y,z,k:integer):integer;
var t,t1,t2,i:integer;
begin
      if k>=n then exit(ord(x>0)+ord(y>0)+ord(z>0));
      if f[x,y,k]<>0 then exit(f[x,y,k]);
      f[x,y,k]:=10000;
      t:=10-x-y;t1:=0;t2:=0;
      for i:=k+1 to k+10 do
      begin
                if a[i]=1 then inc(t1) else if a[i]=2 then inc(t2);
                if i-k=x then f[x,y,k]:=min(f[x,y,k],dfs(0+t1,y+t2,t+x-t1-t2,i)+1);
                if i-k=y then f[x,y,k]:=min(f[x,y,k],dfs(x+t1,0+t2,t+y-t1-t2,i)+1);
                if i-k=t then f[x,y,k]:=min(f[x,y,k],dfs(x+t1,y+t2,t-t1-t2,i)+1);
      end;
      exit(f[x,y,k]);
end;

begin
        readln(n);
        for i:=1 to n do
        begin
                readln(ch);
                a[i]:=ord(ch)-ord('A')+1;
        end;
        fillchar(f,sizeof(f),0);
        t1 := 0;  t2 := 0;
        for i:=1 to min(n,10) do
        if a[i]=1 then inc(t1) else if a[i]=2 then inc(t2);
        writeln(dfs(t1,t2,min(10,n)-t1-t2,min(n,10)))
end.
