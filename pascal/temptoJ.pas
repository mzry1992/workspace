var
        i,j,k:longint;
begin
        assign(input,'peanuts.in');
        assign(output,'peanuts.out');
        reset(input);
        rewrite(output);
        k := 10;
        for i := 1 to 100000 do
        for j := 1 to 100000 do
        begin
                k := k mod 100;
                k := k+i;
                k := k mod j;
        end;
        close(input);
        close(output);
end.
