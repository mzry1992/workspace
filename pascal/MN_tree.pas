var
        l,m,i,j,temp:longint;
        left,right:array[1..100] of longint;
        line:array[0..200] of longint;
begin
        readln(l,m);
        line[0] := 0;
        for i := 1 to m do
        begin
                readln(left[i],right[i]);
                inc(line[0]);
                line[line[0]] := left[i];
                inc(line[0]);
                line[line[0]] := right[i];
        end;
        for i := 1 to line[0]-1 do
        for j := i+1 to line[0] do
        if line[i] = line[j] then
                line[j] := maxlongint;
        for i := 1 to line[0]-1 do
        for j := i+1 to line[0] do
        if line[i] > line[j] then
        begin
                temp := line[i];        line[i] := line[j];     line[j] := temp;
        end;
        while line[line[0]] = maxlongint do     dec(line[0]);
        for i := 1 to line[0] do        writeln(line[i]);
end.
