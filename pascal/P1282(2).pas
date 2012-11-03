type
    jl=record
      bh:longint;
      w:longint;
    end;

 var
    i,j,k,n:longint;
    x:array[0..100000]of jl;
    e:array[1..10]of longint;


 procedure qsort1(l,r: longint);
      var
         i,j,xx,y,yy:longint;
      begin
         i:=l;
         j:=r;
         xx:=x[(l+r) div 2].w;
         yy:=x[(l+r) div 2].bh;
         repeat
           while (x[i].w>xx) or ((x[i].w=xx)and(x[i].bh<yy)) do inc(i);
           while (x[j].w<xx) or ((x[j].w=xx)and(x[j].bh>yy)) do dec(j);
           if not(i>j) then
             begin
                y:=x[i].w;
                x[i].w:=x[j].w;
                x[j].w:=y;
                y:=x[i].bh;
                x[i].bh:=x[j].bh;
                x[j].bh:=y;
                inc(i);
                dec(j);
             end;
         until i>j;
         if l<j then
           qsort1(l,j);
         if i<r then
           qsort1(i,r);
      end;

 begin
    readln(n,k);
    if k=0 then begin write(' '); exit; end;
    for i:=1 to 10 do read(e[i]);
    for i:=1 to n do
      begin
        read(x[i].w);
        x[i].bh:=i;
      end;
    qsort1(1,n);
    for i:=1 to n do
      x[i].w:=x[i].w+e[(i-1) mod 10 +1];
    qsort1(1,n);

    for i:=1 to k-1 do write(x[i].bh,' ');
    write(x[k].bh);

 end.
