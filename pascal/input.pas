uses crt;
const baoliu:array[1..40] of string = ('program','function','procedure',
                                       'array','const','file','label','of','packed','record','set','type','var',
                                       'case','do','downto','else','for','forward','goto','if','repeat','then','to','until','while','with',
                                       'and','div','in','mod','not','or',
                                       'begin','end','nil',
                                       'read','write','ture','false');

var filename,now,temp:ansistring;
function ok(a,b:ansistring):boolean;
var i,j:longint;
begin
for i:= 1 to length(a) do
 if a[i] <> b[i] then exit(false);
exit(true);
end;
procedure done(a:ansistring);
var i,l,j:longint;
    flg:boolean;
    temp:ansistring;
begin
l:=length(a);
i:=0;
temp:=a;
flg:=false;
while i < l do
begin
inc(i);
if ord(temp[i]) = 39 then
 begin
 if flg then
 begin
 insert('[/red]',temp,i+1);
 i:=i+6;
 l:=l+6;
 flg:=false;
 end
 else
 begin
 insert('[red]',temp,i);
 i:=i+5;
 l:=l+5;
 flg:=true;
 end;
 end;
if temp[i] in ['0'..'9'] then
 if not flg then
  begin
  insert('[blue]',temp,i);
  i:=i+6;
  l:=l+5;
  j:=i;
  while temp[j] in ['0'..'9'] do inc(j);
  dec(j);
  i:=j;
  insert('[/blue]',temp,i+1);
  i:=i+6;
  l:=l+6;
  end;
if temp[i] in ['a'..'z'] then
 for j:= 1 to 40 do
  if ok(copy(temp,i,length(baoliu[j]),baoliu[j]) then
   begin
   insert('[b][color=0000ff]',temp,i);
   i:=i+17;
   l:=length(temp);
   i:=i+length(baoliu(j));
   insert('[/color][/b]',temp,i);
   i:=i+12;
   l:=length(temp);
   end;
end;
writeln(temp);
end;

begin
write('Program Name:');
readln(filename);
assign(input,filename+'.pas');
reset(input);
assign(output,filename+'out.txt');
rewrite(output);
while not eof do
begin
readln(now);
done(now);
end;
close(input);
close(output);
end.
