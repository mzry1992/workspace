var
        timenow,opentime:string;
        x,y,c,n,m,i,j,mintime,hour,min,tmin,thour,tsecond:longint;
        g:array[1..1000,1..1000] of longint;
        f:array[1..1000] of longint;

begin
        readln(timenow);
        fillchar(g,sizeof(g),0);
        readln(n,m);
        for i := 1 to m do
        begin
                readln(x,y,c);
                if ( x <> 0 ) and ( y <> 0 ) then
                begin
                        g[x,y] := c;
                        g[y,x] := c;
                end;
        end;
        readln(opentime);
        for i := 1 to n do
                f[i] := maxint;
        f[1] := 0;
        for i := 2 to n do
        for j := 1 to n do
        if g[j,i] <> 0 then
        if f[i] > f[j] + g[j,i] then
                f[i] := f[j] + g[j,i];
        mintime := f[n];
        val(copy(timenow,1,pos(':',timenow)-1),hour);
        val(copy(timenow,pos(':',timenow)+1,length(timenow)-pos(':',timenow)),min);
        tmin := -1;     thour := -1;    tsecond := -1;
        if pos('min',opentime) <> 0 then
                val(copy(opentime,1,pos('min',opentime)-1),tmin)
        else
        if pos('second',opentime) <> 0 then
                val(copy(opentime,1,pos('second',opentime)-1),tsecond)
        else
        if pos('hour',opentime) <> 0 then
                val(copy(opentime,1,pos('hour',opentime)-1),thour);
        min := min + mintime;
        if tmin <> -1 then
        begin
                hour := hour + ( tmin + min ) div 60;
                min := ( tmin + min ) mod 60;
                if hour < 24 then
                begin
                        if min > 9 then
                                writeln(hour,':',min)
                        else
                        if min > 0 then
                                writeln(hour,':0',min)
                        else
                        if min = 0 then
                                writeln(hour,':00');
                        halt;
                end
                else
                begin
                        writeln('Sad');
                        halt;
                end;
        end;
        if tsecond <> -1 then
        begin
                tmin := tsecond div 60;
                hour := hour + ( tmin + min ) div 60;
                min := ( tmin + min ) mod 60;
                if hour < 24 then
                begin
                        if min > 9 then
                                writeln(hour,':',min)
                        else
                        if min > 0 then
                                writeln(hour,':0',min)
                        else
                        if min = 0 then
                                writeln(hour,':00');
                        halt;
                end
                else
                begin
                        writeln('Sad');
                        halt;
                end;
        end;
        if thour <> -1 then
        begin
                tmin := thour * 60;
                hour := hour + ( tmin + min ) div 60;
                min := ( tmin + min ) mod 60;
                if hour < 24 then
                begin
                        if min > 9 then
                                writeln(hour,':',min)
                        else
                        if min > 0 then
                                writeln(hour,':0',min)
                        else
                        if min = 0 then
                                writeln(hour,':00');
                        halt;
                end
                else
                begin
                        writeln('Sad');
                        halt;
                end;
        end;
end.