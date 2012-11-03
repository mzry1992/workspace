var
        n,tw,i,j,total:longint;
        w:array[1..100] of longint;
        g:array[0..100000] of boolean;
        use:array[1..100] of boolean;

procedure find(tw:longint);
var
        i:longint;
begin
        if tw = 0 then begin inc(total); exit; end;
        for i := 1 to n do
        if not use[i] then
        if g[tw-w[i]] then
        begin
                use[i]:=true;
                find(tw-w[i]);
        end;
end;

begin
        readln(tw);
        readln(n);
        for i := 1 to n do readln(w[i]);
        fillchar(g,sizeof(g),false);
        g[0]:=true;
        for i := 1 to n do
        for j := tw downto w[i] do
                g[j] := g[j-w[i]] or g[j];
        if not g[tw] then
        begin
                writeln('0');
                halt;
        end;
        fillchar(use,sizeof(use),false);
        total:=0;
        find(tw);
        if total = 1 then
        begin
                for i := 1 to n do
                if not use[i] then write(i,' ');
                writeln;
        end
        else
                writeln('-1');
end.
