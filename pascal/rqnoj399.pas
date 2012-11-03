var
        a:array['a'..'z'] of integer;
        max,min,j:longint;
        st:string;
        i:char;
function shu(n:integer):boolean;
var
        i:longint;
begin
        if n = 0 then exit(false);
        if n = 1 then exit(false);
        if n = 2 then exit(true);
        for i := 2 to n-1 do
                if n mod i = 0 then exit(false);
        exit(true);
end;
begin
        fillchar(a,sizeof(a),0);
        readln(st);
        for j := 1 to length(st) do
                inc(a[st[j]]);
        max := 0;
        min := 10000;
        for i := 'a' to 'z' do
        if a[i] > 0 then
        begin
                if a[i] > max then
                        max := a[i];
                if a[i] < min then
                        min := a[i];
        end;
        if shu(max-min) then
        begin
                writeln('Lucky Word');
                writeln(max-min);
        end
        else
        begin
                writeln('No Answer');
                writeln('0');
        end;
end.