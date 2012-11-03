uses    sysutils;
var
        k,n,i,j,bit:longint;
        ans:qword;
        flog:text;
        t1,t2:double;
procedure       setinput;
begin
        assign(input,'sequence.in');
        assign(output,'sequence.out');
        assign(flog,'sequence.log');
        append(flog);
        reset(input);
        rewrite(output);
        t1 := now;
end;
procedure       setoutput;
begin
        t2 := now;
        writeln(flog,(t2-t1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
begin
        setinput;
        readln(k,n);
        ans := 0;
        bit := 1;
        i := 32;
        while n shr (i-1) and 1 = 0 do  dec(i);
        for j := 1 to i do
        begin
                if n shr (j-1) and 1 = 1 then   ans := ans+bit;
                bit := bit*k;
        end;
        writeln(ans);
        setoutput;
end.
