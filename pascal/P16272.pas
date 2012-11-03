var
d,c,f,ll,rr:packed array[0..1000]of longint;
s:packed array[0..1000]of int64;
n,l,r,i,j,max,k,t,p,last:longint;
begin
        assign(input,'1.txt');
        reset(input);

    readln(n,l,r);max:=-maxlongint;
    for i:=1 to n do read(d[i]);readln;
    for i:=1 to n do read(f[i]);readln;
    for i:=1 to n do begin read(c[i]);s[i]:=s[i-1]+c[i];end;
    for i:=1 to n do
        begin
        last:=0;
        for j:=i-1 downto 1 do begin
                                p:=last+c[j]-l-r;
                                if p>ll[i] then ll[i]:=p;
                                last:=p;
                               end;
        last:=0;if ll[i]<0 then ll[i]:=0;
        for j:=i+1 to n do begin
                               p:=last+c[j]-l-r;
                               if p>rr[i] then rr[i]:=p;
                               last:=p;
                           end;
        if rr[i]<0 then rr[i]:=0;
        end;
     for i:=1 to n do
       for j:=1 to n do
       begin
           if i<=j then
                     begin
                     k:=s[j]-s[i-1]-r*(j-i)+ll[i]+rr[j]-d[i]-f[j];
                     if k>max then max:=k;
                     end
                   else
                     begin
                     k:=s[i]-s[j-1]-l*(i-j)+ll[j]+rr[i]-d[i]-f[j];
                     if k>max then max:=k;
                     end;
       end;
    writeln(max);

    close(input);
end.
