const bigprime=3214567;
      fac:array[1..8]of longint=(1,2,6,24,120,720,5040,40320);
      change:array[1..2,1..12]of integer=((1,1,2,2,3,4,4,5,5,6,7,8),
                                          (2,4,3,5,6,5,7,6,8,9,8,9));
      w:array[1..8,1..9]of integer=((2,7,6,9,5,1,4,3,8)
                                    ,(2,9,4,7,5,3,6,1,8)
                                    ,(4,3,8,9,5,1,2,7,6)
                                    ,(4,9,2,3,5,7,8,1,6)
                                    ,(6,1,8,7,5,3,2,9,4)
                                    ,(6,7,2,1,5,9,8,3,4)
                                    ,(8,1,6,3,5,7,4,9,2)
                                    ,(8,3,4,1,5,9,6,7,2));
type arr=array[1..9]of integer;
     point=^rec;
     rec=record
         v:arr;
         step:integer;
         next:point;
         end;
var hash:array[0..bigprime-1]of point;
    q:array[0..400000]of rec;
    a:arr;
    i,j,sum:integer;
    key:longint;
    now:point;
    flag:boolean;
function equal(a,b:arr):boolean;
 var i:integer;
 begin
    for i:=1 to 9 do if a[i]<>b[i] then exit(false);
    exit(true);
 end;
function update(a:arr;p,q:integer):arr;
 begin
    update:=a;
    update[p]:=a[q];
    update[q]:=a[p];
 end;
function find(a:arr;step:integer):boolean;
 var now:point;
      i:integer;
      key:longint;
 begin
    key:=0;
    for i:=1 to 8 do key:=(key+(a[i]-1)*fac[i]) mod bigprime;
    now:=hash[key mod bigprime];
    while now<>NIL do
    begin
      if equal(now^.v,a)
      then begin
        if step<now^.step then now^.step:=step;
        exit(true);
      end;
      now:=now^.next;
    end;
    new(now);
    now^.v:=a;
    now^.step:=step;
    now^.next:=hash[key mod bigprime];
    hash[key mod bigprime]:=now;
    exit(false);
 end;
procedure bfs;
 var f,r:longint;
 begin
    f:=0; r:=8;
    for i:=1 to 8 do
    begin
      find(w[i],0);
      q[i].v:=w[i];
      q[i].step:=0;
    end;
    repeat
      inc(f);
      for i:=1 to 12 do
       if not find(update(q[f].v,change[1,i],change[2,i]),q[f].step+1)
       then begin
         inc(r);
         q[r].v:=update(q[f].v,change[1,i],change[2,i]);
         q[r].step:=q[f].step+1;
       end;
    until f>=r;
 end;
begin
 bfs;
 for sum:=1 to 50 do
 begin
    for j:=1 to 9 do read(a[j]);
    key:=0;
    for i:=1 to 8 do key:=(key+(a[i]-1)*fac[i]) mod bigprime;
    now:=hash[key];
    flag:=true;
    while now<>NIL do
    begin
      if equal(now^.v,a)
      then begin writeln(now^.step); flag:=false; break; end;
      now:=now^.next;
    end;
    if flag then writeln(-1);
    readln;
 end;
end.
