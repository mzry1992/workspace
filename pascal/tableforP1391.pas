var
        i,x,y,rp:longint;
begin
        assign(output,'in.txt');
        rewrite(output);
        randomize;
        for i := 1 to 100 do
        begin
                x := random(100)+1;
                y := random(100)+1;
                rp := random(10000);
                writeln(x,' ',y,' ',rp);
        end;
        writeln('0 0 0');
        close(output);
end.
