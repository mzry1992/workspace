var
        c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c,cr:char;
function done:integer;
begin
        done := 0;
        done := done+1*(ord(c1)-ord('0'));
        done := done+2*(ord(c2)-ord('0'));
        done := done+3*(ord(c3)-ord('0'));
        done := done+4*(ord(c4)-ord('0'));
        done := done+5*(ord(c5)-ord('0'));
        done := done+6*(ord(c6)-ord('0'));
        done := done+7*(ord(c7)-ord('0'));
        done := done+8*(ord(c8)-ord('0'));
        done := done+9*(ord(c9)-ord('0'));
        done := done mod 11;
        if done = 10 then       done := ord('X')-ord('0');
end;

begin
        readln(c1,c,c2,c3,c4,c,c5,c6,c7,c8,c9,c,c10);
        cr := chr(done+ord('0'));
        if cr <> c10 then
                writeln(c1,c,c2,c3,c4,c,c5,c6,c7,c8,c9,c,cr)
        else
                writeln('Right');
end.