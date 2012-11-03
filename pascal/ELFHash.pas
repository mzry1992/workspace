var
        st:string;
        num,i,l,g:longint;
begin
        readln(st);
        l := length(st);
        num := 0;
        for i := 1 to l do
        begin
                num := (num shl 4)+ord(st[i]);
                g := num and ($f0000000);
                if g > 0 then num := num xor (g shr 24);
                num := num and (not g);
        end;
        num := num mod 99971 ;
        writeln(num);
end.