const
 maxn=50002;
type
 node=  record
           ls,rs,a,b,zkh,ykh:longint;
         end;
var
 p:array[1..maxn*2] of node;
 all,ansz,ansy:longint;
procedure creat(c,d:longint);
 var
    now,mid:Longint;
 begin
    inc(all);
    now:=all;
    p[now].a:=c; p[now].b:=d;
    if c<d then
      begin
        mid:=(c+d) div 2;
        p[now].ls:=all+1;
        creat(c,mid);
        p[now].rs:=all+1;
        creat(mid+1,d);
      end;
 end;
procedure insert(now,c,d,zn,yn:longint);
 var
    mid:longint;
 begin
    if (d<p[now].a) or (c>p[now].b) then
      exit;
    if (c=p[now].a) and (d=p[now].b) then
      begin
        inc(p[now].zkh,zn);
        inc(p[now].ykh,yn);
        exit;
      end;

    insert(p[now].ls,c,d,zn,yn);
    insert(p[now].rs,c,d,zn,yn);
    if p[now].ls<>0 then
      begin
        p[now].zkh:=p[p[now].ls].zkh+p[p[now].rs].zkh;
        p[now].ykh:=p[p[now].ls].ykh+p[p[now].rs].ykh;
      end;

 end;
procedure count(now,a,b:longint);
 var
    t:longint;
 begin
    if (a<=p[now].a) and (p[now].b<=b) then
      begin
        inc(ansz,p[now].zkh);
        inc(ansy,p[now].ykh);
        exit;
      end;

    if (a<=(p[now].a+p[now].b) div 2) and (p[now].ls<>0) then
      count(p[now].ls,a,b);
    if ((p[now].a+p[now].b) div 2 <=b) and (p[now].rs<>0) then
      count(p[now].rs,a,b);

 end;

var
 i,n,m,k,a,b,t:longint;
begin
 fillchar(p,sizeof(p),0);
 readln(n,m);
 creat(1,n);
 for i:= 1 to m do
    begin
      readln(k,a,b);
      if k=1 then
        begin
          insert(1,b,b,0,1);
          insert(1,a,a,1,0);
        end     else
        begin
          ansz:=0; ansy:=0;
          count(1,1,a-1);
          t:=ansy;
          ansz:=0; ansy:=0;
          count(1,1,b);
          writeln(ansz-t);
        end;

    end;

 readln;
end.
