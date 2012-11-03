var testcase,testnow:integer;
    n,k,i,j,a,b,time:longint;
    x:array[1..100] of ansistring;
    use:array[1..100] of boolean;
    st:ansistring;

function getx(a:ansistring):longint;
var i:longint;
begin
for i:= 1 to n do
 if x[i] = a then exit(i);
exit(0);
end;

begin
readln(testcase);
for testnow:= 1 to testcase do
 begin
 readln(n,k);
 for i:= 1 to n do readln(x[i]);
 fillchar(a,sizeof(a),false);
 time:=-1;
 b:=0;
 for i:= 1 to k do
 begin
        readln(st);
        a:=getx(st);
        if a > 0 then
        if not use[a] then
                begin
                inc(b);
                use[a]:=true;
                if b = n then
                begin
                        inc(time);
                        fillchar(use,sizeof(use),false);
                        use[a]:=true;
                        b:=1;
                end;
                end;
 end;
 if b > 0 then inc(time);
 if time = -1 then time:=0;
 writeln('For ',testnow,'# problem we need ',time);
 end;
end.
