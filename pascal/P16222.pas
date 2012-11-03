var
 s:string;
 ss:array[1..3000]of string;
 k:longint;

procedure make;
var st:string;
    i,num:longint;
begin
 if not(eof)then
 begin
    readln(st);
    if pos(' ',st)<>0 then
    begin
      val(copy(st,pos(' ',st)+1,length(st)-pos(' ',st)),num);
      st:=copy(st,1,pos(' ',st)-1);
      if num>0then
      begin
        k:=k+1;
        ss[k]:=st;
        for i:=1 to num do
          make;
        k:=k-1;
      end;
    end
    else begin
      if st=s then
      begin
        for i:=1 to k do
          write(ss[i],'\');
        writeln(st);
      end;
    end;
 end;
end;

begin
assign(input,'P1622.in');
assign(output,'P1622.txt');
reset(input);
rewrite(output);
 readln(s);
 k:=0;
 while not(eof)do
    make;
close(input);
close(output);
end.
