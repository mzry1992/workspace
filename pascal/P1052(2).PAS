var a:array[0..101,0..101] of extended;
    n:longint;
    x:array[0..101] of extended;
procedure init;
var i,k,j:longint;
 begin
    readln(n);
    for i:=1 to n do
      begin
        for k:=1 to n+1 do read(a[i,k]);
        readln;
      end;
 end;
procedure main;
var  i,k,l,m,num:longint; j,max:extended;
 begin
    for i:=1 to n-1 do
      begin
        max:=abs(a[i,i]); num:=i;
        for k:=i+1 to n do
          if abs(a[k,i])>max then begin max:=abs(a[k,i]); num:=k; end;
        if num<>i then
          for k:=1 to n+1 do begin j:=a[i,k]; a[i,k]:=a[num,k]; a[num,k]:=j; end;
        for k:=i+1 to n do
          begin
            m:=i;
            j:=a[k,i]/a[i,i];
            for l:=1 to n+1 do a[k,l]:=a[k,l]-a[i,l]*j;
          end;
      end;
    x[n]:=a[n,n+1]/a[n,n];
    for i:=n-1 downto 1 do
      begin
        j:=0;
        for k:=i+1 to n do j:=j+x[k]*a[i,k];
        x[i]:=(a[i,n+1]-j)/a[i,i];
      end;
    for i:=1 to n do write(round(x[i]),' ');
    writeln;
 end;
begin
 init;
 main;
end.
