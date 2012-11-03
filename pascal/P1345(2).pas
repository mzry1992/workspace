const zxy:array[1..81,1..2] of longint = ((1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(1,8),(1,9),
                                          (2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(2,7),(2,8),(2,9),
                                          (3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(3,7),(3,8),(3,9),
                                          (4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(4,7),(4,8),(4,9),
                                          (5,1),(5,2),(5,3),(5,4),(5,5),(5,6),(5,7),(5,8),(5,9),
                                          (6,1),(6,2),(6,3),(6,4),(6,5),(6,6),(6,7),(6,8),(6,9),
                                          (7,1),(7,2),(7,3),(7,4),(7,5),(7,6),(7,7),(7,8),(7,9),
                                          (8,1),(8,2),(8,3),(8,4),(8,5),(8,6),(8,7),(8,8),(8,9),
                                          (9,1),(9,2),(9,3),(9,4),(9,5),(9,6),(9,7),(9,8),(9,9));
      ztz:array[1..81] of longint = (1,1,1,2,2,2,3,3,3,1,1,1,2,2,2,3,3,3,1,1,1,2,2,2,3,3,3,
                                     4,4,4,5,5,5,6,6,6,4,4,4,5,5,5,6,6,6,4,4,4,5,5,5,6,6,6,
                                     7,7,7,8,8,8,9,9,9,7,7,7,8,8,8,9,9,9,7,7,7,8,8,8,9,9,9);
      xytz:array[1..9,1..9] of longint = ((1,2,3,4,5,6,7,8,9),
                                          (10,11,12,13,14,15,16,17,18),
                                          (19,20,21,22,23,24,25,26,27),
                                          (28,29,30,31,32,33,34,35,36),
                                          (37,38,39,40,41,42,43,44,45),
                                          (46,47,48,49,50,51,52,53,54),
                                          (55,56,57,58,59,60,61,62,63),
                                          (64,65,66,67,68,69,70,71,72),
                                          (73,74,75,76,77,78,79,80,81));
var a:array[1..9,1..9] of 0..9;
    n,x,y,ttt:longint;
    ch:char;
    l,c,sm:array[1..9,1..9] of boolean;

procedure output;
var x,y:longint;
begin
for y:= 1 to 9 do
 for x:= 1 to 9 do write(a[x,y]);
writeln;
end;

function canuse(step,i:integer):boolean;
var x,y,z:longint;
begin
x:=zxy[step,1];
y:=zxy[step,2];
z:=ztz[step];
if not l[x,i] then exit(false);
if not c[y,i] then exit(false);
if not sm[z,i] then exit(false);
exit(true);
end;


procedure dfs(step:longint);
var i,x,y,z:longint;
begin
if step = 82 then
 begin
 output;
 exit;
 end;
x:=zxy[step,1];
y:=zxy[step,2];
z:=ztz[step];
if a[x,y] > 0 then
 begin
 dfs(step+1);
 exit;
 end;
for i:= 1 to 9 do
 if canuse(step,i) then
  begin
  a[x,y]:=i;
  l[x,i]:=false;
  c[y,i]:=false;
  sm[z,i]:=false;
  dfs(step+1);
  l[x,i]:=true;
  c[y,i]:=true;
  sm[z,i]:=true;
  a[x,y]:=0;
  end;
end;



begin
readln(n);
for ttt:= 1 to n do
 begin
 fillchar(l,sizeof(l),true);
 fillchar(c,sizeof(c),true);
 fillchar(sm,sizeof(sm),true);
 for y:= 1 to 9 do
  for x:= 1 to 9 do
  begin
   read(ch);
   a[x,y]:=ord(ch)-ord('0');
   if a[x,y] <> 0 then
   begin
   l[x,a[x,y]]:=false;
   c[y,a[x,y]]:=false;
   sm[ztz[xytz[x,y]],a[x,y]]:=false;
   end;
  end;
 readln;
 dfs(1);
 end;
end.

