var n,num,vv:longint;
    w,v:array[0..200] of longint;
    f:array[0.. 5000,0..40] of longint;
    t1,t2:array[0..40] of longint;
procedure init;
var i,k:longint;
begin
    readln(num,vv,n);
    for i:=1 to n do readln(w[i],v[i]);
end;
procedure main;
var i,k,j,c1,c2,c3,q1,q2:longint;
begin
    fillchar(f,sizeof(f),0); f[0,0]:=1;
    for i:=1 to n do
     for k:=vv downto w[i] do
        if f[k-w[i],0]<>0 then
        begin
         c1:=f[k,0]; c2:=f[k-w[i],0];
         c3:=c1+c2; if c3>num then c3:=num;
         q1:=1; q2:=1;
         t1:=f[k]; t2:=f[k-w[i]];
         for j:=1 to c2 do t2[j]:=t2[j]+v[i];
         for j:=1 to c3 do
            if (t1[q1]>t2[q2]) or (q2>c2) then begin f[k,j]:=t1[q1]; inc(q1); end
                                         else begin f[k,j]:=t2[q2]; inc(q2); end;
         f[k,0]:=c3;
        end;
    j:=0;
    for i:=1 to num do
     inc(j,f[vv,i]);
    writeln(j);
end;
begin
init;
main;
end.
