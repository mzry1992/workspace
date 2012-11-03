var n,i,j,temp,now,max:longint;
    k:array[0..10001] of longint;
    f:array[1..100,0..10001] of boolean;

begin
readln(n);
fillchar(f,sizeof(f),false);
max:=0;
for i:= 1 to n do
 begin
 f[i,0]:=true;
 now:=0;
 repeat
 read(temp);
 if temp <> -1 then
 begin
 inc(now,temp);
 for j:= now downto temp do
  if ( f[i,j-temp] ) and ( not f[i,j] ) then begin f[i,j]:=true; inc(k[j]); end;
 end;
 until temp= -1 ;
 if now > max then max:=now;
 readln;
 end;
for i:= max downto 1 do
 if k[i] = n then begin writeln(i); halt; end;
writeln(0);
end.
