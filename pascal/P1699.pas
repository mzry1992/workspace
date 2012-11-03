var
        n,i,a,b:longint;
        e,tmin,amin:double;
function        solve(a,b:longint):double;
var
        temp:double;
begin
        if b >= a then  exit(10e100);
        exit((2+a+2*b)*(a+b+1)/(2+3*a+a*a));
end;
begin
        amin := 10e100;
        readln(n);
        for i := 1 to n do
        begin
                readln(a,b);
                tmin := solve(a,b);
                writeln(tmin:0:10);
                if tmin < amin then
                        amin := tmin;
        end;
        readln(e);
        if amin > e then       writeln('Return.')
        else    writeln('Continue.');
end.
