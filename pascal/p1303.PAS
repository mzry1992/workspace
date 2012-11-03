var st:string;
    a,list:array[0..100]of integer;
    s,i,j,k,l,r,p:integer;
    vis:array[0..100]of boolean;
procedure qiu;
begin
 list[1]:=1;
 k:=1;
 for i:=2 to s do
    if a[i]<a[list[k]] then
      begin
        inc(k);
        list[k]:=i;
      end
    else
    begin
      l:=1;
      r:=k;
      while l<r do
        if a[list[(l+r)shr 1]]>a[i] then l:=(l+r)shr 1+1
         else r:=(l+r)shr 1;
      list[l]:=i;
    end;
end;
begin
 readln(st);
 s:=0;
 i:=1;
 j:=2;
 while j<=length(st) do
    begin
      while st[j]<>',' do inc(j);
      inc(s);
      val(copy(st,i,j-i),a[s]);
      inc(j);
      i:=j;
    end;
 qiu;
 write(k,',');
p:=0;
while s>0 do
begin
 fillchar(vis,sizeof(vis),false);
 j:=1;
 vis[list[1]]:=true;
 for i:=2 to k do
    if list[i]>list[j] then
      begin
        vis[list[i]]:=true;
        j:=i;
      end;
 inc(p);
 j:=0;
 for i:=1 to s do
    if not vis[i] then
     begin
       inc(j);
       a[j]:=a[i];
     end;
 s:=j;
 if s=0 then break;
 qiu;
end;
if p > 0 then
 writeln(p-1)
 else writeln(p);
end.
