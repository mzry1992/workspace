type
   matrixtype = array[1..11,1..11] of qword;
var
   base,kans,bb:matrixtype;
   bans:array[0..11] of longint;
   level,n,i,j:longint;

function matrix(a,b:matrixtype;n:longint):matrixtype;
var
   i,j,k:longint;
   temp:matrixtype;
begin
   fillchar(temp,sizeof(temp),0);
   for i := 1 to n do
   for j := 1 to n do
   for k := 1 to n do
      temp[i,j] := (temp[i,j]+a[i,k]*b[k,j]) mod 7777777;
   exit(temp);
end;

procedure roll(x:longint);
begin
   if x = 1 then bb := base
   else
   begin
      roll(x shr 1);
      bb := matrix(bb,bb,level+1);
      if x and 1 = 1 then
         bb := matrix(bb,base,level+1);
   end;
end;

begin
   readln(level);
   readln(n);
   fillchar(base,sizeof(base),0);
   for i := 1 to level do
   begin
      base[i,i+1] := 1;
      base[level+1,i+1] := 1;
   end;
   fillchar(bans,sizeof(bans),0);
   bans[0] := 1;
   for i := 1 to level+1 do
   for j := i-1 downto i-level do
   if j >= 0 then
      bans[i] := bans[i]+bans[j];
   fillchar(kans,sizeof(kans),0);
   for i := 1 to level+1 do
      kans[i,1] := bans[i];
   if n <= level+1 then
   begin
      writeln(kans[n,1]);
      halt;
   end;
   roll(n-level-1);
   kans := matrix(bb,kans,level+1);
   writeln(kans[level+1,1]);
end.