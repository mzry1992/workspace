uses    sysutils;
var
        flog:text;
        time1,time2:double;
procedure       setinput;
begin
        assign(input,'humps.in');
        assign(output,'humps.out');
        assign(flog,'humps.log');
        append(flog);
        reset(input);
        rewrite(output);
        time1 := now;
end;
procedure       setoutput;
begin
        time2 := now;
        writeln(flog,(time2-time1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
begin
end.