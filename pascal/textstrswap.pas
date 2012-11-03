var st:string;
    i,j:longint;
    ch:char;
begin
st:='012345678';
ch:=st[1];
st[1]:=st[4];
st[4]:=ch;
writeln('-->',st,'<--');
end.
