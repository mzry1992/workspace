uses    sysutils;
var
        l,m,i,j,temp,tot,tnow:longint;
        left,right:array[1..100] of longint;
        flog:text;
        t1,t2:double;
procedure       setinput;
begin
        assign(input,'tree.in');
        assign(output,'tree.out');
        assign(flog,'tree.log');
        append(flog);
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(flog);
        close(input);
        close(output);
end;
begin
        setinput;
        t1 := now;
        readln(l,m);
        for i := 1 to m do      readln(left[i],right[i]);
        for i := 1 to m-1 do
        for j := i+1 to m do
        if left[i] > left[j] then
        begin
                temp := left[i];        left[i] := left[j];     left[j] := temp;
                temp := right[i];       right[i] := right[j];   right[j] := temp;
        end;
        tot := 0;
        i := left[1];
        j := right[1];
        for tnow := 2 to m do
        begin
                if ( left[tnow] >= i ) and (left[tnow] <= j ) then
                begin
                        if right[tnow] > j then  j := right[tnow];
                end
                else
                begin
                        tot := tot + j-i+1;
                        i := left[tnow];
                        j := right[tnow];
                end;
        end;
        tot := tot + j-i+1;
        writeln(l+1-tot);
        t2 := now;
        writeln(flog,(t2-t1)*24*3600:0:10);
        setoutput;
end.
