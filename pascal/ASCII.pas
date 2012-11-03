var i:longint;
    st:string;
begin
writeln(ord('(')-1);
writeln(chr(39));
st:='abcdef';
insert('[/blue]',st,5+1);
writeln(st);
insert('[blue]',st,2);
writeln(st);
end.
