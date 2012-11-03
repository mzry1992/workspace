var a:array[1..15] of longint;
    st:string;
    time,i,j:longint;

function myord(ch:char):integer;
begin
if ch in ['3'..'9'] then
 exit(ord(ch)-ord('2'));
if ch = 'J' then exit(9);
if ch = 'Q' then exit(10);
if ch = 'K' then exit(11);
if ch = 'A' then exit(12);
if ch = '2' then exit(13);
if ch = 'X' then exit(14);
if ch = 'D' then exit(15);
end;

begin
fillchar(a,sizeof(a),0);
readln(st);
i:=1;
while i <= length(st) do
 begin
 if st[i] in ['2'..'9','A','J','Q','K','X','D'] then
  inc(a[myord(st[i])])
 else
  begin
  inc(a[8]);
  inc(i);
  end;
 inc(i);
 end;
time:=0;

end.

