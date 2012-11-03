var
        test,ftest,n,i,j:longint;
        road:array[1..1001] of longint;
        f1,f0:array[0..1001] of boolean;
procedure       solve;
var
        i,j:longint;
        flg:boolean;
begin
        fillchar(f0,sizeof(f0),false);  f0[0] := true;
        for i := 1 to maxlongint do
        begin
                fillchar(f1,sizeof(f1),false);
                f1[0] := true;
                flg := true;
                for j := 1 to n+1 do
                begin
                        if f0[j-1] and (i mod road[j] <> 0) then     f1[j] := true;
                        if f0[j] and (i mod road[j] <> 0) then       f1[j] := true;
                        if f0[j+1] and (i mod road[j] <> 0) then     f1[j] := true;
                        if f1[j] then flg := false;
                end;
                write(i,' : ');
                for j := 1 to n+1 do
                        write(ord(f1[j]),' ');
                writeln;
                if f1[n+1] then
                begin
                        writeln(i);
                        exit;
                end;
                if flg then
                begin
                        writeln('You can',chr(39),'t cross the road!');
                        exit;
                end;
                f0 := f1;
        end;
end;
begin
        readln(test);
        for ftest := 1 to test do
        begin
                readln(n);
                for i := 1 to n do      read(road[i]);
                readln;
                road[n+1] := maxlongint;
                solve;
        end;
end.